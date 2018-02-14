#!/bin/bash
#SCRIPT : database.sh

<< purpose
PURPOSE : Create,search,edit and view database on following parameters
          name
          email -d         
          telephone number
		  mobile number
		  place
		  message
purpose


#--------------------------------------- functions for adding-----------------------------------------------

function name
{
	echo -e "\e[1mEnter name\e[0m"
	read string
	if [[ $string =~ ^[a-zA-Z][a-zA-Z\s]+ ]]
		then 
	        first=`echo $string | cut -c1 | tr [a-z] [A-Z]`
		    second=`echo $string | cut -c2- | tr [a-zA-Z] [a-z]`
			echo -n ""$first$second"," >> database.csv
			echo Name added to database | ts >> database.log
	else
		    echo -e "\e[1;31mInvalid input.Try again\e[0m"
			name	
    fi
}

function mail
{
	echo -e "\e[1mEnter E-mail ID\e[0m"
	read string
	if [[ $string =~ ^[a-zA-Z0-9][a-zA-Z0-9\._]*@[a-zA-Z0-9]+\.[a-z]+$ ]]
		then
			echo -n ""$string"," >> database.csv
			echo  Mail added to database | ts >> database.log
	else 
		    echo -e "\e[1;31mInavlid input.Try again\e[0m"
			echo Invalid mail format entered.Prompted to enter again | ts >> database.log	
			mail
    fi
}

