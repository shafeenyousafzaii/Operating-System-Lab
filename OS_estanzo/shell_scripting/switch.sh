#!/bin/bash
ch='y'
while [ ${ch} == 'y' ]
do
echo "Enter a choice"
echo "1 to see who logged on"
echo "2 to see the calender"
echo "3 to print date"

read d
case ${d} in 
1) who;;
2) cal 20;;
3) date;;
*) break;;
esac

echo "do you wish to continue (y/n)"
read ch
done