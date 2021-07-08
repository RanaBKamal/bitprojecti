#ifndef LOGIN

#define LOGIN
#include "global.h"

void showLoginWindow(){
	printf("\n\n\n\n\n\n");
	printf("%10s %20s", "","Username : ");
	scanf("%s", USER.username);
	printf("%10s %20s", "","Password : ");
	scanf("%s", USER.password);
	printf("\n\n\n\n\n\n\n");
}



#endif