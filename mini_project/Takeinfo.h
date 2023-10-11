#ifndef TAKEINFO_H
#define TAKEINFO_H
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
void takeStudentInfo(){
    char name[100],rollno[100],emailId[100],password[100];
			printf("Name of Student: ");
			scanf("%s",name);
			printf("Roll No of Student: ");
			scanf("%s",rollno);
			printf("Email Id of Student: ");
			scanf("%s",emailId);
			printf("Password of Student: ");
			scanf("%s",password);
			if(addStudent(name,rollno,emailId,password)==1){
				printf("Successfully Added Student!\n");
			}
			else{
				printf("Error\n");
			}
}
void searchStudent(){
    char emailId[100];
			printf("Email Id of the Student : ");
			scanf("%s",emailId);
			struct Student student,user;
			int fd=open("StudentRecord.txt",O_RDONLY);
			char ch='t';
			while (read(fd, &user, sizeof(user)) > 0) {
		// printf("emailId: %s",user.emailId);
		// printf("password: %s",user.password);
        	if (strcmp(emailId, user.emailId)==0) {
				student=user;
				ch='f';
                printf("###################################################################\n");
				printf("Student Name:%s\n",student.name);
				printf("Student RollNo:%s\n",student.rollno);
				printf("Student emailId:%s\n",student.emailId);
				printf("Student status:%d\n",student.status);
                printf("###################################################################\n");
				close(fd);// Authentication successful
        	}
    		}
			if(ch=='t')
			printf("No Record Found!\n");
}
void takeFacultyInfo(){
    char name[100],emailId[100],password[100];
			printf("Name of Faculty: ");
			scanf("%s",name);
			printf("Email Id of Faculty: ");
			scanf("%s",emailId);
			printf("Password of Faculty: ");
			scanf("%s",password);
			if(addFaculty(name,emailId,password)==1){
				printf("Successfully Added Faculty!\n");
			}
			else{
				error("Error\n");
			}
}
void searchFaculty(){
    char emailId[100];
			printf("Email Id of the Faculty : ");
			scanf("%s",emailId);
			struct Faculty faculty,user;
			int fd=open("FacultyRecord.txt",O_RDONLY);
			char ch='t';
			while (read(fd, &user, sizeof(user)) > 0) {
		// printf("emailId: %s",user.emailId);
		// printf("password: %s",user.password);
        	if (strcmp(emailId, user.emailId)==0) {
				faculty=user;
				ch='f';
                printf("###################################################################\n");
				printf("Faculty Name:%s\n",faculty.name);
				printf("Faculty emailId:%s\n",faculty.emailId);
                printf("###################################################################\n");
				close(fd);// Authentication successful
        	}
    		}
			if(ch=='t')
			printf("No Record Found!\n");
}
#endif
