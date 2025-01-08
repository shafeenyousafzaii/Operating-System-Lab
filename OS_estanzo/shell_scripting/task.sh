#!/bin/bash

echo "Creating The File"
touch test2.c

echo "Copying the Content"
cp test.c test2.c

echo "Press 1 to Compile"
echo "Press 2 to Compile and Run The File"
echo "Press 3 to See the Contents orignal File"
read d
case ${d} in 
1) gcc test2.c;;
2) gcc test2.c -o test2 && ./test2;;
3) cat test.c && echo " ";;
*) ls;;
esac

