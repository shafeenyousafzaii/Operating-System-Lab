#!/bin/bash
touch task1_script_for_c
echo '#include<stdio.h> 
int main()
{ printf("Hello World");return 0; }' > task1_script_for_c
echo $task1_script_for_c > 'anotherfile.c'
echo """1 for compile , 2 for compile and run , 3 for printing content , if any input other than that"""
read a
if [ $a -eq 1 ]
then
gcc task1_script_for_c.c '-o' task1scriptforc
fi
if [ $a -eq 2 ]
then
gcc task1_script_for_c.c '-o' task1scriptforc
./task1scriptforc
fi
if [ $a -eq 3 ]
then
ls
fi
ls
