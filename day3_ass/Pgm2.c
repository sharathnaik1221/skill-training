#include <stdio.h>
#include <string.h>
void findPattern(char dna[], char pattern[]) {
int count = 0;
int dnaLen = strlen(dna);
int patternLen = strlen(pattern);
for (int i = 0; i <= dnaLen - patternLen; i++) {
if (strncmp(&dna[i], pattern, patternLen) == 0) {
count++;
}
}
printf("Pattern found %d time(s) in the DNA sequence.\n", count);
}
int main() {
char dna[100], pattern[20];
printf("Enter DNA Sequence: ");
scanf("%s", dna);
printf("Enter pattern to search: ");
scanf("%s", pattern);
findPattern(dna, pattern);
return 0;
}
