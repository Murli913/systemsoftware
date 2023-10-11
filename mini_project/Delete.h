#ifndef DELETE_H
#define DELETE_H
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include"Error.h"
#include "Model.h"
int deactivateStudent(){
    char emailId[100];
    struct Student student;
    printf("Student Email id: ");
    scanf("%s",emailId);
    int fd = open("StudentRecord.txt",O_RDWR | O_CREAT, 0600);
    if(fd==-1){
        error("File Error");
        return 0;
    }
    while(read(fd,&student,sizeof(struct Student))>0){
        if(strcmp(emailId,student.emailId)==0){
            student.status=0;
            lseek(fd, -sizeof(struct Student), SEEK_CUR);
            write(fd, &student, sizeof(struct Student));
            close(fd);
            printf("Successfully changed status from ACTIVE ---> BLOCK!\n");
            return 1;
        }
    }
    printf("NO record found!\n");
    return 0;
}
int activateStudent(){
    char emailId[100];
    struct Student student;
    printf("Student Email id: ");
    scanf("%s",emailId);
    int fd = open("StudentRecord.txt",O_RDWR | O_CREAT, 0600);
    if(fd==-1){
        error("File Error");
        return 0;
    }
    while(read(fd,&student,sizeof(struct Student))>0){
        if(strcmp(emailId,student.emailId)==0){
            student.status=1;
            lseek(fd, -sizeof(struct Student), SEEK_CUR);
            write(fd, &student, sizeof(struct Student));
            close(fd);
            printf("Successfully changed status from BLOCK ---> ACTIVE!\n");
            return 1;
        }
    }
    printf("NO record found!\n");
    return 0;
}

#endif
