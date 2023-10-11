#ifndef ADD_H
#define ADD_H
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include"Error.h"
#include "Model.h"
int addStudent(const char *name,const char *rollno,const char *emailId,const char *password){
    struct Student student;
    strcpy(student.name,name);
    strcpy(student.rollno,rollno);
    strcpy(student.password,password);
    strcpy(student.emailId,emailId);
    student.status=1;
    int fd = open("StudentRecord.txt",O_WRONLY | O_CREAT | O_APPEND, 0600);
    if(fd==-1){
        error("File Error");
        return 0;
    }
    ssize_t bytes_written = write(fd, &student, sizeof(struct Student));
    if (bytes_written == -1) {
        error("Error writing to file");
        close(fd);
        return 0;
    }
    // printf("%s %s %s",student.name,student.emailId,student.password);
    close(fd);
    return 1;
}
int addFaculty(const char *name,const char *emailId,const char *password){
    struct Faculty faculty;
    strcpy(faculty.name,name);
    strcpy(faculty.password,password);
    strcpy(faculty.emailId,emailId);
    int fd = open("FacultyRecord.txt", O_WRONLY | O_CREAT | O_APPEND, 0600);
    if(fd==-1){
        error("File Error");
        return 0;
    }
    ssize_t bytes_written = write(fd, &faculty, sizeof(struct Faculty));
    if (bytes_written == -1) {
        error("Error writing to file");
        close(fd);
        return 0;
    }
    return 1;
}
#endif
