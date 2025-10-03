#include <stdio.h>
#include "atm.h"
/*
*
*/
int main() {
   User users[MAX_USERS] = {
       {"alice", "1234", 1000.0, {0}, 0},
       {"bob", "4321", 1500.0, {0}, 0},
       {"charlie", "1111", 2000.0, {0}, 0}
   };


   printf("==== Welcome to the ATM System ====\n");


   while (1) {
       int user_index = login(users, MAX_USERS);
       if (user_index != -1) {
           showMenu(&users[user_index]);
       } else {
           printf("Too many failed attempts. Exiting.\n");
           break;
       }
   }


   return 0;
}

