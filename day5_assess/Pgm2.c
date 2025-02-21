#include <stdio.h>
#include <string.h>

#define MAX_CALLS 5

typedef struct {
    int id;
    char name[30];
} Call;

Call queue[MAX_CALLS];
int front = -1, rear = -1;

void addCall(int id, char name[]) {
    if (rear == MAX_CALLS - 1) {
        printf("Call Queue Full: Cannot add Call %d from %s\n", id, name);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear].id = id;
    strcpy(queue[rear].name, name);
    printf("New Call Added: Call %d from %s\n", id, name);
}

void processCall() {
    if (front == -1) {
        printf("No Calls to Process\n");
        return;
    }
    printf("Processing Call: %d from %s\n", queue[front].id, queue[front].name);
    front++;
    if (front > rear) front = rear = -1;
}

void displayQueue() {
    if (front == -1) {
        printf("No Remaining Calls in Queue\n");
        return;
    }
    printf("Remaining Calls:\n");
    for (int i = front; i <= rear; i++) {
        printf("Call %d from %s\n", queue[i].id, queue[i].name);
    }
}

int main() {
    addCall(101, "Alice");
    addCall(102, "Bob");
    processCall();
    displayQueue();
    addCall(103, "Charlie");
    processCall();
    displayQueue();
    return 0;
}
