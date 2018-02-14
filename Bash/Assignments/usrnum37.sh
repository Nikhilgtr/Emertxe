#!/bin/bash
#SCRIPT : usrnum37.sh
#PURPOSE : count number of users with user ID's between predefined 
#          or userdefined range 

function number
{
declare -a usrid=(`cut -d ":" -f3 /etc/passwd`) #arr usrid contains all userids
num=0
l=$# #number of arguments
if [ $l -ne 0 ] # arguments given(desired range specified)
 then
  a=$1 #start
  b=$2 #end
   for id in ${usrid[@]}
    do
      if [ $id -le $b -a $id -ge $a ]
        then 
          num=`expr $num + 1`
          echo -n "$id "
      fi
    done

  #default range
else 
a=500 #start
b=10000 #stop
   for id in ${usrid[@]}
    do
      if [ $id -le $b -a $id -ge $a ]
        then 
          num=`expr $num + 1`
          echo -n "$id "
      fi
   done

fi

echo ""
echo "The number of users with user ids between the $a and $b are $num"
}

number

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
       echo enter two numbers for range
       read -a range      
       number ${range[@]}
    else
       exit
    fi
 done

