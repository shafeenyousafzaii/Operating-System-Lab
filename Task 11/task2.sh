#!/bin/bash

	Task_loop(){
    case $1 in
    1)      
       	    head -n 5 $filename
            ;;
    2)
	    tail -n 5 $filename
	    ;;
    3)
            wc -w $filename
            ;;
   
    esac
}
echo "File name enter"
read filename
touch filename
echo "File created now add input to the file"
cat > input
cat input > $filename
a=1
while [ $a -eq 1 ]
do
echo "Choose an option:"
echo "1.head"
echo "2.tail"
echo "3.Word count"
read option
Task_loop "$option" "$filename"
echo "continue ? 1 or 0"
read a
done
