#!/bin/bash
# Operation menu
function display_menu(){
	echo "Please select the operation you want to perform"
	echo "1. Insert the employee details."
	echo "2. Search for employee details."
	echo "3. Delete employee details."	
	echo "4. Sort employee details."
	echo "5. Display employee details."
	echo "6. List All  employee details."
	echo "7. Exit."
	echo 
}
function create_record(){
	read -p "Enter employee name " ename
	read -p "Enter employee number " eno
	read -p "Enter employee cell number " enum
	#Check if already exists
	if grep -q "^.*:$eno:.*$" employeeRecord.txt; then
		echo "Employee number $eno  already exist"
	else
		#append new record
		echo "----------------------------------------------------------------------"
		echo "$ename:$eno:$enum">>employeeRecord.txt
		echo "Employee record created successfully!!!"
		echo "----------------------------------------------------------------------"
	fi

}
function search(){
	read -p "Enter employee number to search " eno
	echo "-----------------------------------------------------------------------"
	grep "^.*:$eno:.*$" employeeRecord.txt
	echo "-----------------------------------------------------------------------"
}
function delete_record(){
	read -p "Enter Employee number to delete " eno
	#use temp file to store updated record
	grep -v "^.*:$eno:.*$" employeeRecord.txt > temp.txt
	#mv -move, rm -remove
        mv temp.txt employeeRecord.txt
	echo "Employee Record deleted successfully!"       
}
function sortRecords(){
	sort -t':' -k2n employeeRecord.txt > temp.txt
	mv temp.txt employeeRecord.txt
	echo "Record sorted successfully!"
}
function displayEmployee(){
	search
}
function listOfEmployees(){
	#sed is strem editor
	# 's/pattern/replacement/global'=>'s/:/ /g'
	echo "-----------------------------------------------------------------------"
	sed 's/:/ /g' employeeRecord.txt
	echo "-----------------------------------------------------------------------"
}
while(true)
do
	display_menu
	read -p "Enter the option(1-7) " option
	case $option in
		1) echo "Insert Employee details "
			create_record;;
		2) echo "Search Record "
			search;;
		3) echo "Delete Record"
			delete_record;;
		4) echo "Sort Employee details"
			sortRecords ;;
		5) echo "Display Employee Detail"
			displayEmployee;;
		6) listOfEmployees;;
		7) exit 0;;
	esac
echo	
done

