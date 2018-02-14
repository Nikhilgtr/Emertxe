#!/bin/bash
#SCRIPT : pat3.sh
#PURPOSE :
<<'generate'
1
23
456
78910
generate
function pattern
{
k=1
echo "enter the range"
read x
for (( i=1; i<=$x; i++ )) # i=row
 do
  for(( j=1; j<=i; j++ )) #j=coloumn
   do 
    echo -n "$k "
    k=`expr $k + 1`
   done
  echo " "
 done
}

pattern

while [ 1 ]
 do
 echo "do you want to continue"
 read option
   if [ $option == "yes" ]
    then 
     pattern
   else
     exit
   fi
  done
