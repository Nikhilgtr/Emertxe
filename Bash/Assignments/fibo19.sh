#!/bin/bash
#SCRIPT : fibo19.sh
#PURPOSE : largest number in the fibonacci series <= number

function fibo
{
echo "enter the number"
read n
A=0
B=1
C=0

while [ $B -lt $n ]
do
  C=`expr $A + $B`
  A=$B
  B=$C
done
echo "The largest no of the fibonnaci series is  $A" 
}

fibo

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
        fibo
      else
       exit
    fi
 done

