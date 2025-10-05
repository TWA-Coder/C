#ifndef ATM_H
#define ATM_H

#define MAX_LOG_LEN 50
#define MAX_NAME_LEN 32
#define MAX_TRANSACTIONS 100
#define MAX_USERS 3

typedef struct {
   char username[MAX_NAME_LEN];
   char pin[5]; // 4-digit PIN + null terminator
   float balance;
   char transactions[MAX_TRANSACTIONS][MAX_LOG_LEN];
   int transaction_count;
} User;


// Core Functions
int login(User users[], int user_count);
void show_menu(User *user);
void check_balance(User *user);
void deposit(User *user);
void withdraw(User *user);
void view_transactions(User *user);
void add_transaction(User *user, const char *message);


#endif

