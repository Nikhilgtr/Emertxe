#!/bin/bash
# SCRIPT : digit_arithmetic.sh
# PURPOSE :
<<"print"
arithmetic operator depending on operator
eg:ip 12345+ op 15
print

function 
echo "enter the string to be operated on"
read s

a=${#s}                                             #lenght of input string
b=`expr $a - 1`                                     #index of the last element(operator in this case)
c=${s:$b:1}                                         #last element of the string
echo "the operator given by the user is $c"         #operator
temp=${s:0:1}                                       #first element of the string

for (( i=1; i<$b; i++ ))
  do
	x=${s:$i:1} 
	
	case $c in
		+)cal=`echo $temp + $x | bc` 
			temp=$cal
                         ;;
                -)cal=`echo $temp - $x | bc` 
			temp=$cal
     			 ;;
		x)cal=`echo $temp \* $x | bc` 
                        temp=$cal   
                        ;; 
		/)cal=`echo $temp / $x | bc` 
                        temp=$cal
     			;;
		%)cal=`echo $temp % $x | bc` 
                        temp=$cal
                        ;;
	        *)echo "invalid inputs"
                        ;;
	esac
  done
echo output is $cal
    
