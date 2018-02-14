#!/bin/bash
# SCRIPT : cal6.sh
# PURPOSE : arithmetic calculator using cli


x=$# #number of arguments
operator=$2 #operator taken as second argument
if [ $x -le 3 ] ;then

case $operator in
+)echo $1 + $3 | bc ;; #addition 
-)echo $1 - $3 | bc ;; #subtractiom
X)echo $1 \* $3 | bc ;; #multiplication 
/)echo $1 / $3 | bc ;;  #quotient
%)echo $1 % $3 | bc ;;  #remainder
*)echo invalid inputs
esac
else 
echo "too many inputs"
fi



