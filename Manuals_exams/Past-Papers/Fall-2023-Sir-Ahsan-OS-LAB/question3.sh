#!/bin/bash

# Step 1: Ask the user to enter the name of a directory
echo "Enter the name of the directory:"
read dir_name

# Step 2: Check if the directory exists. If not, create the directory.
if [ ! -d "$dir_name" ]; then
    echo "Directory does not exist. Creating it..."
    mkdir "$dir_name"
else
    echo "Directory already exists."
fi

# Step 3: Inside the directory, create three subdirectories
cd "$dir_name" || exit
mkdir -p Images Documents Others

echo "Subdirectories 'Images', 'Documents', and 'Others' created."

# Step 4: Ask the user to enter the number of files to generate for each subdirectory
echo "Enter the number of files to generate for each subdirectory:"
read file_count

# Step 5: Generate files with random names in each subdirectory
for ((i = 1; i <= file_count; i++)); do
    # Generate random file name
    random_file="file_$i23.txt"
    
    # Step 6: Assign files to a random subdirectory
    case $((RANDOM % 3)) in
        0) touch "Images/$random_file" ;;
        1) touch "Documents/$random_file" ;;
        2) touch "Others/$random_file" ;;
    esac
done

# Step 7: Display a summary of the created directories, subdirectories, and files
echo "Summary of created directories and files:"
echo "Directory Name: $dir_name"
echo "Subdirectories:"
echo "  Images: $(ls Images | wc -l) files"
echo "  Documents: $(ls Documents | wc -l) files"
echo "  Others: $(ls Others | wc -l) files"

exit 0
