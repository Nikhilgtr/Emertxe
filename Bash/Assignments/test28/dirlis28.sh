#!/bin/bash
#SCRIPT : dirlis28.sh
#PURPOSE : print directory name prior to contents

function name
{ 
echo "enter the directory"
read name

files=`ls $a` #files in the directory
for file in $files
 do
  echo "$name"_"$file" 
done
}

name

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
        name
      else
       exit
    fi
 done

