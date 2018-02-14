#!/bin/bash
#SCRIPT : command_line_test.sh
#PURPOSE : login based Test 

clear

        #to check if username entered by user at signup is unique :

function uservalid
{
flag=0
num=`cat user.csv | wc -l` #number of users that have signed up
declare -a existname=(`cut -d "," -f 1 user.csv`) #usernames stored in an array
for user in ${existname[@]}
  do
    if [ "$1" == "$user" ] #match user input with names in database
     then
      flag=`expr $flag + 1` #increament if match
    fi
  done
if [ $flag -eq 0 ] 
  then
   return 1
else
   echo -e "\e[1;31mUsername already exists.Please enter a different username\e[0m"
   echo Pre-existing username entered.Prompted to enter again | ts >> test_activity.log
   userup
fi
}

         #to check if username entered by user to sign in present in database :
 
function signin_valid
{
flag=0
num=`cat user.csv | wc -l` 
declare -a existname=(`cut -d "," -f 1 user.csv`) 

for user in ${existname[@]}
  do
   if [ "$1" == "$user" ]
     then
       respass=`grep $1 user.csv | cut -d "," -f 2`  
                                     #password to the respective user
       
       return 1 #exit function as username matches entry in database
   else 
       flag=`expr $flag + 1` #increament if name doesnt match entry in database
      continue
   fi
  done

if [ $flag -gt 0 ]
  then 
     echo -e "\e[1;31mUsername not present!!Try again\e[0m"
     echo Invalid username entered.Prompted to enter again | ts >> test_activity.log
     userin # ask user to follow signin procedure again as name doesnt match 
            #entry in data base
fi
}

         # take username to signin :
       
function userin
{
unset name	
echo -e "\e[1mUsername:\e[0m"
read name
signin_valid ${name}  # to validate user based on presence in data base
}
# take password for signin : 
function passin
{
echo -e "\e[1mPassword:\e[0m"
read -s pass
if [ $pass == $respass ] #to match password with password given
                         #  at the time of signup
   then
     echo
     echo -e "\e[36;1mSignin Successfull\e[0m"
     echo Signin Successfull | ts >> test_activity.log
     echo $name signed in | ts >> test_activity.log
	 sleep 2
     return 1 # exit function if passwords match
else 
     echo -e "\e[1;31mIncorrect!!Try again\e[0m"
     echo Invalid password entered.Prompted to enter again | ts >> test_activity.log 
     passin #ask user to give password again as doesnt match entry in data base
fi 
}

      # take username to signup :

function userup
{

unset name	
echo -e "\e[1mUsername\e[0m\e[1;91m(should be alphanumeric only)\e[0m:"
read name
if [ "$name" == "`echo $name | grep -e "[0-9]\+[a-zA-Z]\+" -e "[a-ZA-Z]\+[0-9]\+" `" ] # to check if username is alphanumeric or not
   then
      uservalid ${name} #check if username already exists (unique or not)
      echo -n "$name"  >> user.csv #add unique username to database
      return 1
else
      echo -e "\e[1;31mInvalid input!!Try again\e[0m"
      echo Invalid username entered.Prompted to enter again | ts >> test_activity.log
      userup #ask user to enter username again as it is not unique 
             #(already exists in data base)
fi
}

         #take password to signup :

