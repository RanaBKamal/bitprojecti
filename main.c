#include <stdio.h>
#include <stdlib.h>
#include "src/login.h"
#include "src/delay.h"
#include "src/project.h"


int main(){
	if (userExists() != 1){
		clrscr();
		printf("%10s %20s", "", "No user Exist create one.");
		fflush(stdout);
		delay(2);
		showRegisterWindow();
	}
	loginAndRedirect();
	return 0;
}