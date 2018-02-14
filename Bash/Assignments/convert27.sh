#!/bin/bash
#SCRIPT : convert27.sh 
#PURPOSE : convert string to upper or lower case

function convert
{
echo "enter the string"
read input

echo "enter the conversion format"
read conv

if [ $conv = "upper" ]
  then
    output=` echo $input | tr 'a-z' 'A-Z' `
    echo $output
elif [ $conv = "lower" ]
  then
     output=` echo $input | tr 'A-Z' 'a-z' `
    echo $output
else 
    echo "invalid input"
fi
}

convert

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
        convert
      else
        exit
    fi
 done


