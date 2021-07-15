#include <stdio.h>
#include "src/login.h"


int main(){
	showLoginWindow();
	if (checkCredential(USER.USERNAME, USER.PASSWORD) == 1)
	{
		printf("\n You are valid user \n");
	}else{
		printf("\n You are not valid user \n");
	}
	return 0;
}