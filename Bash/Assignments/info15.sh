#!/bin/bash 
#SCIRPT : info15.sh
#PURPOSE : to print following info
           #currently logged user
           #your shell directory
           #home directory
           #os name & version
           #current working directory
           #number of users logged in
           #show all available shells in your system
           #hard disk information
           #cpu information
           #memory information 
           #file system information
           #currently running process

echo 1- currently logged user
whoami
echo 
echo 2- shell directory
echo $SHELL
echo
echo 3- home directory
echo $HOME 
echo
echo 4- os name and verison
cat /etc/*-release | head -6 | tail -2
echo
echo 5- current working directory
echo $PWD
echo
echo 6-number of users logged in
echo who | wc -l
echo
echo 7-show all shells available in system
cat /etc/shells
echo 
echo 8- hard disk information
sudo lshw -c disk | head -12
echo
echo 9- cpu information
lscpu
echo
echo 10- memory information
cat /proc/meminfo
echo
echo 11-file system information
df
echo
echo 12-currently running process
ps
echo
