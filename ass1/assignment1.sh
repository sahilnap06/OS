#!/bin/bash

choice=0
filename="file.txt"
variable="null"

while [ $choice -ne 4 ]
	do 
		#display the menu
		echo "1 -> Create a file"
		echo "2 -> Write to the file"
		echo "3 -> Read from the file"
		echo "4 -> Search from the file"
		echo "5 -> Exit"
		
		read choice #accept the choice
		case $choice in
		 1 ) echo "Enter the name of the file : "
			read filename
			if [ -e $filename ]
				then
					echo "File already present"
			else
				touch $filename
				ls -l $filename	#checks if the file is created or not
				echo "Welcome to $filename"
			fi
		 	;;
			
		2 )	echo "Enter the name and value in format 'name,value' without quotes"
			read variable
			echo "$variable" >> $filename
			;;
		3 ) echo "The content of the file is as follows : "
			cat $filename 
			;;
		
		4 ) 
		esac
	done