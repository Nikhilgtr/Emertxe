#1/bin/bash
#SCRIPT : pat2.sh
#PURPOSE :
<<'generate'
1
12
123                      
1234                     
generate

function pattern
{ 
echo "enter the range"
read R
for (( i=1; i<=$R; i++ )) #i=row
  do
    for (( j=1; j<=$i; j++ )) #j=coloumn
     do
     echo -n  "$j "
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
