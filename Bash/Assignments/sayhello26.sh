#!/bin/bash
#SCRIPT : sayhello26.sh
#PURPOSE: print messages depending on time of the day on login


date
HOUR=`date +%H` #get hour in 24 hour format


if [ $HOUR -ge 9 -a $HOUR -lt 13 ]
  then 
    echo "Good Morning Utkarsh"
elif [ $HOUR -ge 13 -a $HOUR -lt 17 ]
  then 
    echo "Good Afternoon Utkarsh"
elif [ $HOUR -ge 17 -a $HOUR -lt 21 ]
  then 
    echo "Good Evening Utkarsh"
elif [ $HOUR -lt 9 -a $HOUR -ge 21 ]
   then 
    echo "Good Night Utkarsh"
fi


