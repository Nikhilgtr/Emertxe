#!/bin/bash
#SCRIPT : empty9.sh
#PURPOSE : to delete empty lines from a file

echo "enter filename"
read file
sed '/^[[:blank:]]*$/d' $file > withoutempty.txt
cat withoutempty.txt	

