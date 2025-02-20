#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100

struct Weather {
    char city[50];
    int temperature;
    int humidity;
};

void saveToFile(struct Weather records[], int count) {
    FILE *file = fopen("weather_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s, %d°C, %d%%\n", 
                records[i].city, records[i].temperature, records[i].humidity);
    }
    fclose(file);
    printf("Data saved in \"weather_data.txt\"\n");
}

void searchCity(struct Weather records[], int count, char searchCity[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].city, searchCity) == 0) {
            printf("Weather in %s: %d°C, %d%% Humidity\n", 
                   records[i].city, records[i].temperature, records[i].humidity);
            return;
        }
    }
    printf("City %s not found in records.\n", searchCity);
}

int main() {
    struct Weather records[MAX_CITIES];
    int n;
    char searchCity[50];
    printf("Enter number of cities: ");
    scanf("%d", &n);
    getchar();  
    for (int i = 0; i < n; i++) {
        printf("Enter details for City %d (Name, Temperature, Humidity): ", i + 1);
        fgets(records[i].city, 50, stdin);
        records[i].city[strcspn(records[i].city, "\n")] = '\0';
        scanf("%d %d", &records[i].temperature, &records[i].humidity);
        getchar();  
    }
    saveToFile(records, n);
    printf("Enter city name to search: ");
    fgets(searchCity, 50, stdin);
    searchCity[strcspn(searchCity, "\n")] = '\0';
    searchCity(records, n, searchCity);
    return 0;
}
