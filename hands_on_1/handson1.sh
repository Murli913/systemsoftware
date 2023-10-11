/*
============================================================================
Name : handson1.sh
Author : Murli Talreja
Description : Create the following types of a files using (i) shell command
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 09,Sept, 2023.
============================================================================
*/

ln -s  temp1.txt 1_soft_link
ln temp1.txt 1_hard_link
mkfifi 1_fifo_file
