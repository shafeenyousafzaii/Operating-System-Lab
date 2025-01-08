#!/bin/sh
echo "Enter a value"
read a
echo "Enter Another Value"
read b

# Addition
c=`expr ${a} + ${b}`
echo "Sum: "${c}

# Subtraction
c=`expr ${a} - ${b}`
echo "Difference: "${c}

# Multiplication
c=`expr ${a} \* ${b}`
echo "Multiplication: "${c}

# Division
c=`expr ${a} / ${b}`
echo "Division: "${c}

