#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNo;
    char name[50];
    char course[50];
    int marks;
};

void saveToFile(struct Student students[], int count) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d, %s, %s, %d\n", 
                students[i].rollNo, students[i].name, 
                students[i].course, students[i].marks);
    }
    fclose(file);
    printf("Record saved in \"students.txt\"\n");
}

void searchStudent(struct Student students[], int count, int rollNo) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Student Found: %s, %s, Marks: %d\n", 
                   students[i].name, students[i].course, students[i].marks);
            return;
        }
    }
    printf("Student with Roll No %d not found.\n", rollNo);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n, rollNo;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter details for Student %d (Roll No, Name, Course, Marks): ", i + 1);
        scanf("%d", &students[i].rollNo);
        getchar();
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        fgets(students[i].course, 50, stdin);
        students[i].course[strcspn(students[i].course, "\n")] = '\0';
        scanf("%d", &students[i].marks);
    }
    saveToFile(students, n);
    printf("Enter Roll No to search: ");
    scanf("%d", &rollNo);
    searchStudent(students, n, rollNo);
    return 0;
}
