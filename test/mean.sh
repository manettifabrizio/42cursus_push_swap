#!/bin/bash

rm -fr test/tests
TESTS_NBR=$(($1))
TOTAL=0
TMP=0
MIN=1000000
MAX=0

for i in $( eval echo {1..$TESTS_NBR} )
	do 
		arg=`ruby -e "puts (1..4).to_a.shuffle.join(' ')"`
		echo -en "$arg\t\t"
		TMP=`./push_swap $arg | wc -l`
		if [ $TMP -gt $MAX ];
		then
			MAX=$TMP
		elif [ $TMP -lt $MIN ];
		then
			MIN=$TMP
		fi
		arg2=`./push_swap $arg | ./checker $arg`
		echo "$i / $TESTS_NBR: $TMP | $arg2"
		TOTAL=$((TOTAL + TMP))
	done
	

if [ $MIN -eq 1000000 ];
then
	MIN=0
fi

echo "min: $MIN"
echo "max: $MAX"

echo "scale=2; $TOTAL / $TESTS_NBR" | bc