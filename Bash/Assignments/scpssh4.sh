#!/bin/bash
#SCRIPT : scpssh4.sh
#PURPOSE : to implement scp and ssh

echo 1-ssh
echo 2-scp
echo select an option to continue
read option
if [ $option -eq 1 ] 
     then
       echo please enter remote system ip address
       read ip
       echo please enter username
       read user
       ssh $user@$ip    

elif [ $option -eq 2 ]
     then
     echo please enter remote system ip address
     read ip
     echo please enter username
     read user
     echo 1- local to remote
     echo 2-remote to local
     echo please choose an option to continue 
     read direction
       if [ $direction -eq 1 ]
            then
              echo please enter source file location
              read sourcefile
              echo please enter destination file location
              read destfile
              scp -r $sourcefile $user@$ip:$destfile
       elif [ $direction -eq 2 ] 
            then
              echo please enter source file location
              read sourcefile
              echo please enter destination file location
              read destfile
              scp $user@$ip:$sourcefile $destfile
       else 
       echo invalid input
       fi
else 
echo enter the right option
fi
