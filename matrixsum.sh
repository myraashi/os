#!/bin/bash
declare -A X
declare -A Y
declare -A Z

echo "Enter the order of matrix"
read n
echo "Enter matrix A"
for ((i=0;i<n;i++))
do
	for((j=0;j<n;j++))
	do
		read X[$i,$j]
	done
done
echo "Enter matrix B"
for ((i=0;i<n;i++))
do
	for ((j=0;j<n;j++))
	do
		read Y[$i,$j]
	done
done
echo
echo "Matrix A"
echo
for ((i=0;i<n;i++))
do
	for ((j=0;j<n;j++))
	do
		echo -ne "${X[$i,$j]}"
	done
done
echo
echo "Matrix B"
echo
for ((i=0;i<n;i++))
do
	for ((j=0;j<n;j++))
	do
		echo -ne "${Y[$i,$j]}"
	done
done
echo
echo "Sum:"
for ((i=0;i<n;i++))
do
for ((j=0;j<n;j++))
do
	Z[$i,$j]=$(( ${X[$i,$j]}+${Y[$i,$j]} ))
		echo -ne "${Z[$i,$j]}"
done
echo
done

