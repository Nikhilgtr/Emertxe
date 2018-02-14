#!/bin/bash
#SCRIPT : rename17.sh
#PURPOSE : rename present working directory by given name


a=`pwd` #present work directory
echo "PWD is $a"
echo "please enter the name"
read d
c=`basename $a` #gives present work directory name from absolute path
echo $c
cd ..
mv $c $d

