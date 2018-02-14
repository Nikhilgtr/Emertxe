#!/bin/bash
#SRIPT : username21.sh
#PURPOSE : to print longest and shortest usernames in the system

declare -a names=(`cut -d ":" -f1 /etc/passwd`) #first field of passwd file 
                                                #contains usernames
echo ${names[@]}
len=${#names[@]} #number of usernames
echo $len

   #for largest username
for (( i=1; i<$len; i++ ))
   do
     a=${names[0]}
     b=${names[$i]}
     if [ ${#a} -lt  ${#b} ]
       then 
       names[0]=${names[$i]}
     fi
   done
echo "longest username is ${names[0]}"


   #for smallest username
for (( i=1; i<$len; i++ ))
do
a=${names[0]}
b=${names[$i]}
if [ ${#a} -gt  ${#b} ]
then 
names[0]=${names[$i]}
fi
done
echo "shortest username is ${names[0]}"

