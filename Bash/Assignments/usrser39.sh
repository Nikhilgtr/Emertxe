#!/bin/bash
#SCRIPT : usrser39.sh
#PURPOSE : search for user in system
function user
{
flag=0
echo "enter the username"
read name

declare -a names=(`cut -d ":" -f1 /etc/passwd`) #usernames stored in array names
#echo ${names[@]}

for n in ${names[@]}
  do 
    if [ "$n" == "$name" ]
    then
      flag=`expr $flag + 1`
    break
    fi
  done
if [ $flag -ne 0 ]
then 
echo "$name is present"
else 
echo "$name is not present"
fi
}

user

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
        user
      else
       exit
    fi
 done

