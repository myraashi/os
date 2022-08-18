#!/bin/bash
declare -A X
echo "Enter the value of n"
read n
echo "Enter a list of numbers"
for (( i=0;i<n;i++ ))
do
	read X[$i]
done
max=0
for v in ${X[@]}; do
	if (( $v > $max ));
		then max=$v
	fi
done
echo "The largest number is $max"


