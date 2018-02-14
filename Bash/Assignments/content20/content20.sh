#!/bin/bash
#SCRIPT : content20.sh
#PURPOSE : print contents of given file from given line to next given line nos.

function content
{
filename=$3   #filename gievn as third argument
echo $filename
a=`expr $2 + $1 - 1`
b=$2
head -n $a $filename | tail -n $b #print first "a" lines and print last "b" 
                                      #lines of the previous output
}

content $@  #passsing command line arguments to the function

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
        echo enter the arguments
        read -a arguments
        content ${arguments[@]}
      else
       exit
    fi
 done


