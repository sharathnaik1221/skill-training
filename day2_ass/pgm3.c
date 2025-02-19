#include <stdio.h>
void atmTransaction(int choice, int *balance) {
int amount;
switch(choice) {
case 1:
printf("Enter Amount: ");
scanf("%d", &amount);
if (amount > 0 && amount <= *balance) {
*balance -= amount;
printf("Transaction Successful. Remaining Balance: ₹%d\n", *balance);
} else {
printf("Insufficient Balance or Invalid Amount!\n");
}
break;
case 2:
printf("Enter Amount: ");
scanf("%d", &amount);
if (amount > 0) {
*balance += amount;
printf("Transaction Successful. Updated Balance: ₹%d\n", *balance);
} else {
printf("Invalid Amount!\n");
}
break;
case 3:
printf("Current Balance: ₹%d\n", *balance);
break;
default:
printf("Invalid Choice! Please enter a valid option.\n");
}
}
int main() {
int balance = 10000;
int choice;
printf("ATM Transaction System\n");
printf("1. Withdraw Money\n");
printf("2. Deposit Money\n");
printf("3. Check Balance\n");
printf("Enter your choice: ");
scanf("%d", &choice);
atmTransaction(choice, &balance);
return 0;
}
