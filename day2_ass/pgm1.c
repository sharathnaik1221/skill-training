#include <stdio.h>
#include <string.h>
int check_insurance(int age, char condition[], int salary) {
if(age >= 18 && age <= 60 && strcmp(condition, "no") == 0 && salary >= 25000)
return 1;
return 0;
}
int main() {
int age, salary;
char condition[4];
printf("Enter Age: ");
scanf("%d", &age);
printf("Any Pre-existing Condition? (yes/no): ");
scanf("%s", condition);
printf("Enter Monthly Salary: ");
scanf("%d", &salary);
if(check_insurance(age, condition, salary))
printf("Eligible for Medical Insurance");
else
printf("Not Eligible for Medical Insurance");
return 0;
}
