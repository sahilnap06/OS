#! /bin/sh

echo "Enter the name of file::"
read fp
create()
{ 
   i=0
   echo "Enter the number of records::"
   read n
   while [ $i -lt $n ]
   do
   
     echo "Enter the id::"
     read id1
     echo "Enter the name::"
     read name
     echo "Enter the address::"
     read address
     echo "Enter the phone number::"
     read phone
     echo $id1  "\t"  $name  "\t"  $address  "\t"  $phone >> $fp
     i=`expr $i + 1`
   done 
}   
display()
{
   echo "-------------------ADDRESS BOOK--------------------\n"
	echo  "ID  \t  Name  \t  Address  \t  Mob Number"
	cat $fp
	echo "\n---------------------------------------------------" 
}

add()
{
     echo "Enter the id::"
     read id1
     echo "Enter the name::"
     read name
     echo "Enter the address::"
     read address
     echo "Enter the phone number::"
     read phone
     echo  $id1  "\t"  $name  "\t"  $address  "\t"  $phone >> $fp
}
search() {
	echo "\nEnter ID to be searched:"
	read id1
	if [ $(grep -wc $id1 $fp) -eq 0 ]
	then
	      echo "RECORD NOT FOUND"
	else
		echo "\nName  \t  Roll Number  \t  Mob Number\n"
		
		grep -w $id1 $fp
	fi
}

delete() {
	echo "\nEnter ID to be deleted:"
	read id1
	if [ $(grep -wc $id1 $fp) -eq 0 ]
	then
	
	      echo "RECORD NOT FOUND"
	else
		grep -v -w $id1 $fp > temp.txt
	#sed "/"$roll"/d" student.txt > temp.txt
		mv temp.txt $fp

		echo "\nRecord deleted Successfully!!"
	fi
}

modify() {
	echo "\nEnter ID to be modified:: "
	read id1
	
	if [ $(grep -wc $id1 $fp) -eq 0 ]
	then
	
	      echo "RECORD NOT FOUND"
	else
		echo "\nEnter new name::"
		read name
	
		echo "\nEnter new address::"
		read address
	
		echo "\nEnter new mobile number::"
		read phone
	
		grep -v -w $id1 $fp > temp.txt
		mv temp.txt $fp
	
		echo $id1  "\t"  $name  "\t"  $address  "\t"  phone >> $fp
	
		echo "\nData Modified!!"
	fi
}


while (true)
do
    echo "\n-----------------STUEDNT DATABASE------------------\n\n"
    echo "1.Create database\n"
    echo "2.Display database\n"
    echo "3.Add a record\n"
    echo "4.Modify a record\n"
    echo "5.Delete a record\n"
    echo "6.Search a record\n"
    echo "7.Exit\n" 
    echo "\n---------------------------------------------------\n"
    echo "Enter the choice"
    read ch
    
    case $ch in
    	1)create;;
    	2)display;;
    	3)add;;
    	4)modify;;
    	5)delete;;
    	6)search;;
    	7)exit;;
    	
    	esac 	       
done
