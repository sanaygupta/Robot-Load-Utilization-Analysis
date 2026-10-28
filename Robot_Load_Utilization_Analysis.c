#include <stdio.h>
#include <string.h>

#define MAX 100

struct Robot {
    int id;
    char type[30];
    float capacity;      /* payload capacity */
    float load;          /* actual load */
    float opTime;        /* operating time (hours) */
    float utilization;   /* load utilization % */
    char status[15];     /* Overloaded / Within Limit */
};

/* Input buffer me bacha hua newline/extra characters saaf karta hai */
void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Valid integer lene ke liye (min se max ke beech) */
int readInt(const char *prompt, int min, int max) {
    int val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &val) == 1 && val >= min && val <= max) {
            clearBuffer();
            return val;
        }
        printf("Invalid input! %d se %d ke beech number daalo.\n", min, max);
        clearBuffer();
    }
}

/* Valid float lene ke liye (min se bada ya barabar) */
float readFloat(const char *prompt, float min) {
    float val;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &val) == 1 && val >= min) {
            clearBuffer();
            return val;
        }
        printf("Invalid input! %.2f ya usse bada number daalo.\n", min);
        clearBuffer();
    }
}

int main() {
    struct Robot r[MAX];
    int n, i;

    n = readInt("Enter the number of robots: ", 1, MAX);

    for (i = 0; i < n; i++) {
        printf("\n--- Robot %d ---\n", i + 1);

        /* Robot ID - alag line */
        r[i].id = readInt("Enter robot ID: ", 1, 999999);

        /* Robot type - alag line (space allowed) */
        printf("Enter robot type: ");
        fgets(r[i].type, sizeof(r[i].type), stdin);
        r[i].type[strcspn(r[i].type, "\n")] = '\0';

        /* Capacity (capacity 0 nahi ho sakti, kyunki divide karna hai) */
        do {
            r[i].capacity = readFloat("Enter payload capacity (kg): ", 0);
            if (r[i].capacity == 0)
                printf("Capacity 0 nahi ho sakti!\n");
        } while (r[i].capacity == 0);

        /* Load */
        r[i].load = readFloat("Enter actual load (kg): ", 0);

        /* Operating time */
        r[i].opTime = readFloat("Enter operating time (hours): ", 0);

        /* Load utilization = (load / capacity) x 100 */
        r[i].utilization = (r[i].load / r[i].capacity) * 100;

        /* If load > capacity -> Overloaded, else Within Limit */
        if (r[i].load > r[i].capacity)
            strcpy(r[i].status, "Overloaded");
        else
            strcpy(r[i].status, "Within Limit");
    }

    /* Tabular output */
    printf("\n");
    printf("+----------+----------------------+------------+----------+----------+-------------+--------------+\n");
    printf("| %-8s | %-20s | %-10s | %-8s | %-8s | %-11s | %-12s |\n",
           "Robot ID", "Robot Type", "Capacity", "Load", "Op. Time", "Utilization", "Status");
    printf("+----------+----------------------+------------+----------+----------+-------------+--------------+\n");

    for (i = 0; i < n; i++) {
        printf("| %-8d | %-20s | %-10.2f | %-8.2f | %-8.2f | %10.2f%% | %-12s |\n",
               r[i].id, r[i].type, r[i].capacity, r[i].load,
               r[i].opTime, r[i].utilization, r[i].status);
    }

    printf("+----------+----------------------+------------+----------+----------+-------------+--------------+\n");

    return 0;
}
