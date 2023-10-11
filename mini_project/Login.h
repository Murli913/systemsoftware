#ifndef LOGIN_H
#define LOGIN_H
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include "Menu.h"
#include "Authenticate.h"
#include "Model.h"
#include "Error.h"
#include "Add.h"
int AdminLogin(){
    const char *filename = "admin";
		char inputUsername[100];
    	char inputPassword[100];
		printf("Username: ");
		scanf("%s",inputUsername);
		printf("Password: ");
		scanf("%s",inputPassword);
		int result = authenticateAdmin(filename, inputUsername, inputPassword);
    	if (result == 1) {
        	printf("Authentication successful. Welcome, %s!\n", inputUsername);  
    	} else if (result == 0) {
        printf("Authentication failed. Invalid username or password.\n");
    	} else {
        printf("Error occurred during authentication.\n");
        }
        return result;
}
void StudentLogin(){
		const char *filename = "StudentRecord.txt";
		char inputUsername[100];
    	char inputPassword[100];
		printf("Username: ");
		scanf("%s",inputUsername);
		printf("Password: ");
		scanf("%s",inputPassword);
		int result = authenticateStudent(filename, inputUsername, inputPassword);
    	if (result == 1) {
        	printf("Authentication successful. Welcome, %s!\n", inputUsername);
			StudentMenu();
    	} else if (result == 0) {
        printf("Authentication failed. Invalid username or password.\n");
    	} else {
        printf("Error occurred during authentication.\n");
    	}
}
void FacultyLogin(){
    {
		const char *filename = "FacultyRecord.txt";
		char inputUsername[100];
    	char inputPassword[100];
		printf("Username: ");
		scanf("%s",inputUsername);
		printf("Password: ");
		scanf("%s",inputPassword);
		int result = authenticateStudent(filename, inputUsername, inputPassword);
    	if (result == 1) {
        	printf("Authentication successful. Welcome, %s!\n", inputUsername);
			FacultyMenu();
    	} else if (result == 0) {
        printf("Authentication failed. Invalid username or password.\n");
    	} else {
        printf("Error occurred during authentication.\n");
    	}
		}
}
#endif
