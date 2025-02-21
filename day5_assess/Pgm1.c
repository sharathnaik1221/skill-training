#include <stdio.h>
#include <string.h>

#define MAX_SEATS 2
#define MAX_QUEUE 5

typedef struct {
    char name[30];
} Passenger;

Passenger queue[MAX_QUEUE];
int front = -1, rear = -1;
int confirmed = 0;

void addReservation(char name[]) {
    if (confirmed < MAX_SEATS) {
        confirmed++;
        printf("Booking Confirmed: Passenger %d (%s)\n", confirmed, name);
    } else {
        if (rear == MAX_QUEUE - 1) {
            printf("Waiting List Full: Cannot add %s\n", name);
            return;
        }
        if (front == -1) front = 0;
        queue[++rear].name[0] = '\0';
        strcpy(queue[rear].name, name);
        printf("Waiting List: Passenger %d (%s)\n", rear - front + 1, name);
    }
}

void processNextBooking() {
    if (confirmed < MAX_SEATS && front <= rear && front != -1) {
        confirmed++;
        printf("Booking Confirmed: Passenger %d (%s)\n", confirmed, queue[front].name);
        front++;
        if (front > rear) front = rear = -1;
    }
}

void displayWaitingList() {
    if (front == -1) {
        printf("No Passengers in Waiting List\n");
        return;
    }
    printf("Waiting List:\n");
    for (int i = front; i <= rear; i++) {
        printf("Passenger %d: %s\n", i - front + 1, queue[i].name);
    }
}

int main() {
    addReservation("Alice");
    addReservation("Bob");
    addReservation("Charlie");
    addReservation("David");
    displayWaitingList();
    processNextBooking();
    processNextBooking();
    processNextBooking();
    displayWaitingList();
    return 0;
}
