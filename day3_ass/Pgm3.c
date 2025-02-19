#include <stdio.h>
int main() {
int n, i, highest, lowest, sum = 0;
float average;
printf("Enter the number of matches: ");
scanf("%d", &n);
int scores[n];
printf("Enter scores of %d matches: ", n);
for (i = 0; i < n; i++) {
scanf("%d", &scores[i]);
sum += scores[i];
}
highest = lowest = scores[0];
for (i = 1; i < n; i++) {
if (scores[i] > highest)
highest = scores[i];
if (scores[i] < lowest)
lowest = scores[i];
}
average = (float)sum / n;
printf("\nHighest Score: %d", highest);
printf("\nLowest Score: %d", lowest);
printf("\nAverage Score: %.2f\n", average);
return 0;
}
