# !/bin/bash 
# To declare static Array 
arr=(1 12 31 4 5) 
i=0 

# Loop upto size of array 
# starting from index, i=0 
while [ $i -lt 5 ] 
do
	# To print index, ith 
	# element 
	echo ${arr[$i]} 
	
	# Increment the i = i + 1 
	i=`expr $i + 1` 
done
