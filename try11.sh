# !/bin/bash 
# To input array at run 
# time by using while-loop 

# echo -n is used to print 
# message without new line 
echo -n "Enter the Total numbers :"
read n 
echo "Enter numbers :"
i=0 

# Read upto the size of 
# given array starting from 
# index, i=0 
while [ $i -lt $n ] 
do
	# To input from user 
	read a[$i] 

	# Increment the i = i + 1 
	i=`expr $i + 1` 
done

# To print array values 
# starting from index, i=0 
echo "Output :"
i=0 

while [ $i -lt $n ] 
do
	echo ${a[$i]} 

	# To increment index 
	# by 1, i=i+1 
	i=`expr $i + 1` 
done
