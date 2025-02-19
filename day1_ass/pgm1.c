#include <stdio.h>

int main() {
    int num_students, marks;
    
    
    printf("Enter number of students: ");
    scanf("%d", &num_students);
    
    
    for (int i = 1; i <= num_students; i++) {
        printf("Enter marks for Student %d: ", i);
        scanf("%d", &marks);
        
        
        printf("Student %d: Grade ", i);
        if (marks >= 90 && marks <= 100) {
            printf("A\n");
        } else if (marks >= 80) {
            printf("B\n");
        } else if (marks >= 70) {
            printf("C\n");
        } else if (marks >= 60) {
            printf("D\n");
        } else {
            printf("F\n");
        }
    }
    
    return 0;
}
