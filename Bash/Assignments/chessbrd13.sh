#!/bin/bash
# SCRIPT : chessbrd13.sh
# PURPOSE: print chess board

for (( i=1; i<=8; i++ )) 
   do 
     for (( j=1; j<=8; j++ )) 
        do
        a=`expr $i + $j`
        b=`expr $a % 2`
         if [ $b -eq 0 ]
            then
            echo -e -n " \033[47m " #white
            else
            echo -e -n " \033[40m " #black
         fi
        done 
       echo -e -n  " \033[0m "
       echo ""
   done
