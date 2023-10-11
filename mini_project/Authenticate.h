#ifndef AUTHENTICATE_H
#define AUTHENTICATE_H
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include "Model.h"
#include "Error.h"
int authenticateAdmin(const char *filename, const char *inputUsername, const char *inputPassword) {
    struct Admin user;
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        error("Error opening file");
    }
    while (read(fd, &user, sizeof(user)) > 0) {
		// printf("emailId: %s",user.emailId);
		// printf("password: %s",user.password);
        if (strcmp(inputUsername, user.emailId) == 0 && strcmp(inputPassword, user.password) == 0) {
            close(fd);
            return 1;  // Authentication successful
        }
    }

    close(fd);
    return 0;  // Authentication failed
}
int authenticateStudent(const char *filename, const char *inputUsername, const char *inputPassword) {
    struct Student user;
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        error("Error opening file");
    }
	printf("%d\n",fd);
    while (read(fd, &user, sizeof(user)) > 0) {
		// printf("emailId: %s",user.emailId);
		// printf("password: %s",user.password);
        if (strcmp(inputUsername, user.emailId) == 0 && strcmp(inputPassword, user.password) == 0 && user.status==1) {
            close(fd);
            return 1;  // Authentication successful
        }
    }

    close(fd);
    return 0;  // Authentication failed
}
int authenticateFaculty(const char *filename, const char *inputUsername, const char *inputPassword) {
    struct Faculty user;
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        error("Error opening file");
    }
	printf("%d\n",fd);
    while (read(fd, &user, sizeof(user)) > 0) {
		// printf("emailId: %s",user.emailId);
		// printf("password: %s",user.password);
        if (strcmp(inputUsername, user.emailId) == 0 && strcmp(inputPassword, user.password) == 0) {
            close(fd);
            return 1;  // Authentication successful
        }
    }

    close(fd);
    return 0;  // Authentication failed
}
#endif
