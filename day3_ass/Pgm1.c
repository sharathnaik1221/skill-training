#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
char name[50];
int age;
char destination[50];
} Passenger;
void sortPassengers(Passenger p[], int n) {
Passenger temp;
for (int i = 0; i < n - 1; i++) {
for (int j = i + 1; j < n; j++) {
if (strcmp(p[i].destination, p[j].destination) > 0) {
temp = p[i];
p[i] = p[j];
p[j] = temp;
}
}
}
}
void searchPassengers(Passenger p[], int n, char dest[]) {
int found = 0;
for (int i = 0; i < n; i++) {
if (strcmp(p[i].destination, dest) == 0) {
printf("%s\n", p[i].name);
found = 1;
}
}
if (!found) {
printf("No passengers traveling to %s\n", dest);
}
}
int main() {
int n;
Passenger passengers[MAX];
printf("Enter number of passengers: ");
scanf("%d", &n);
for (int i = 0; i < n; i++) {
printf("Passenger %d: ", i + 1);
scanf("%s %d %s", passengers[i].name, &passengers[i].age,
passengers[i].destination);
}
sortPassengers(passengers, n);
printf("\nSorted List (by destination):\n");
for (int i = 0; i < n; i++) {
printf("%s • %s\n", passengers[i].name, passengers[i].destination);
}
char searchDest[50];
printf("\nEnter destination to search: ");
scanf("%s", searchDest);
printf("Passengers traveling to %s:\n", searchDest);
searchPassengers(passengers, n, searchDest);
return 0;
}
