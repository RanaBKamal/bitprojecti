#ifndef LOGIN

#define LOGIN
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"
#include "delay.h"


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
		printf("Here we save user to a file\n");
		exit(0);
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