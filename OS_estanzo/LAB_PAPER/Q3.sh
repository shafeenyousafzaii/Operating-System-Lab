#!/bin/bash
# Taking Input the directory which backup want
echo "Enter the Path of the foler which backup you want"
read dir_path

# Creating the directory of backup
echo "Created the Backup Direcotory In ${dir_path}_bak"
bak_dirname=${dir_path}"_bak"
# Copying the All content into backup directory
cp -r ${dir_path} ${bak_dirname}
