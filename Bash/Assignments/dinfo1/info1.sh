#!/bin/bash
#SCRIPT : dinfo1.sh
#PURPOSE : to print file related information of present work directory

information=`ls -l -h` # -l long list -h human readable #command 
echo -n $information
ls -l > info.txt
less info.txt

