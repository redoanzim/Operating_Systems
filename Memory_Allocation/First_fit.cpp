#include <stdio.h>

// First Fit Function
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];

    // Initialize allocation as -1 (not allocated)
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    // Allocation process
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Print result
    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> ", i + 1);
        if (allocation[i] != -1)
            printf("Block %d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

// Main Function
int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    // Call First Fit
    firstFit(blockSize, m, processSize, n);

    return 0;
}