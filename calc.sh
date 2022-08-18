#!/bin/bash
echo "Choose operation"
echo "1)addition"
echo "2)Subtraction"
echo "3)MUltiplication"
echo "4)Division"
echo "5)modulo"
read choice
echo "enter two numbers"
read a 
read b
case $choice in
1) echo "The sum is $(($a+$b))" ;;
2) echo $(($a-$b)) ;; 
3) echo $(($a*$b)) ;;
4) echo $(($a/$b)) ;;
5) echo $(($a%$b)) ;;
esac
