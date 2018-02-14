#!/bin/bash
#SCRIPT : real5.sh
#PURPOSE addition of integer and real nos.

function add
{
C=0 #total
echo "enter the numbers to be added"
read A B
C=`echo $A + $B | bc` # |-pipping bc-bench calculator(for real nos)
echo "the addition of $A and $B is $C"
}
 
add

while [ 1 ]
 do 
  echo do you want to continue 
  read option
   if [ $option == "yes" ]
    then 
     add
   else 
   exit 
   fi
 done
