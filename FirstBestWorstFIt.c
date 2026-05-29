#include <stdio.h>

#define MAX 10

// 1. First-Fit Allocation
void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    // Initialize all allocations as -1 (Not Allocated)
    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;
                // Reduce available memory in this block
                blockSize[j] -= processSize[i];
                // Move to the next process
                break;
            }
        }
    }

    printf("\n--- First-Fit Allocation ---\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n", i + 1, processSize[i]);
    }
}

// 2. Best-Fit Allocation
void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processes; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // If a suitable block was found
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\n--- Best-Fit Allocation ---\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n", i + 1, processSize[i]);
    }
}

// 3. Worst-Fit Allocation
void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[MAX];

    for (int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < processes; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        // If a suitable block was found
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\n--- Worst-Fit Allocation ---\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d of size %d -> Block %d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("Process %d of size %d -> Not Allocated\n", i + 1, processSize[i]);
    }
}

int main() {
    int blockSize[MAX], processSize[MAX], blocks, processes, choice;
    int originalBlockSize[MAX];

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);

    printf("Enter size of each block:\n");
    for (int i = 0; i < blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
        originalBlockSize[i] = blockSize[i];
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &processes);

    printf("Enter size of each process:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    printf("\nMemory Allocation Techniques:\n");
    printf("1. First Fit\n2. Best Fit\n3. Worst Fit\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            firstFit(blockSize, blocks, processSize, processes);
            break;
        case 2:
            bestFit(blockSize, blocks, processSize, processes);
            break;
        case 3:
            worstFit(blockSize, blocks, processSize, processes);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
