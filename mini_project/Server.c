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
#include "Login.h"
#include "Takeinfo.h"
#include "Delete.h"
/*
username:adminiiitb@gmail.com
password:IIITB
*/
/*
Name of Student: Sudhanshu 
Roll No of Student: MT2023131
Email Id of Student: sudhanshu@iiitb
Password of Student: Sudha123
Name of Student: Khushbu
Roll No of Student: MT2023121
Email Id of Student: Khushbu@iiitb     
Password of Student: Khush123
*/
/*
Name of Faculty: Ganesh
Email Id of Faculty: ganesh@iiitb.ac.in
Password of Faculty: Ganesh123
Name of Faculty: Dishang
Email Id of Faculty: dishang@iiitb.ac.in
Password of Faculty: Dishang123
*/
int main(){
	MainMenu();
	int login_as;
	scanf("%d",&login_as);
	switch (login_as)
	{
	case 1:
		printf("Please provide Information\n");
		{
		int isOK=AdminLogin();
		if(isOK!=1){
			break;
		}
		while(1){
		AdminMenu();
		int choice;
		scanf("%d",&choice);
		//Add Student
		switch(choice){
			case 1:takeStudentInfo();
			break;
			case 2:searchStudent();
			break;
			case 3:takeFacultyInfo();
			break;
			case 4:searchFaculty();
			break;
			case 5:activateStudent();
			break;
			case 6:deactivateStudent();
			break;
			case 9: break;
			default:
			break;
		}
		if(choice==9){
			break;
		}
		}
		}
		break;
	case 2:
		printf("Please provide Information\n");
		{
			FacultyLogin();
		}
		break;
	case 3:
		printf("Please provide Information\n");
		{
		StudentLogin();
		}
		break;	
	default:
		break;
	}
	return 0;
}
