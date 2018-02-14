#!/bin/bash
#SCRIPT : revnum8.sh
#PURPOSE : to reverse a number

function reverse
{
echo "enter the number to be reversed"
read n
or=$n #original value
a=0 #power
b=0 #reversed value

while [ $n -gt 0 ] # to get length
 do
  a=`expr $a + 1` 
  n=$(($n/10))
 done 
 
a=$(($a-1)) #largest position in the number
n=$or

while [ $a -ge 0 -a $n -ge 0 ]
 do
b=$(($b+$(($n%10))*$((10**$a))))
n=$(($n/10))
a=$(($a-1))
 done

echo "The reversed number is $b"
}

reverse

while [ 1 ]
 do 
  echo do you want to continue
  read option
   if [ $option == "yes" ]
    then
      reverse
   else 
      exit
   fi
 done
