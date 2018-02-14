#!/bin/bash
#SCRIPT : pronum31.sh
#PURPOSE : script that outputs process number and waits 
#          allowing too view the contents of the linux/proc in another shell
echo The process number is
PID=$$ #process id
echo $PID
echo
echo The contents of $PID are
ls /proc/$PID
sleep 10 #wait for 10sec and then proceed

