#!/bin/sh

Task_loop(){
    case $1 in
    1)      
            gcc task1_script_for_c.c '-o' task1scriptforc
            ;;
    2)
	    gcc task1_script_for_c.c '-o' task1scriptforc
            ./task1scriptforc
            ;;
    3)
            echo "Contents of the original file:"
            echo $task1_script_for_c
            ;;
    *)
            	
            ls
            ;;
    esac
}

touch task1_script_for_c
echo '#include<stdio.h> 
int main()
{ printf("Hello World");return 0; }' > task1_script_for_c
echo $task1_script_for_c > 'anotherfile.c'

echo "Copied"
a=1
while [ $a -eq 1 ]
do
echo "Choose an option:"
echo "1.compile"
echo "2.compile run "
echo "3.print contents of original file"
echo "Any  key to  Print contents of  current directory"
read x

Task_loop $x
echo " continue 1 for yes 0 for no"
read a
done
