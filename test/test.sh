#!/bin/bash

set -e

RED="\033[0;31m"
GREEN="\033[0;32m"
BOLD="\033[1m"
RESET="\033[0m"

MIN=10000000000
MAX=0
ERR=0
TOTAL=0
I=1

if [ "$1" == "-ev" ] || [ "$1" == "-ve" ] || [ "$1" == "-av" ] || [ "$1" == "-va" ]
then
	v="valgrind -q --leak-check=full --show-leak-kinds=all"
fi

if [ "$1" == "-a" ] || [ "$1" == "-e" ] || [ "$1" == "-h" ] || [ "$1" == "-t" ] || [ "$1" == "-av" ] || [ "$1" == "-va" ] || [ "$1" == "-ev" ] || [ "$1" == "-ve" ]
	then
		TESTN=$2
		INTERVAL=$3
else
		TESTN=$1
		INTERVAL=$2
fi

generate_tests()
{
		rm -f test/tests
		for i in $( eval echo {1..$TESTN} )
			do
				printf "Generating tests... $i / $TESTN\r"
				echo `ruby -e "puts ($INTERVAL).to_a.shuffle.join(' ')"` >> test/tests
			done
		echo -e "$TESTN test generated ${GREEN}SUCCESSFULLY${RESET}"
}

execute_tests()
{
	if [ ! -f "test/tests" ]; then
    	echo -e "${RED}Error${RESET}: tests file not found"
		echo -e "${GREEN}\"bash test/test.sh -t \$TEST_NBR \$INTERVAL\"${RESET} to create tests file"
	else
		while IFS= read -r ARG
			do
				OPS=`$v ./push_swap $ARG`
				LNS=`echo "$OPS" | wc -l | xargs`
				echo -en "$I / $TESTN  $LNS"
				((I++))
				if (( $(echo "$LNS > $MAX" | bc -l) )); then
					MAX=$LNS
				fi
				if (( $(echo "$LNS < $MIN" | bc -l) )); then
					MIN=$LNS
				fi
				TOTAL=$((TOTAL + LNS))
				if [ -z "$OPS" ]; then
					TMP="OK"
				else
					TMP=`echo "$OPS" | $v ./checker $ARG`
				fi
				if [ "$TMP" != "OK" ];
					then
					((ERR++))
					echo -e "  [ ${RED}KO${RESET} ]"
				else
					echo -e "  [ ${GREEN}OK${RESET} ]"
				fi
		done < "test/tests"
		if [ $ERR -eq 0 ];
			then
			echo -e "\033[0;32mSUCCESS\033[0m"
			echo -e "min:\t\t$MIN"
			echo -e "max:\t\t$MAX"
			echo -en "mean:\t\t"
			echo "scale=2; $TOTAL / $TESTN" | bc
			echo -e "time:\t\t$SECONDS"
		else
			echo -e "\033[0;31mFAIL $ERR / $TESTN"
		fi
	fi
}

help()
{
	echo -e "${BOLD}Usage${RESET}: bash test/test.sh -aehtv"
	echo -e "Those options are available:\n"
	echo -e "\t${BOLD}-t${RESET}\t\$TEST_NBR \$INTERVAL\tGenerate \$TEST_NBR tests in interval \$INTERVAL"
	echo -e "\t\tEx.\tbash test/test.sh -t 1000 1..100\n"
	echo -e "\t${BOLD}-e${RESET}\t\$TEST_NBR \$INTERVAL\tExecute \$TEST_NBR tests in interval \$INTERVAL"
	echo -e "\t\tEx.\tbash test/test.sh -a 1000\n"
	echo -e "\t${BOLD}-a${RESET}\t${BOLD}-t${RESET} + ${BOLD}-e${RESET}"
}

case $1 in
-h)
	help
	;;
-t)
	generate_tests
	;;
-a | -va | -av)
	generate_tests
	execute_tests $1
	;;
-e | -ve | -ev | "")
	execute_tests $1
	;;
esac
