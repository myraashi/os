#!/bin/bash

echo "Choose operation"
echo "1)Addition"
echo "2)Subtraction"
echo "3)Multiplication"
echo "4)Division"
echo "5)Modulo"
read choice
echo "Enter two number"
read a
read b
case $choice in
1) echo $(($a+$b)) ;;
2) echo $(($a-$b)) ;;
3) echo $(($a*$b)) ;;
4) echo $(($a/$b)) ;;
5) echo $(($a%$b)) ;;
esac
