#!/bin/bash

set -e

RES=0;
ERR=0;

while IFS= read -r ARG
	do
		echo -n $ARG
		TMP=`./push_swap $ARG | ./checker $ARG`
  		if [ "$TMP" != "OK" ];
		  	then
			((ERR++))
			echo -e "  [ \033[0;31m\033[1mKO\033[0m ]"
		else
			echo -e "  [ \033[0;32m\033[1mOK\033[0m ]"
		fi
		LNS=`./push_swap $ARG | wc -l`
  		LNS=`echo $LNS | xargs`
		if (( $(echo "$LNS > $RES" | bc -l) )); then
			RES=$LNS
		fi
done < "test/tests"

if [ $ERR -eq 0 ];
	then
	echo -e "\033[0;32mSuccess max ops: $RES"
else
	echo -e "\033[0;31mFail $ERR / 148"
fi
