#!/bin/bash
#SCRIPT : perm33.sh
#PURPOSE : lock down permission for particular directory

function lockdown
{
echo enter directory name
read directory
mkdir $directory
ls -l
chmod g-rwx $directory #remove all permissions for all users in the group
chmod o-rwx $directory #remove all permissions for all others users
ls -l
}

lockdown

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
        lockdown
      else
       exit
    fi
 done


