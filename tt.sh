#!/bin/bash

echo -n "Enter the total numbers:"
read n
echo "Enter the numbers"
i=0
while [ $i -lt $n ]
do
    read a[$i]
    i=`expr $i + 1`
done

echo "output:"
i=0
while [ $i -lt $n ]
do
    echo ${a[$i]}
    i=`expr $i + 1`
done

