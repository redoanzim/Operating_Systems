//PREEMPTIVE VERSION
#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], p[n];
    int ct[n], tat[n], wt[n];

    // Input
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &p[i]);

        rt[i] = bt[i]; // remaining time
    }

    int time = 0, completed = 0;

    // Scheduling
    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MIN; // larger value = higher priority

        // Find highest priority process
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (p[i] > highest_priority) {
                    highest_priority = p[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            rt[idx]--;
            time++;

            // If process completes
            if (rt[idx] == 0) {
                completed++;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }
        } else {
            time++; // CPU idle
        }
    }

    // Calculate averages
    float total_wt = 0, total_tat = 0;

    printf("\nID\tAT\tBT\tP\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], p[i],
               ct[i], tat[i], wt[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }

    float avg_tat = total_tat / n;
    float avg_wt = total_wt / n;

    printf("\nAverage Turnaround Time = %.2f", avg_tat);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt);

    return 0;
}