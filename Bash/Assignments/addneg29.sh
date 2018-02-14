#!/bin/bash
#SCIRPT : addneg29.sh
#PURPOSE : use address negation to print 5th line of
#          /etc/passwd file 

#head -5 /etc/passwd | tail -1


sed -n '5p' /etc/passwd #prints fifth line of /etc/passwd command
<<"prog"
cat /etc/passwd > del.txt  
a=`wc -l del.txt` #total number of lines in file
echo $a
sed -i '1,4d' del.txt #delete first 4 lines
b=`expr $a - 4`
sed -i '2,${b}d' del.txt #delete all but 1st line
cat del.txt 
rm del.txt
prog
