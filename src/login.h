#ifndef LOGIN

#define LOGIN
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"

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

#endif