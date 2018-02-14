#!/bin/bash
#SCRIPT : freespace36.sh
#PURPOSE : display names of filesystems with less that 10% free space available

df | tr -s " " > info.txt 

cut -d " " -f1,5 info.txt > temp.txt
cp temp.txt info.txt
sed 1d info.txt > line.txt #delete first line to remove attributes 

cp line.txt info.txt

declare -a filesys=(`cut -d " " -f1 info.txt`) #filesystem

cut -d " " -f2 info.txt > %.txt 

declare -a percent=(`cut -d "%" -f1 %.txt`) #percentage

len=${#percent[@]} #number of file systems

for (( i=0; i<len; i++ ))
 do
   if [ ${percent[i]} -gt 50 ]
     then 
       echo "${filesys[i]} has less than 50% free space"
   fi
 done

rm *.txt
 
