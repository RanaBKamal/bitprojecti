#include <stdio.h>
#include <stdlib.h>
#include "src/login.h"
#include "src/delay.h"


int main(){
	if (userExists() == 1)
	{
		printf("User exists\n");
	}else{
		clrscr();
		printf("%10s %20s", "", "No user Exist create one.");
		fflush(stdout);
		delay(2);
		showRegisterWindow();
	}
	showLoginWindow();
	if (checkCredential(USER.USERNAME, USER.PASSWORD) == 1)
	{
		printf("\n You are valid user \n");
	}else{
		printf("\n You are not valid user \n");
	}
	return 0;
}