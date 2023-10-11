/*
============================================================================
Name : handson15.c
Author : Murli Talreja
Description : Write a program to display the environmental variable of the user (use environ).
Date: 09th Sept, 2023.
============================================================================
*/

#include<stdio.h>

extern char **environ;

void main() {
  for(int i=0; environ[i]!=NULL; i++)
    printf("%s\n", environ[i]);
}
