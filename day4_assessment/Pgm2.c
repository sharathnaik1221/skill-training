#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100

struct Order {
    int orderID;
    char customerName[50];
    char product[50];
    int amount;
};

void saveToFile(struct Order orders[], int count) {
    FILE *file = fopen("orders.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d, %s, %s, ₹%d\n", 
                orders[i].orderID, orders[i].customerName, 
                orders[i].product, orders[i].amount);
    }
    fclose(file);
    printf("Record saved in \"orders.txt\"\n");
}

void searchOrder(struct Order orders[], int count, int orderID) {
    for (int i = 0; i < count; i++) {
        if (orders[i].orderID == orderID) {
            printf("Order Found: %s - %s - ₹%d\n", 
                   orders[i].customerName, orders[i].product, orders[i].amount);
            return;
        }
    }
    printf("Order with ID %d not found.\n", orderID);
}

int main() {
    struct Order orders[MAX_ORDERS];
    int n, orderID;
    printf("Enter number of orders: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter details for Order %d (Order ID, Customer Name, Product, Amount): ", i + 1);
        scanf("%d", &orders[i].orderID);
        getchar();
        fgets(orders[i].customerName, 50, stdin);
        orders[i].customerName[strcspn(orders[i].customerName, "\n")] = '\0';
        fgets(orders[i].product, 50, stdin);
        orders[i].product[strcspn(orders[i].product, "\n")] = '\0';
        scanf("%d", &orders[i].amount);
    }
    saveToFile(orders, n);
    printf("Enter Order ID to search: ");
    scanf("%d", &orderID);
    searchOrder(orders, n, orderID);
    return 0;
}
