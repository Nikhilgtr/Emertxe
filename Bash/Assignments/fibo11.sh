#!/bin/bash
#SCRIPT : fibo11.sh
#PURPOSE :
<<'generate'
fibonacci series
0 1 1 2 3 5 8 13 ...
generate
 
echo "enter the length of the series"
read F
echo "fibonacci series:"
A=0
B=1
C=0 
while [ $A -le $F  ] 
do
echo -n "$A "
C=$(($A+$B)) #sum of previous 2 elements
A=$B
B=$C
done
echo " "