function telephone
{
     echo -e "\e[1mEnter Telephone number\e[0m"
	 read string	 
	 if [[ $string =~ ^[0-9]+$ ]] && [[ ${#string} -eq 8 ]]
		 then
			 echo -n ""$string"," >> database.csv
             echo Telephone number added to database | ts >> database.log
	 else
			 echo -e "\e[1;31mInvalid input.Try again\e[0m"
			 echo Invalid Telephone number format entered.Prompted to enter again | ts >> database.log
			 telephone
     fi
}

function code 
{
	echo -e "\e[1mEnter Country code\e[0m"
	read string	
	if [[ $string =~ ^[0\+][0-9]+[0-9]$ ]]
		then
			 echo -n ""$string" " >> database.csv
			 echo Country code added to database | ts >> database.log
	else
			 echo -e "\e[1;31mInvalid input.Try again\e[0m"
			 echo Invalid Country code format entered.Propmted to enter again | ts >> database.log 
			 code
	fi
}

function mobile
{ 
	echo -e "\e[1mEnter Mobile number\e[0m"
	read string	
	if [[ $string =~ ^[0-9]*$ ]] && [[ ${#string} -eq 10 ]]
		then
			  echo -n ""$string"," >> database.csv
		      echo Mobile number added to database | ts >> database.log
     else	            
		      echo -e "\e[1;31mInvalid input.Try again\e[0m"
			  echo Invalid Mobile number format entered.Prompted to enter again | ts >> database.log
			  mobile
     fi
}

function place
{
	echo -e "\e[1mEnter place\e[0m"
	read string	
	if [[ $string =~ ^[a-zA-Z][a-zA-Z\s]+ ]]
	    then
		      first=`echo $string | cut -c1 | tr [a-z] [A-Z]`
	          second=`echo $string | cut -c2- | tr [a-zA-Z] [a-z]`
			  echo -n ""$first$second"," >> database.csv
			  echo Place added to database | ts >> database.log

	 else
			  echo -e "\e[1;31mInvalid input.Try again\e[om"  
	          echo Invalid Place format entered.Prompted to enter again | ts >> database.log
			  place
	fi
}
 
function message
{
	echo -e "\e[1mEnter Message\e[0m"
	read string	
	          echo $string >>  database.csv
              echo Message added to database | ts >> database.log
}
#--------------------------------------------add functions stop here ---------------------------------------

#--------------------------------------------- functions for parameter checking----------------------------------------

function names
{
	temp=$1
	if [[ $temp =~ ^[a-zA-Z][a-zA-Z\s]+ ]] 
		then 
			echo "$temp"
	else 
	         >&2 echo -e "\e[1;31mInvalid format.Enter string again\e[0m" 
			 >&2 echo "Enter name" 
			read q
			names $q
	fi		
}

function mails
{
	temp=$1
	if [[ $temp =~ ^[a-zA-Z0-9][a-zA-Z0-9\._]*@[a-zA-Z0-9]+\.[a-z]+$ ]]
		then
			echo "$temp"
	else   
		    >&2 echo -e "\e[1;31mInvalid format.Enter string again\e[0m"
			>&2 echo "Enter email-id"
			read q
			mails $q
    fi
}

function telephones
{
    temp=$1
	if [[ $temp =~ ^[0-9]+$ ]] && [[ ${#temp} -eq 8 ]]
        then
			echo "$temp"
	else   
		    >&2 echo -e "\e[1;31mInvalid format.Enter string again\e[0m"
			>&2 echo "Enter telephone number"
			read q
			telephones $q
    fi
}

function codes
{
	temp=$1	
	if [[ $temp =~ ^[0\+][0-9]+[0-9]$ ]]
		then
			 echo "$temp"
	else
			 >&2 echo -e "\e[1;31mInvalid format.Enter string again\e[0m"
			 >&2 echo "Enter country code"
			 read q
             codes $q
	fi
}

function mobiles
{
    temp=$1
	if [[ $temp =~ ^[0-9]*$ ]] && [[ ${#temp} -eq 10 ]]
        then
			echo "$temp"
	else   
		    >&2 echo -e "\e[1;31mInvalid format.Enter string again\e[0m"
			>&2 echo "Enter mobile number"
			read q
			mobiles $q
    fi
}

function places
{
    temp=$1
	if [[ $temp =~  ^[a-zA-Z][a-zA-Z\s]+ ]]
		then
			echo "$temp"
	else   
		    >&2 echo "\e[1;31mInvalid format.Enter string again\e[0m"
            >&2 echo "Enter place"
			read q
			places $q
    fi
}

#---------------------------------------functions for parameter checking stop here---------------------------------------



function view
{	
     a=$1
     shift 
	 array=("$@")		 
	 echo -e "\e[1;93m************************\e[0m" >> data1.txt
	 echo -e "\e[1;91mTOTAL MATCHES\e[0m : \e[1;32m$a\e[0m" >> data1.txt
	 echo -e "\e[1;93m************************\e[0m" >> data1.txt
	 echo >> data1.txt
	 echo >> data1.txt
	 for(( i=1; i<=$a; i++ ))
        do  
			 j=`expr $i - 1`
             sed -n ${i}p database1.csv > data.txt
			 name=`cut -d "," data.txt -f1`
			 mail=`cut -d "," data.txt -f2`
			 telephone=`cut -d "," data.txt -f3`
			 code=`cut -d "," data.txt -f4 | cut -d " " -f1`
			 mobile=`cut -d "," data.txt -f4 | cut -d " " -f2`
			 place=`cut -d "," data.txt -f5`
			 message=`cut -d "," data.txt -f6`

             echo -e "\e[34m..............................................................................\e[0m" >> data1.txt
			 echo -e "\e[1;95m SERIAL NUMBER\e[0m : \e[96m$i\e[0m       #  ( \e[1;31mORIGINAL\e[0m : \e[32m${array[j]}\e[0m ) " >> data1.txt
			 echo -e "\e[34m------------------------------------------------------------------------------\e[0m" >> data1.txt
			 echo >> data1.txt
			 echo "  NAME : $name" >> data1.txt
			 echo "  EMAIL-ID : $mail" >> data1.txt
			 echo "  TELEPHONE NUMBER : $telephone" >> data1.txt
			 echo "  COUNTRY CODE : $code" >> data1.txt
			 echo "  MOBILE NUMBER : $mobile " >> data1.txt
			 echo "  PLACE : $place" >> data1.txt
			 echo "  MESSAGE : $message" >> data1.txt
			 echo >> data1.txt
			 echo "-------------------------------------------------------------------------------" >> data1.txt
	
         done
             (  
		     echo -e "Use \e[1;31mup\e[0m and \e[1;31mdown\e[0m arrow keys to navigate and \e[1;31mq\e[0m to quit"
			 echo
             cat data1.txt
			 echo
             echo -e "Use \e[1;31mup\e[0m and \e[1;31mdown\e[0m arrow keys to navigate and \e[1;31mq\e[0m to quit"
             ) | less -R
			 rm data1.txt data.txt database1.csv



}


function search 
{  

   count=`cat database.csv | wc -l`
    if [ $count -eq 0 ]
		then
		echo -e "\e[1;31mDATABASE EMPTY !!\e[0m"
		sleep 2
	else 

    clear
    echo -e "\e[92m***************************************************************\e[0m"
	echo -e "\e[1;91m                            SEARCH                           \e[0m"
	echo -e "\e[93m***************************************************************\e[0m"
	echo
	echo -e "\e[1m        SELECT PARAMETER TO BE SEARCHED BY :\e[0m"
	echo	
	echo "         1-Name"
	echo "         2-Email-Id"
	echo "         3-Telephone number"
	echo "         4-Mobile number"
	echo "         5-Place"
	echo "         6-Message"
	read -s para   	

        if [ $para -eq 1 ]
		then
		echo User decided to search by name | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mname\e[0m"
		echo
        echo "Enter name"
    	read a
		str=$(names "$a")
		no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)  
		n=`grep -w -i "$str" database.csv | wc -l`
		if [ $n -eq 0 ]
          then
			  echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
			  echo
			  sleep 2
		  else	  
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
		fi

    elif [ $para -eq 2 ]
		then
		echo User decided to search by email-id | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31memail-id\e[0m"
		echo
        echo "Enter email-id"
    	read a
		str=$(mails "$a")
		no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
        n=`grep -w -i "$str" database.csv | wc -l`
		if [ $n -eq 0 ]
			then 
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m" 
				echo
				sleep 2
		  else		
        grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        fi

	elif [ $para -eq 3 ]
		then
		echo User decided to search by telephone number | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mtelephone number\e[0m"
		echo
        echo "Enter telephone number"
    	read a
		str=$(telephones "$a")
        n=`grep -w -i "$str" database.csv | wc -l`
        no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
		if [ $n -eq 0 ]
           then
			   echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
			   echo
			   sleep 2
		else	   
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        fi


	elif [ $para -eq 4 ]
		then
		echo User decided to search by mobile number | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mmobile number\e[0m"
		echo
        echo "Enter mobile number"
    	read a
		str=$(mobiles "$a")
		n=`grep -w -i "$str" database.csv | wc -l`
		no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
		if [ $n -eq 0 ]
			then 
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
				echo
				sleep 2
		else		
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        fi

    elif [ $para -eq 5 ]
		then
		echo User decided to search by place | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mplace\e[0m"
		echo
        echo "Enter place"
    	read a
		str=$(places "$a")
        n=`grep -w -i "$str" database.csv | wc -l`
        no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
		if [ $n -eq 0 ]
			then
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
				echo
				sleep 2
		else		
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
		fi

    elif [ $para -eq 6 ]
		then
		echo User decided to search by message | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mmessage\e[0m"
		echo
        echo "Enter message"
    	read a
		str=$a
		n=`grep -w -i "$str" database.csv | wc -l`
        no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
		if [ $n -eq 0 ]
		   then
			   echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
			   echo
			   sleep 2
		else	   
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        fi
	fi 
  fi
  echo
  echo -e "\e[1mDo you want to continue searching?\e[0m[y/n]"
  read op
  echo User prompted to continue with search >> database.log
  if [ $op == y ]
	  then
	  echo -e "You decided to continue \e[1;31msearching\e[0m"
	  echo User decided to continue searching | ts >> database.log
      sleep 1
	  clear
	  search
  else
      echo -e "\e[1;33mYou decided to go back to home page\e[0m"
	  echo User decided to go back to home page | ts >> database.log
	  sleep 1
	  clear
	  database
  fi

}

function editing
{       
         echo Enter serial numbers to be edited 
		 read -a serial
                                                            #echo ${serial[@]} 
		 len=${#serial[@]}
         search=$1
         shift  
	     matchnum=("$@")
                                                            #echo original
                                                            #echo ${matchnum[@]}
                                                            #echo number of matches 
                                                            #echo ${#matchnum[@]}
		 for((g=0;g<$len;g++))
	     do
		 ser=${serial[$g]}	 
                                                             #echo serial number
                                                             #echo $ser
     	 index=`expr $ser - 1`
                                                             #echo array index number
                                                             #echo $index
		 or=${matchnum[$index]}	 
                                                             #echo original index
                                                             #echo $or	 
         sed -n ${or}p database.csv > data.txt
                                                             #cat data.txt
	     name=`cut -d "," data.txt -f1`
	     mail=`cut -d "," data.txt -f2`
		 telephone=`cut -d "," data.txt -f3`
	     code=`cut -d "," data.txt -f4 | cut -d " " -f1`
		 mobile=`cut -d "," data.txt -f4 | cut -d " " -f2`
		 place=`cut -d "," data.txt -f5`
		 message=`cut -d "," data.txt -f6`
		
		echo "*******************************************************************************"
        echo -e "\e[1;92mEDITING ENTRY NO\e[0m:\e[1;91m$or\e[0m"
        echo "*******************************************************************************"

 
		echo -e "Do you want to edit the \e[1;31mname\e[0m(\e[1mcurrent\e[0m:\e[93m$name\e[0m)?[y/n]"
		read a
		if [ $a == y ]
			then
				echo "Enter replacement:"
				read s
				st=$(names "$s")
				first=`echo $st | cut -c1 | tr [a-z] [A-Z]`
	            second=`echo $st | cut -c2- | tr [a-zA-Z] [a-z]`
			    st="$first$second"

                echo -n ""$st"," >> database2.csv
		else	 
                echo -n ""$name"," >> database2.csv

        fi
		
		echo "-------------------------------------------------------------------------------"
		echo -e "Do you want to edit the \e[1;32memail-id\e[0m(\e[1mcurrent\e[0m:\e[93m$mail\e[0m)?[y/n]"
		read a
        if [ $a == y ]
			then
				echo "Enter replacement:"
				read s
				st=$(mails "$s") 
                echo -n ""$st"," >> database2.csv
		else	 
                echo -n ""$mail"," >> database2.csv
				
        fi
		
		echo "-------------------------------------------------------------------------------"
		echo -e "Do you want to edit the \e[1;33mtelephone number\e[0m(\e[1mcurrent\e[0m:\e[93m$telephone\e[0m)?[y/n]"
		read a
        if [ $a == y ]
			then
				echo "Enter replacement:"
	   			read s
				st=$(telephones "$s")
                echo -n ""$st"," >> database2.csv
		else	 
                echo -n ""$telephone"," >> database2.csv
        fi
        
		echo "-------------------------------------------------------------------------------"
        echo -e "Do you want to edit the \e[1;34mcountry code\e[0m(\e[1mcurrent\e[0m:\e[93m$code\e[0m)?[y/n]"
		read a
        if [ $a == y ]
			then
				echo "Enter replacement:"
				read s
				st=$(codes "$s")
                echo -n ""$st"," >> database2.csv
		else	 
                echo -n ""$code" " >> database2.csv
		fi
         
		echo "-------------------------------------------------------------------------------"
        echo -e "Do you want to edit the \e[1;35mmobile number\e[0m(\e[1mcurrent\e[0m:\e[93m$mobile\e[0m)?[y/n]"
		read a
        if [ $a == y ]
			then
				echo "Enter replacement:"
				read s
				st=$(mobiles "$s")
                echo -n ""$st"," >> database2.csv
		else	 
                echo -n ""$mobile"," >> database2.csv
        fi

        echo "-------------------------------------------------------------------------------"
		echo -e "Do you want to edit the \e[1;36mplace\e[0m(\e[1mcurrent\e[0m:\e[93m$place\e[0m)?[y/n]"
		read a
        if [ $a == y ]
			then
				echo "Enter replacement:"
				read s
				st=$(places "$s")
                first=`echo $string | cut -c1 | tr [a-z] [A-Z]`
	            second=`echo $string | cut -c2- | tr [a-zA-Z] [a-z]`
			    st="$first$second"
                echo -n ""$st"," >> database2.csv
		else	 
                echo -n ""$place"," >> database2.csv
        fi
				
		echo "-------------------------------------------------------------------------------"
        echo -e "Do you want to edit the \e[1;37mmessage\e[0m(\e[1mcurrent\e[0m:\e[93m$message\e[0m)?[y/n]"
		read a
        if [ $a == y ]
			then
				echo "Enter replacement:"
				read s
				st=$s
			    echo "$st" >> database2.csv
		else	 
                echo "$message" >> database2.csv

        fi

        echo "-------------------------------------------------------------------------------"
		
		replacement=`sed -n 1p database2.csv`
		sed -i "${or}s/.*/$replacement/" database.csv 
        echo
		echo -e "\e[1;33mENTRY EDITED SUCCESSFULLY !!\e[0m"
		echo
        echo "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
        echo Entry number $or edited in database | ts >> database.log
		echo
		echo
        rm database2.csv
		rm data.txt

        
done
	   
}

function edit 
{   
  counter=`cat database.csv | wc -l`
    if [ $counter -eq 0 ]
		then
		echo -e "\e[1;91mDATABASE EMPTY !!\e[0m"
		sleep 2
	else 

    clear
    echo -e "\e[92m***************************************************************\e[0m"
	echo -e "\e[1;91m                            EDIT                               \e[0m"
	echo -e "\e[93m***************************************************************\e[0m"
	echo
	echo -e "\e[1m        SELECT PARAMETER TO BE SEARCHED BY :\e[0m"
	echo	
	echo "         1-Name"
	echo "         2-Email-Id"
	echo "         3-Telephone number"
	echo "         4-Mobile number"
	echo "         5-Place"
	echo "         6-Message"
	read -s para		

      if [ $para -eq 1 ]
		then
		echo User decided to search by name | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mname\e[0m"
		echo
        echo "Enter name"
    	read a
		str=$(names "$a")
		no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)  
		n=`grep -w -i "$str" database.csv | wc -l`
		if [ $n -eq 0 ]
			then 
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
		else		
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
		editing "$str" "${no[@]}"
		fi

    elif [ $para -eq 2 ]
		then
		echo User decided to search by email-id | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31memail-id\e[0m"
		echo
        echo "Enter email-id"
    	read a
		str=$(mails "$a")
		no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
        n=`grep -w -i "$str" database.csv | wc -l`
		if [ $n -eq 0 ]
			then
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
				sleep 2
		else		
        grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        editing "$str" "${no[@]}"    
        fi

     elif [ $para -eq 3 ]
		then
		echo User decided to search by telephone number | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mtelephone number\e[0m"
		echo
        echo "Enter telephone number"
    	read a
		str=$(telephones "$a")
        n=`grep -w -i "$str" database.csv | wc -l`
        no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
		if [ $n -eq 0] 
			then 
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
				sleep 2
		else		
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        editing "$str" "${no[@]}"  
		fi

    elif [ $para -eq 4 ]
		then
		echo User decided to search by mobile number | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mmobile number\e[0m"
		echo
        echo "Enter mobile number"
    	read a
		str=$(mobiles "$a")
		n=`grep -w -i "$str" database.csv | wc -l`
		no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
		if [ $n -eq 0 ]
			then
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
				sleep 2
		else		
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        editing "$str" "${no[@]}" 
		fi
 
    elif [ $para -eq 5 ]
		then
		echo User decided to search by place | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mplace\e[0m"
		echo
        echo "Enter place"
    	read a
		str=$(places "$a")
        n=`grep -w -i "$str" database.csv | wc -l`
        no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
		if [ $n -eq 0 ]
			then
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
				sleep 2
		else		
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        editing "$str" "${no[@]}"  
		fi

    elif [ $para -eq 6 ]
		then
		echo User decided to search by message | ts >> database.log
		echo
		echo -e "You decided to search by \e[1;31mmessage\e[0m"
		echo
        echo "Enter message"
    	read a
		str=$a
		n=`grep -w -i "$str" database.csv | wc -l`
		if [ $n -eq 0 ]
			then
				echo -e "\e[1;31mNO MATCHES FOUND !!\e[0m"
				sleep 2
		else		
        no=(`grep -w -i -n "$str" database.csv | cut -d ":" -f1`)
		grep -w -i "$str" database.csv >> database1.csv
		view $n "${no[@]}"
        editing "$str" "${no[@]}"  
		fi
	fi
  echo
  echo -e "\e[1mDo you want to continue editing?\e[0m[y/n]"
  read op
  echo User prompted to continue editing | ts >> database.log
  if [ $op == y ]
	  then
	  echo -e "You decided to continue \e[1;31mediting\e[0m"
	  echo User decided to continue editing | ts >> database.log
      sleep 2
	  clear
	  edit
  else
      echo -e "\e[1;33mYou decided to go back to home page\e[0m"
	  echo User decided to go back to home page | ts >> database.log
	  sleep 2
	  clear
	  database
  fi
fi
}


#-------------------------------------------------application function-----------------------------------------------

function database
{
clear
echo -e "\e[1;33m#####################################################################\e[0m"
echo -e "\e[1;32m    ******\e[0m                  \e[1;31mHEY THERE\e[0m                   \e[1;32m******\e[0m     "
echo -e "\e[1;32m#####################################################################\e[0m"
echo 
echo -e "        \e[1m SELECT AN OPTION \e[0m          "
echo
echo -e "           1-\e[1mADD\e[0m entry to database"
echo -e "           2-\e[1mSEARCH\e[0m for entry in database " 
echo -e "           3-\e[1mEDIT\e[0m entry present in database"
echo -e "           4-\e[1mVIEW\e[0m entire database"
echo -e "           5-\e[1mEXIT\e[0m application"
read  -s -t 10 option

if [ ! -z $option ]
   then 
   echo Application launched | ts >> database.log
   echo
else
   echo Application launched | ts >>  database.log
   echo	   
   echo -e "\e[1;91mTIME OUT !!!\e[0m"
   sleep 2
   echo "Session  timed-out" | ts >> database.log
   echo
   echo -e "\e[1mDo you want to relaunch app?\e[0m[y/n]"
   read select
   if [ $select == 'y' ]
      then
	  echo User decided to re-execute application | ts >> database.log
	  echo -e "\e[1;33mYou decided to re-execute application\e[0m"
	  sleep 1
	  bash database.sh
   else  
      echo User decided to exit the application | ts >> database.log
	  clear	
	  echo
	  echo -e "           \e[1;31mCLOSING APPLICATION\e[0m          "
	  echo
	  sleep 2
	  exit
   fi

fi


if [ $option -eq 1 ]
   then
     echo User chose to ADD entry to database | ts >> database.log
	 echo -e "You chose to \e[1;31madd\e[0m entry"
	 sleep 1
     function entry
     {
      echo -e "\e[1;33m------------------------------------------------------------------\e[0m"
	  echo -e "\e[1;31mFORMAT : ALPHABETS AND SPACES ONLY\e[0m"	  
      name
	  echo
	  echo -e "\e[1;33m------------------------------------------------------------------\e[0m"
      echo -e "\e[1;31mFORMAT : aaaa@bbbb.cccc (ALPHABETS,DIGITS[0-9],'_'only)\e[0m"
      mail
      echo
	  echo -e "\e[1;33m------------------------------------------------------------------\e[0m"
	  echo -e "\e[1;31mFORMAT : 8 DIGITS ONLY [0-9]\e[0m"
      telephone
      echo
	  echo -e "\e[1;33m------------------------------------------------------------------\e[0m"
	  echo -e "\e[1;31mFORMAT : +/0[0-9]\e[0m"
      code
      echo
	  echo -e "\e[1;33m------------------------------------------------------------------\e[0m"
	  echo -e "\e[1;31mFORMAT : 10 DIGITS ONLY [0-9]\e[0m"
      mobile
      echo
	  echo -e "\e[1;33m------------------------------------------------------------------\e[0m"
	  echo -e "\e[1;31mFORMAT : ALPHABETS AND SPACES ONLY\e[0m"
      place
      echo
	  echo -e "\e[1;33m------------------------------------------------------------------\e[0m"
	  echo -e "\e[1;31mFORMAT : NONE\e[0m" 
      message 
      echo
	  echo -e "\e[1;33m-------------------------------------------------------------------\e[0m"
	  echo
	  echo -e "\e[1;32mENTRY SUCCESSFULL ADDED TO DATABASE !!!\e[0m"
	  sleep 2
      echo Entry added to database | ts >> database.log
     }
entry

elif [ $option -eq 2 ]
   then
     echo "User decided to search for entries in database" | ts >> database.log
	 echo -e "You decided to \e[1;31msearch\e[0m for entries in database"
     sleep 1
     search

elif [ $option -eq 3 ]
   then
     echo "User decided to edit entires in database" | ts >> database.log
	 echo -e "You decided to \e[1;31medit\e[0m entires in database"
	 sleep  2
	 edit

elif [ $option -eq 4 ]
   then
     echo "User decided to view entire database" | ts >> database.log
	 echo -e "You decided to \e[1;31mview\e[0m the database" 
	 sleep 2
	 num=`cat database.csv | wc -l`
	 if [ $num -eq 0 ]
		 then
		echo -e "\e[1;31mDATABASE EMPTY !!\e[0m"
		sleep 2
     else

	 echo -e "\e[1;93m************************\e[0m" >> data1.txt
	 echo -e "\e[1;91mTOTAL ENTRIES\e[0m : \e[92m$num\e[0m    ">> data1.txt
	 echo -e "\e[1;93m************************\e[0m">> data1.txt
	 echo >> data1.txt
	 echo >> data1.txt
	 for((i=1;i<=$num;i++))
	     do  
             sed -n ${i}p database.csv > data.txt
			 name=`cut -d "," data.txt -f1`
			 mail=`cut -d "," data.txt -f2`
			 telephone=`cut -d "," data.txt -f3`
			 code=`cut -d "," data.txt -f4 | cut -d " " -f1`
			 mobile=`cut -d "," data.txt -f4 | cut -d " " -f2`
			 place=`cut -d "," data.txt -f5`
			 message=`cut -d "," data.txt -f6`

             echo -e "\e[34m..............................................................................\e[0m" >> data1.txt
			 echo -e "\e[1;31mENTRY NUMBER\e[0m : \e[32m$i\e[0m                                                           **" >> data1.txt
			 echo -e "\e[34m------------------------------------------------------------------------------\e[0m" >> data1.txt
			 echo >> data1.txt
			 echo "  NAME : $name" >> data1.txt
			 echo "  EMAIL-ID : $mail" >> data1.txt
			 echo "  TELEPHONE NUMBER : $telephone" >> data1.txt
			 echo "  COUNTRY CODE : $code" >> data1.txt
			 echo "  MOBILE NUMBER : $mobile " >> data1.txt
			 echo "  PLACE : $place" >> data1.txt
			 echo "  MESSAGE : $message" >> data1.txt
			 echo >> data1.txt
			 echo "-------------------------------------------------------------------------------" >> data1.txt
	
         done
             (  
		     echo -e "Use \e[1;31mup\e[0m and \e[1;31mdown\e[0m arrow keys to navigate and \e[1;31mq\e[0m to quit"
			 echo
             cat data1.txt
			 echo
             echo -e "Use \e[1;31mup\e[0m and \e[1;31mdown\e[0m arrow keys to navigate and \e[1;31mq\e[0m to quit"
             ) | less -R
			 rm data1.txt data.txt
      fi

elif [ $option -eq 5 ]
   then
     clear
     echo "User decided to exit the application" | ts >> database.log
	 echo
	 echo -e "          \e[1;31mCLOSING APPLICATION\e[0m         "
	 echo
	 sleep 1
	 clear
	 exit
fi
}

database


while [ 1 ]
do
clear
echo -e "\e[1mDo you want to relaunch application?\e[0m[y/n]"
read op
if [ $op == "y" ]
   then
   echo User decided to re-execute application | ts >> database.log
   echo -e "\e[1;33mYou decided to re-execute application\e[0m"
   sleep 1
   database
else 
   clear
   echo User decided to exit application | ts >> database.log
   echo "closing Application"
   sleep 1
   clear
   exit
fi
done
