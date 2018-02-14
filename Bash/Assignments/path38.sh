#!/bin/bash
#SCRIPT : path38.sh
#PURPOSE : for each directory in $PATH,display executable
#          files in that directory

num=0
a=`echo $PATH | tr ":" " "`
paths=($a)
echo ${paths[@]} #paths
len=${#paths[@]} #number of paths
echo $len
for path in ${paths[@]}
 do
   if [ ! -d $path ] #checks if directory exists or not
    then
     echo "$path directory does not exist"
     continue # to check for next directory as previous directory does not exist
   else
    cd $path
   fi
   for file in $(ls $path)
   do
    if [ -x $file ] #check if file is executable or not
    then
    num=`expr $num + 1`
  fi
  done
 done
echo "Number of executables are $num"

