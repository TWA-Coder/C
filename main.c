#include <stdio.h>
#include "atm.h"
/*
*main - Entry of the program contains user a/c
*
*Return: zero when the program runs successfully
*/
int main(void)

{
User users[MAX_USERS] = {
{"arisene", "1234", 1000.0, {0}, 0},
{"stecie", "4321", 1500.0, {0}, 0},
{"bot", "1111", 2000.0, {0}, 0}
};


printf("==== Welcome to the ATM System ====\n");


while (1)
{
int user_index = login(users, MAX_USERS);
if (user_index != -1)
{
show_menu(&users[user_index]);
}
else
{
printf("Too many failed attempts. Exiting.\n");
break;
}
}


return (0);
}

