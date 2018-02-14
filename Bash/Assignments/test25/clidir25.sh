#!/bin/bash
#SCRIPT : clidir25.sh
#PURPOSE : to take any number of directories in cli argument form
#          and list the contents

l=$# #number of arguments(directories)
for (( i=1; i<=$#; i++ ))
 do
   cd ${!i} # change to directory given in argument
   echo "${!i}-"
     for n in * #checks in present directory
      do
        echo $n
      done
    echo ""
    cd ..
 done
