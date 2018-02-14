#!/bin/bash
#SCRIPT : strlen12.sh
#PURPOSE : length of string using arrays

function length
{
echo enter the strings
read -a len #read an array ,user inputs strings here
x=${#len[@]} #lenght of the array
echo $x
for (( i=0; i<$x; i++ ))
  do
   echo "the length of ${len[$i]} is ${#len[$i]}"
  done
}

length

while [ 1 ]
  do 
    echo do you want to continue
    read option
      if [ $option == "yes" ]
        then 
         length
      else 
         exit
      fi
  done

