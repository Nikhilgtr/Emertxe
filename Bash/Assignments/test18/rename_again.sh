#!/bin/bash
i=1
cd test
for j in *
do
  if [ $i -le 9 ]
then
 mv $j "DSN"_00"$i".jpg
else
mv $j "DSN"_0"$i".jpg
fi
i=`expr $i + 1`
done
cd ..

