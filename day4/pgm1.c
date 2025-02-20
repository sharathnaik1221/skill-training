#include <stdio.h>
struct employee_t{
    int id;
    char name[250];
    float salary;
    char department[50];
};
typedef struct employee_t employee;

void reademployees(employee emp[],int n);
void displayemployees(employee emp[],int n);
employee findhighestsalaried(employee emp[],int n);

int main(){
    int employeecount;
    printf("Enter number of employees:");
    scanf("%d",&employeecount);
    
    employee employees[1000];
    reademployees(employees,employeecount);
    displayemployees(employees,employeecount);
    employee highestsalaried = findhighestsalaried(employees,employeecount);
    printf("Employee with highest salary: %s,%.2f (%s)\n",highestsalaried.name,highestsalaried.salary,highestsalaried.department);
    return 0;
}

void reademployees(employee emp[],int n){
    printf("Enter the details (ID,Name,Salary,Department):");
    for(int i=0;i<n;i++){
        scanf("%d %s %f %s",&emp[i].id, emp[i].name,&emp[i].salary,emp[i].department);
    }
}
void displayemployees(employee emp[],int n){
    printf("Employees:\n");
    for(int i=0;i<n;i++){
        printf("%d - %s - %.2f - %s\n",emp[i].id, emp[i].name,emp[i].salary,emp[i].department);
    }
}
employee findhighestsalaried(employee emp[],int n){
    employee maxemployee = emp[0];
     for(int i=0;i<n;i++){
         if(emp[i].salary>maxemployee.salary){
             maxemployee = emp[i];
         }
     }
     return maxemployee;
}
