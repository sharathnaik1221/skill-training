#include <stdio.h>
#include <string.h>
int main() {
int n, total = 0;
char vehicle[10];
scanf("%d", &n);
for (int i = 0; i < n; i++) {
scanf("%s", vehicle);
switch(vehicle[0]) {
case 'C': case 'c':
total += 50;
break;
case 'T': case 't':
total += 100;
break;
case 'B': case 'b':
if (strcmp(vehicle, "Bike") == 0 || strcmp(vehicle, "bike") == 0)
total += 20;
else
total += 80;
break;
}
}
printf("Total Toll Tax: %d", total);
return 0;
}
