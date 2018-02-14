#!/bin/bash
#SCRIPT : recursive32.sh
#PURPOSE : print all arguments passed to the function usign recursive funtion

function argument()
{
declare -a args=($@)
len=${#args[@]}

if [ $len -ge 1 ]   
    then
        echo $1
	argument ${args[@]:1} #deletes first elements of the array
fi    
}
argument 11 12 13 14 
