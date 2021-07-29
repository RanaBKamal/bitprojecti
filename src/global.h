#ifndef GLOBAL

#define GLOBAL
typedef struct user{
	int USER_TYPE;//if 1-admin, else other
	char USERNAME[30];
	char PASSWORD[30];
}User;
User USER;

const int USER_ADMIN = 1;
const int USER_NORMAL = 2;

const char USER_FILE[30] = "user_file.dat";
static short int LOGIN_ATTEMPT = 0;
const short int MAX_LOGIN_ATTEMPT = 5;

#endif