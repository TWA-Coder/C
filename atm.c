#include <stdio.h>
#include <string.h>
#include "atm.h"

/**
*login - login user account
*@User: username
*@user_count: pin(4-digits)
*
* Return: i when login is successfull / -1 if not
*/
int login(User users[], int user_count)
{
char input_name[MAX_NAME_LEN];
char input_pin[5];
int attempts = 3;


while (attempts--)
{
    printf("\nLogin\nUsername: ");
    scanf("%s", input_name);
    printf("PIN (4-digit): ");
    scanf("%s", input_pin);


    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(users[i].username, input_name) == 0 &&
            strcmp(users[i].pin, input_pin) == 0)
            {
            printf("Login successful. Welcome, %s!\n", users[i].username);
            return i;
        }
    }


    printf("Invalid credentials. Attempts left: %d\n", attempts);
}
return -1;
}

/**
*showMenu - displays the menu for the User in stdout & calls appropriete function
*@user: pointer to designated User
*/
void show_menu(User *user)
{
int choice;
do {
    printf("\n==== ATM Menu ====\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. View Transactions\n");
    printf("5. Logout\n");
    printf("Choose an option: ");
    scanf("%d", &choice);


    switch (choice)
    {
    case 1:
        check_balance(user);
        break;
    case 2:
        deposit(user);
        break;
    case 3:
        withdraw(user);
        break;
    case 4:
        view_transactions(user);
        break;
    case 5:
        printf("Logging out...\n");
        break;
    default:
        printf("Invalid option. Try again.\n");
    }
} while (choice != 5);
}
/**
*check_balance - Display the current balance to stdout
*@user - designated user
*/

void check_balance(User *user)
{
printf("Your current balance is: $%.2f\n", user->balance);
}
/**
*deposit - add amount to the user a/c and log the transaction
*@user -designated user
*/

void deposit(User *user)
{
float amount;
printf("Enter amount to deposit: ");
scanf("%f", &amount);
if (amount <= 0)
{
    printf("Invalid deposit amount.\n");
    return;
}
user->balance += amount;


char log[MAX_LOG_LEN];
snprintf(log, MAX_LOG_LEN, "Deposited: $%.2f", amount);
add_transaction(user, log);


printf("Deposit successful. New balance: $%.2f\n", user->balance);
}
/**
*withdraw - removes amount to the user a/c and log the transaction
*@user -designated user
*/

void withdraw(User *user)
{
float amount;
printf("Enter amount to withdraw: ");
scanf("%f", &amount);
if (amount <= 0)
{
    printf("Invalid withdrawal amount.\n");
    return;
}
if (amount > user->balance)
{
    printf("Insufficient balance.\n");
    return;
}
user->balance -= amount;


char log[MAX_LOG_LEN];
snprintf(log, MAX_LOG_LEN, "Withdrew: $%.2f", amount);
add_transaction(user, log);


printf("Withdrawal successful. New balance: $%.2f\n", user->balance);
}
/**
*view_transactions - list user logs in stdout
*@user -designated user
*/

void view_transactions(User *user)
{
printf("\n--- Transaction History ---\n");
if (user->transaction_count == 0) {
    printf("No transactions available.\n");
} else {
    int start = user->transaction_count > MAX_TRANSACTIONS ?
                user->transaction_count - MAX_TRANSACTIONS : 0;
    for (int i = start; i < user->transaction_count; i++) {
        printf("%s\n", user->transactions[i % MAX_TRANSACTIONS]);
    }
}
}
/**
*add_transaction - add to user log history
*@user: designated user
*@message: what happened on the a/c
*/

void add_transaction(User *user, const char *message)
{
int index = user->transaction_count % MAX_TRANSACTIONS;
strncpy(user->transactions[index], message, MAX_LOG_LEN - 1);
user->transactions[index][MAX_LOG_LEN - 1] = '\0';
user->transaction_count++;
}

