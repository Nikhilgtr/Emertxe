#!/bin/bash
#SCRIPT : largest7.sh
#PURPOSE : print largest number from the given arguments

i=$# #number of arguments
temp=$1 #temporary variable temp given first argument
for (( n=2; n<=$i; n++ )) #loop for iterating through arguments
 do
  if [ $temp -lt ${!n} ] 
   then
    temp=${!n}
   fi
 done
echo "the greatest no is $temp"
 
 
