#!/bin/bash
#SCRIPT : random24.sh
#PURPOSE : to generate random 8 character passwords

function password
{
String=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 8 | head -n 1)
echo The random 8 character password is $String
}

password

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
        password
      else
       exit
    fi
 done

