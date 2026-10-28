#include <stdio.h>

struct Robot {
    int id;
    char type[30];
    float capacity, load, time;
};

int main() {
    int n, i;
    struct Robot r[10];

    printf("Enter number of robots: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for robot %d\n", i + 1);
        printf("Robot ID: ");
        scanf("%d", &r[i].id);
        
        printf("Robot Type: ");
        scanf(" %[^\n]", r[i].type);
        
        printf("Payload Capacity (kg): ");
        scanf("%f", &r[i].capacity);
        
        printf("Actual Load (kg): ");
        scanf("%f", &r[i].load);
        
        printf("Operating Time (hours): ");
        scanf("%f", &r[i].time);
    }

    // Border Lines Functionality
    #define BORDER "+----------+----------------------+------------+------------+-----------+-------------+--------------+"

    // Tabular Header
    printf("\n%s\n", BORDER);
    printf("| %-8s | %-20s | %-10s | %-10s | %-9s | %-11s | %-12s |\n", 
           "Robot ID", "Robot Type", "Capacity", "Load", "Op. Time", "Utilization", "Status");
    printf("%s\n", BORDER);

    // Tabular Data Rows
    for (i = 0; i < n; i++) {
        float util = (r[i].load / r[i].capacity) * 100;
        
        printf("| %-8d | %-20s | %-10.2f | %-10.2f | %-9.2f | %6.2f%%     | %-12s |\n", 
               r[i].id, 
               r[i].type, 
               r[i].capacity, 
               r[i].load, 
               r[i].time, 
               util, 
               (r[i].load > r[i].capacity) ? "Overloaded" : "Within Limit");
    }

    printf("%s\n", BORDER);

    return 0;
}
