#!/bin/bash
#SCRIPT : swp23.sh
#PURPOSE : do delete all .swp files from given directory


cd $1 #directory given as argument
find . -name ".*swp" > swpfiles.txt
if [ ! -s swpfiles.txt ] #checks if file is empty or not
  then 
   echo "no .swp files found"
else 
  rm .*swp
fi
rm swpfiles.txt
cd ..
