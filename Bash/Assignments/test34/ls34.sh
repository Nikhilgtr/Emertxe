#!/bin/bash
#SCRIPT : ls34.sh
#PURPOSE : show outpu same as ls command
#          directory given as command line argument

echo "enter the directory name"
read name

cd $name
for files in *
 do
   echo -n "$files  "
 done 
echo ""
cd ..
