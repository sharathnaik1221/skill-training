#include <stdio.h>

int main() {
    int units;
    int bill = 0;
    printf("Enter units consumed: ");
    scanf("%d", &units);
    if (units <= 100) {
        bill = units * 2;
    } else if (units <= 200) {
        bill = (100 * 2) + ((units - 100) * 3);
    } else {
        bill = (100 * 2) + (100 * 3) + ((units - 200) * 5);
    } 
    printf("Total Bill: ₹%d\n", bill);
    return 0;
}
