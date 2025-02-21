#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient {
    int id;
    char name[30];
    struct Patient *prev, *next;
} Patient;

Patient *head = NULL;

void addPatient(int id, char name[]) {
    Patient *newPatient = (Patient *)malloc(sizeof(Patient));
    newPatient->id = id;
    strcpy(newPatient->name, name);
    newPatient->prev = newPatient->next = NULL;

    if (head == NULL) {
        head = newPatient;
    } else {
        Patient *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
        newPatient->prev = temp;
    }
    printf("New Patient Admitted: %s (ID %d)\n", name, id);
}

void dischargePatient(int id) {
    Patient *temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Patient with ID %d not found.\n", id);
        return;
    }

    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp == head) head = temp->next;

    printf("Discharging: %s\n", temp->name);
    free(temp);
}

void displayPatients() {
    if (head == NULL) {
        printf("No Patients in Hospital\n");
        return;
    }
    Patient *temp = head;
    printf("Remaining Patients: ");
    while (temp != NULL) {
        printf("%s", temp->name);
        if (temp->next != NULL) printf(" ↔ ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    addPatient(201, "John");
    addPatient(202, "Mary");
    addPatient(203, "David");

    dischargePatient(202);
    displayPatients();
    
    return 0;
}
