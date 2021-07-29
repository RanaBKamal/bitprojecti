#ifndef LOGIN

#define LOGIN
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "delay.h"
#include "project.h"

void showLoginWindow();
void showRegisterWindow();
int checkCredential(char usern[30], char passw[30]);
int userExists();
void loginAndRedirect(){
	if (LOGIN_ATTEMPT >= MAX_LOGIN_ATTEMPT)
	{
		printf("%10s %20s", "","Max attempt reached. Wait for 500s");
		fflush(stdout);
		delay(500);
	}
	++LOGIN_ATTEMPT;
	showLoginWindow();
	if (checkCredential(USER.USERNAME, USER.PASSWORD) == 1)
	{
		printf("\n You are valid user \n");
		fflush(stdout);
		delay(2);

		/*
			All the project works that needs user authentication goes here

		*/
		startProjectTasks();
		getch();
	}else{
		printf("\n You are not valid user \n");
		fflush(stdout);
		delay(2);
		loginAndRedirect();
	}
}


/*
	function to show login window
*/
void showLoginWindow(){
	char ch;
	int i = 0;
	clrscr();
	printf("\n\n\n\n\n\n");
	printf("%10s %20s", "","Username : ");
	scanf(" %s", USER.USERNAME);
	printf("%10s %20s", "","Password : ");
	getch();
	ch = getch();
	while(ch != '\n'){
		USER.PASSWORD[i] = ch;
		++i;
		printf("*");
		ch = getch();
	}
	USER.PASSWORD[i] = '\0';
	printf("\n\n\n\n\n\n\n");
}
/*
	function to display register window
*/
void showRegisterWindow(){
	User tempUser;
	char ch, tempPassword[30];
	int i = 0;
	clrscr();
	printf("\n\n\n\n");
	printf("%10s %20s", "", "Create User\n\n");
	printf("%10s %20s", "","Username : ");
	scanf(" %s", tempUser.USERNAME);
	printf("%10s %20s", "","Password : ");
	getch();
	ch = getch();
	while(ch != '\n'){
		tempUser.PASSWORD[i] = ch;
		++i;
		printf("*");
		ch = getch();
	}
	tempUser.PASSWORD[i] = '\0';
	printf("%10s %20s", "","Confirm Password : ");
	i = 0;
	ch = getch();
	while(ch != '\n'){
		tempPassword[i] = ch;
		++i;
		printf("*");
		ch = getch();
	}
	tempPassword[i] = '\0';
	if (strcmp(tempUser.PASSWORD, tempPassword) == 0)
	{
		FILE *user_filep;
		user_filep = fopen(USER_FILE, "ab");
		if (user_filep == NULL)
		{
			printf("Error adding user to a file.\n\n");
			exit(0);
		}
		if (userExists() == 1)
		{
			tempUser.USER_TYPE = USER_NORMAL;
		}else{
			tempUser.USER_TYPE = USER_ADMIN;
		}
		fwrite(&tempUser, sizeof(tempUser), 1, user_filep);
		printf("%10s %20s", "", "User successfully saved\n\n");
		fclose(user_filep);
		fflush(stdout);
		delay(2);
		loginAndRedirect();

	}else{
		clrscr();
		printf("%10s %20s", "", "Password did not match, Try again\n\n");
		fflush(stdout);
		delay(2);
		showRegisterWindow();
	}
	printf("\n\n\n\n\n\n\n");
}



/*
	function to check if credential matches
*/

int checkCredential(char usern[30], char passw[30]){
	FILE *user_filep;
	User TempUSER;
	user_filep = fopen(USER_FILE, "rb");
	if (user_filep == NULL)
	{
		clrscr();
		printf("\nFailed to open a file\n");
		exit(0);
	}
	while(!feof(user_filep)){
		fread(&TempUSER, sizeof(TempUSER), 1, user_filep);

		if ((strcmp(usern, TempUSER.USERNAME) == 0) && (strcmp(passw, TempUSER.PASSWORD) == 0))
		{
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
} 

/*
	function to check if user exists
*/
int userExists(){
	FILE *tempFile;
	User tempUser;
	int cursorPos;
	tempFile = fopen(USER_FILE, "rb");
	if (tempFile == NULL)
	{
		clrscr();
		printf("\nFailed to open a file\n");
		exit(0);
	}
	fseek(tempFile, 0, SEEK_END);
	cursorPos = ftell(tempFile);
	fclose(tempFile);
	if (cursorPos <= 1)
	{
		return 0;
	}else{
		return 1;
	}
}

#endif