#!/bin/bash
#SCRIPT : replace40.sh
#PURPOSE : replace 20% lines in a c file and replace
#          with pattern <-DEL->

num=`wc -l < replaced.c` #number of lines in the file
echo $num
echo 
n=`expr $num / 5 ` # to get 20% of total lines 
for (( i=1; i<=$n; i++ ))
 do
ran=`shuf -i 1-20 -n1` #generate any random number between 1 and 20 and give                           #  one number
echo $ran
sed -i "${ran}s/.*/<-DEL->/" replaced.c #replace line number $ran with given                                            #string
done

cat real.c
cat replaced.c
