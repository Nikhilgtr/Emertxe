#!/bin/bash
#SCRIPT : sort14.sh
#PURPOSE : arrange number in ascending or descending order

echo "enter the number to be rearranged"
read -a num
echo "ascending or descending?"
read mod

l=${#num[@]}
m=$l
a=`expr $m - 1`

if [ $mod = "ascending" ]
then
   for (( i=0; i<=$a; i++ ))
    do
     for (( j=`expr $i + 1`; j<=$a; j++ ))
      do  
        if [ ${num[$i]} -gt ${num[$j]} ] 
         then
           temp=${num[$j]}
           num[$j]=${num[$i]}
           num[$i]=$temp
        fi
      done
    done

elif [ $mod = "descending" ]
then

   for (( i=0; i<=$a; i++ ))
    do
     for (( j=`expr $i + 1`; j<=$a; j++ ))
      do
        if [ ${num[$i]} -lt ${num[$j]} ] 
         then
           temp=${num[$i]}
           num[$i]=${num[$j]}
           num[$j]=$temp
        fi
      done
    done

 
else 
echo "wrong input" 
fi 
if [ $mod == "ascending" -o "descending" ]
then
echo "${num[@]}"
fi           
