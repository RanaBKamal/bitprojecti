#ifndef GLOBAL

#define GLOBAL
typedef struct user{
	int user_type;//if 1-admin, else other
	char USERNAME[30];
	char PASSWORD[30];
}User;
User USER;

const char USER_FILE[30] = "user_file.dat";

#endif