#!/bin/bash 
#SCRIPT : swp22.sh
#PURPOSE : delete all .swp files in system 
swp=0
cd ~ #switch to home directory
echo $PWD
declare swp=`sudo find . -name ".*swp"` #search for swp files and move names 
                                        #into an array
echo ${#swp[@]} #number of swp files
echo ${swp[@]}

if [ ${#swp[@]} -eq 1 ]
   then
    echo "no swp files found"
else
    for file in ${swp[@]}
     do
      rm $file
     done
fi
cd - # back to previous directory


