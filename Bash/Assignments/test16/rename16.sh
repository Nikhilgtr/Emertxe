#!/bin/bash
#SCRIPT : rename16.sh
#PURPOSE : rename files/directories with lower/uppercase format of previous name

cd /home/utkarsh/ECEP/linux_system/assignments/test16/test
ls
pwd
dest=/home/utkarsh/ECEP/linux_system/assignments/test16/test/*
echo $dest
for i in * #i=contents of the present working directory
do 
if [ -f $i ]
then 
mv "$i" "`echo $i | tr 'A-Z' 'a-z' `"
else
mv "$i" "`echo $i | tr 'a-z' 'A-Z' `"
fi 
done
