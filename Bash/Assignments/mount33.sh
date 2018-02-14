#!/bin/bash
#SCRIPT : mount33.sh
#PURPOSE : to check whether file system/mount point is mounted along with
#          amount of free space and error message

function mount
{
flag=0
df | tr -s " " > info.txt #to shrink spaces
sed 1d info.txt > temp.txt #to delete the first line(contains names in df)
cp temp.txt info.txt
cut -d " " -f1,4,5 info.txt > details.txt
declare -a filesys=(`cut -d " " -f1 details.txt`) #filesystem
declare -a empty=(`cut -d " " -f2 details.txt`) #free space
declare -a percent=(`cut -d " " -f3 details.txt`) #percentage of space used
len=${#empty[@]} #number of file systems mounted
for (( i=0; i<$len; i++ ))
  do
   if [ ${filesys[i]} == $1  ]
       then
       a=${empty[i]}
       b=${percent[i]}
       flag=`expr $flag + 1` 
       break
   fi
  done

if [ $flag -eq 0 ]
 then 
  echo "Filesystem $1 not mounted"  
else 
 echo "Filesystem $1 is $b used with $a kB free"
fi
rm *.txt
}

mount

while [ 1 ]
 do
   echo do you want to continue
   read option
    if [ $option == "yes" ]
      then
        echo enter filesystem
        read filesystem
        mount $filesystem
      else
       exit
    fi
 done

