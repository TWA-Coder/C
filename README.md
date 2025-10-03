# ATM System in C

## Problem Statement
This project implements a simple **ATM System in C** that allows multiple predefined users to log in and perform basic banking operations. It simulates how an ATM interface works by handling login, checking balance, deposits, withdrawals, and transaction history.  

The program demonstrates the use of **variables, control structures, arrays, strings, and functions** while following a modular programming approach.  

---

## Assumptions
- The system supports a fixed number of users (`MAX_USERS = 3`) defined in the code.
- Each user has:
  - A username
  - A 4-digit PIN
  - An account balance
  - A transaction history log
- Login requires matching both username and PIN.
- Users are limited to 3 login attempts before being locked out.
- Transactions (deposit/withdraw) are stored in a circular log with a maximum of 100 entries.
- Input is assumed to be valid (e.g., numeric input where required).

---

## How to Compile and Run
1. Clone or download the repository.
2. Navigate to the folder containing the source files (`main.c`, `atm.c`, `atm.h`).
3. Compile the program using GCC:
   ```bash
   gcc main.c atm.c -o atm
