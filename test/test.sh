#!/bin/bash

set -e

RED="\033[0;31m"
GREEN="\033[0;32m"
NO_COLOR="\033[0m"

MIN=10000000000
MAX=0
ERR=0
TOTAL=0
I=1

if [ "$1" == "-a" ] || [ "$1" == "-t" ] || [ "$1" == "-ta" ] || [ "$1" == "-at" ]
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
		echo -e "$TESTN test generated ${GREEN}SUCCESSFULLY${NO_COLOR}"
}

execute_tests()
{
	if [ ! -f "test/tests" ]; then
    	echo -e "${RED}Error${NO_COLOR}: tests file not found"
		echo -e "${GREEN}\"bash test/test.sh -t \$TEST_NBR \$INTERVAL\"${NO_COLOR} to create tests file"
	else
		while IFS= read -r ARG
			do
				LNS=`./push_swap $ARG | wc -l`
				LNS=`echo $LNS | xargs`
				if [ "$1" == "-a" ] || [ "$1" == "-ta" ] || [ "$1" == "-at" ]
					then
						echo -en "$ARG  $LNS"
				else
						echo -en "$I / $TESTN  $LNS"
				fi
				((I++))
				if (( $(echo "$LNS > $MAX" | bc -l) )); then
					MAX=$LNS
				fi
				if (( $(echo "$LNS < $MIN" | bc -l) )); then
					MIN=$LNS
				fi
				TOTAL=$((TOTAL + LNS))
				TMP=`./push_swap $ARG | ./checker $ARG`
				if [ "$TMP" != "OK" ];
					then
					((ERR++))
					echo -e "  [ ${RED}KO${NO_COLOR} ]"
				else
					echo -e "  [ ${GREEN}OK${NO_COLOR} ]"
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
	echo "usage: bash test/test.sh -aht"
	echo -e "Those options are available:\n"
	echo -e "\t-t\t\$TEST_NBR \$INTERVAL\tGenerate \$TEST_NBR tests in interval \$INTERVAL"
	echo -e "Ex.\tbash test/test.sh -t 1000 1..100\n"
	echo -e "\t-a\t\$TEST_NBR \$INTERVAL\tExecute \$TEST_NBR tests in interval \$INTERVAL"
	echo -e "Ex.\tbash test/test.sh -a 1000 1..100\n"
}

case $1 in
-h)
	help
	;;
-t)
	generate_tests
	;;
-at | -ta)
	generate_tests
	execute_tests $1
	;;
-a | *)
	execute_tests $1
	;;
esac