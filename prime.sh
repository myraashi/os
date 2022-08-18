#!/bin/bash
echo "enter the uppper limit"
read n
flag=0
echo "the prime number in the given range are"
for (( i=2; i<n ;i++ ))
do
	for (( j = 2;j<=$((i/2));j++))
	do 
	if [ $((i%j)) == 0 ]
	then
		flag=1
	break
	fi
	done
	if [ $((flag))==0 ]
	then
	echo -ne "$i"
	fi
	flag=0
done 