function passup
{
unset pass	
echo -e "\e[1mPassword\e[0m\e[1;91m(should contain atleast a number and a symbol and min. 8 characters long)\e[0m:"
read -s pass
if [[ $pass =~ ^.*[0-9].*$ ]] && [[ $pass =~ ^.*[!@#$%^\&\*].*$ ]] && [[ ${#pass} -ge 8 ]]
          #to check if password has atleast one number,one special character and atleast 8 characters long
   then
     echo
     echo Re-enter the password
     read -s repass
     echo
         if [ "$repass" == "$pass" ]
             then
               echo -n ",$pass" >> user.csv 
                          #add password to database with respective username
               echo >> user.csv
               echo -e "\e[36;1mSignup Successful\e[0m" #password and username meet requirements
               echo Signup successfull | ts >> test_activity.log 
               echo $name signed up | ts >> test_activity.log
			   sleep 2
         else
 echo -e "\e[1;31mInvalid input!!Try again (password not matching re-entered password)\e[0m"
 echo Re-entered password not matching.Prompted to enter again | ts >> test_activity.log
    passup #ask user to enter password again as not matching re-entered password
         fi
else
     echo -e "\e[1;31mInvalid input!!Try again (password not matching requirements)\e[0m"
    passup #ask user to enter password again as not matching requirements
fi
}

         #main function or script :

function clitest
{
echo User using script | ts >> test_activity.log
echo	
echo -e " \e[1;31m**************************************************************************************************************\e[0m  "
echo -e "               #####                                 \e[1;5;96mWELCOME\e[0m                                   ##### "
echo -e " \e[1;32m**************************************************************************************************************\e[0m  "
echo
echo -e "\e[1mPlease select an option\e[0m :"
echo
echo "            1-Signup"
echo "            2-Signin"
echo "            3-Exit"
echo
read -s -t 10 option
echo
if [ ! -z "$option" ] #check if option entered or not by checking size of parameter(0 or not)
   then
    echo User prompted with options | ts  >> test_activity.log                     
                                  #read option and append to log with time stamp
else
    echo 
    echo -e "   \e[31mTimeout!!\e[0m   "
    echo "Script timedout" | ts >> test_activity.log
    sleep 2
    clear
    echo -e "\e[1mDo you want to continue[\e[32my\e[0m/\e[31mn\e[0m]?\e[0m"
	echo "Script timed out.Propmted with option" | ts >> test_activity.log
	read -s op
	if [ $op == "y" ]
		then 
			echo User decided to execute script again | ts >> test_activity.log
			bash command_line_test.sh
	else
            echo User decided to exit script | ts >> test_activity.log 

	    clear
         echo -e " \e[1;94m****************************************************************************************************\e[0m   "
		 echo -e "       ##########                         \e[1;91mThank you for using the script\e[0m            ##########        "
		 echo -e " \e[1;94m****************************************************************************************************\e[0m   "
         sleep 2
		 clear
			exit
    fi			
fi
if [ $option -eq 1 ] #signup
  then 
    echo -e "You chose to \e[1;32msignup\e[0m"
	echo
	echo User decided to signup | ts >> test_activity.log
    userup  #call functions related to signup
    echo
    passup
    echo

elif [ $option -eq 2 ] #signin
  then
    echo -e "You chose to \e[1;32msignin\e[0m"
	echo
	echo User chose to signin | ts >> test_activity.log
    userin  #call functions related to signin
    echo
    passin
    echo
	echo -e "\e[1mWould you like to take the test?\e[0m"
	echo  "          1-Take test "
	echo  "          2-Exit to main Menu(Signout)     "

	      
# echo -e "\e[1;35mSelect an option\e[0m"
# echo "            *take test(take)"
# echo "            *view test(view)"
    echo
    read select
	echo
# echo User decided to $select test | ts >> test_activity.log 
#read option and append to log with time stamp
     if [ $select -eq 1 ] #take
         then
		   echo User decided to take test | ts >> test_activity.log
                          #read option and append to log with time stamp
           echo 
		   echo >> $name.csv	 
		   echo "user:$name" >> $name.csv
           echo
           echo "format : question,answer given,time taken" >> $name.csv 
           echo >> $name.csv
           clear
		   echo
		   echo
		   echo -e "              \e[1;32m**********************************************************\e[0m                           "
           echo -e "                                      \e[1;31mBest of luck\e[0m                                " 
		   echo -e "              \e[1;32m**********************************************************\e[0m                           "
           sleep 2
           clear
           len=`grep "^[0-9]\+\." questions_bank.txt | wc -l` 
                                       #to get number of questions
           declare -a num=(`shuf -i 1-${len} -n ${len}`)
                         #to generate random numbers btw 1 and (no of questions)
           q=1  #to print question number in a series starting from 1

           for (( i=0; i<${len}; i++ ))
             do
			   unset ans	   
               a=${num[i]} #random question number
			   echo -n "$q." #to print question number
			   echo -e "\e[1;91m------------------------------------------------------------------------------\e[0m"
               sed -n "/^${a}\./,+4p" questions_bank.txt | cut -d "." -f2 | cut -d "|" -f 1
			   echo -e "\e[1;92m--------------------------------------------------------------------------------\e[0m"
               sed -n "/^${a}\./,+4p" questions_bank.txt | cut -d "." -f2 | cut -d "|" -f 1 > f.txt

               echo 
           
                        # to limit user to a certain time limit to answer

               total=10  # total wait time in seconds 
               count=0  # counter
               while [ ${count} -lt ${total} ] 
                 do
                   tlimit=$(( $total - $count ))
                 echo -e "\rYou have \e[1;31m${tlimit}\e[0m seconds to enter your answer: \c"
                   read -t 1 ans
                   test ! -z  "$ans" && { break ; } #if not zero break else increment count value 
                   count=$((count+1))
                 done
                     if [ ! -z "$ans" ]  
                       then
						b=`grep -e "^${ans}).*$" f.txt | cut -d ")" -f 2` #to show only answer and not option
						c=`grep -e "^${ans}).*$" f.txt` #to show answer with option
                        echo -e "\nYour answer is \e[93m${b}\e[0m"
                        echo -e "You answered in \e[95m`expr 10 - $tlimit`\e[0m seconds"
						echo -e "\e[1;94m--------------------------------------------------------------------------------\e[0m"
                        echo "$q. `sed -n "/^${a}\./p" questions_bank.txt | cut -d "|" -f1 | cut -d "." -f2`,$c,$count" >> $name.csv 
                                                           #appened question with answer given by user and store in file
						echo "`sed -n "/^${a}\./p" questions_bank.txt | cut -d "|" -f1`,$c" >> h.txt
                        
                        sleep 2    
                   else
					echo "$q. `sed -n "/^${a}\./p" questions_bank.txt |cut -d "|" -f1 | cut -d "." -f2`,timed out" >> $name.csv
                    echo "`sed -n "/^${a}\./p" questions_bank.txt | cut -d "|" -f1`,e)timed out " >> h.txt 
                        echo -e "\n\e[1;31mTime out!\e[0m"
						echo -e "\e[1;94m--------------------------------------------------------------------------------\e[0m"
                        sleep 1
                    fi
					q=`expr $q + 1`
              clear
              done
			  cat h.txt | sort -n > q.txt #to get original sequence of question numbers
              echo
              echo Test completed by the user | ts >> test_activity.log
			  echo
			  echo
			  echo -e "  \e[1;31m********************************************************\e[0m    "
              echo -e "                      \e[1;92mTEST COMPLETE\e[0m                          "
			  echo -e "  \e[1;31m********************************************************\e[0m    "
              sleep 2
              clear
      
           
		   echo -e "\e[1;32m#####################################################################################################################\e[0m "
		   echo
           echo -e "                       \e[1;33m ***********************\e[0m    \e[1;31m RESULT TIME\e[0m      \e[1;33m**************************\e[0m                       "
           echo
           echo -e  "\e[1;32m#####################################################################################################################\e[0m "
		   sleep 2
		   clear
           mark=0
           array1=(`grep -e "^[0-9]\+\." questions_bank.txt | cut -d "|" -f2`) #right answers put in an array
           array2=(`cut -d "," q.txt -f 2 | cut -d ")" -f 1`)  #user entered answers put in  array
		   num=${#array1[@]}
		   for ((i=1;i<=num;i++))
			   do
				j=`expr $i - 1` 
					if [[ ${array2[j]} == e ]]
						then
				          sed -n "/^${i}\./,+4p" questions_bank.txt | cut -d "|" -f1 > m.txt
						  sed -i "1s/$/`echo -e " : \e[37mstatus\e[0m : \e[1;31mTimed Out\e[0m"`/" m.txt  
						  cp m.txt o.txt
				          cat o.txt | GREP_COLORS="mt=01;32" grep --colour=always -e "^" -e "${array1[j]}).*" >> right.txt
				          echo >> right.txt
							
				    elif [[ ${array1[j]} != ${array2[j]} ]]
					    then
			              sed -n "/^${i}\./,+4p" questions_bank.txt | cut -d "|" -f1 > m.txt
						  sed -i "1s/$/`echo -e " : \e[37mstatus\e[0m : \e[1;31mwrong\e[0m"`/" m.txt                         
						  cp m.txt o.txt
                          cat o.txt | GREP_COLORS="mt=01;31" grep --colour=always -e "^" -e "${array2[j]}).*" > r.txt
                          cat r.txt | GREP_COLORS="mt=01;32" grep --colour=always -e "^" -e "${array1[j]}).*" >> right.txt 
                          echo >> right.txt

				    elif [[ ${array1[j]} == ${array2[j]} ]]
				        then 
					      mark=`expr $mark + 1`
					      sed -n "/^${i}\./,+4p" questions_bank.txt | cut -d "|" -f1 > m.txt
	                      sed -i "1s/$/`echo -e " : \e[37mstatus\e[0m : \e[1;32mRight\e[0m"`/" m.txt                        
						  cp m.txt o.txt
						  cat o.txt | GREP_COLORS="mt=01;31" grep --colour=always -e "^" -e "${array2[j]}).*" > r.txt
						  cat r.txt | GREP_COLORS="mt=01;32" grep --colour=always -e "^" -e "${array1[j]}).*" >> right.txt
			              echo >> right.txt

			        fi
			    	
			   done
            (
			 echo -e "  \e[33m*************************************************************************\e[0m"
             echo -e "                      ***  You scored \e[1;5;91m${mark}/${num}\e[0m  ***         "
			 echo -e "  \e[33m*************************************************************************\e[0m"
             echo
			 echo -e "Use \e[91mup\e[0m and \e[91mdown\e[0m arrow keys to navigate and \e[91mq\e[0m to quit "
			 echo -e "\e[93m------------------------------------------------------------------\e[0m"
             cat right.txt
			 echo -e "\e[93m------------------------------------------------------------------\e[0m"
			 echo -e "Use \e[91mup\e[0m and \e[91mdown\e[0m arrow keys to navigate and \e[91mq\e[0m to quit"
            ) | less -R
			 
					else 
						echo User decided to exit to main menu | ts >> test_activity.log
						echo $name signed out | ts >> test_activity.log	
						clear	
						bash command_line_test.sh	
                    fi

elif [ $option -eq 3 ] #exit
    then    
	  echo User decided to exit script | ts >> test_activity.log
      clear
	  echo
	  echo
	  echo -e " \e[1;94m******************************************************************************************************\e[0m "
	  echo -e "          #########                  \e[1;91mThank you for using the script\e[0m       ##########                          "
	  echo -e " \e[1;94m******************************************************************************************************\e[0m "
	  sleep 2
      clear
      rm f.txt h.txt q.txt r.txt right.txt o.txt m.txt
      exit

else
     echo -e "\e[31mInvalid input.Try again\e[0m"
     clitest #call main function again

fi

}

clitest

while [ 1 ]
  do
    echo -e "\e[1mDo you want continue ?\e[0m" # user wants to execute procedure again
    echo User prompted to continue or exit | ts >> test_activity.log
    echo
    echo *Enter yes to continue
    echo *Enter no to exit
    echo
    read option    
    if [ $option == "yes" ]
      then
      echo User decided to continue | ts >> test_activity.log
      clear
      clitest #call main function
    else 
      echo User decided to exit | ts >> test_activity.log
	  rm f.txt h.txt q.txt r.txt right.txt o.txt m.txt
	  clear
      echo
      echo
      echo -e " \e[1;94m******************************************************************************************************\e[0m "
	  echo -e "          #########                  \e[1;91mThank you for using the script\e[0m       ##########                          "
	  echo -e " \e[1;94m******************************************************************************************************\e[0m "

      sleep 2
      clear
      exit
   fi
  done
