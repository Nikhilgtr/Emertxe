#!/bin/bash
#SCRIPT : rename18.sh
#PURPOSE : to rename files in an album to a user defined name

echo "enter the desired name"
read name
i=1
cd test
for j in *
   do
    if [ $i -le 9 ]
    then
 mv $j "$name"_00"$i".jpg #print 001 to 009
else
mv $j "$name"_0"$i".jpg #print 010 and above
fi
i=`expr $i + 1`
done
cd ..

