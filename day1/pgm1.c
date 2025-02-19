#include <stdio.h>
int main() {
    int id;
    char name[255];
    int units;
    printf("Enter id:");
    scanf("%d", &id);
    printf("Enter name:");
    scanf("%s", name);
    printf("Enter total units consumed:");
    scanf("%d", &units);
    float base_amount = 100.0f;
    float surcharge = 0.0f;
    float total_amount = 0.0f;
    if(units > 300) {
        base_amount += (100.0f * 5.0f); 
        base_amount += (200.0f * 7.0f);
        base_amount += ((units - 300.0f) * 10.0f); 
    } else if(units > 100) {
        base_amount += (100.0f * 5.0f);
        base_amount += ((units - 200.0f) * 7.0f); 
    } else {
        base_amount += (units * 5.0f);
    }
    if(base_amount > 1000.0f) {
        surcharge = ((base_amount / 100.0f) * 5.0f);
    }
    total_amount = base_amount + surcharge;
    printf("EB Bill Details:\n");
    printf("\tCustomer Name: %s\n", name);  
    printf("\tCustomer ID: %d\n", id);  
    printf("\tUnits Consumed: %d\n", units);  
    printf("\tBase Bill: ₹%.2f\n", base_amount);
    if(surcharge > 0.0f) {
        printf("\tSurcharge: ₹%.2f\n", surcharge);
    }
    printf("\tTotal Bill: ₹%.2f\n", total_amount);

    return 0;
}
