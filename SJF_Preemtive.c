#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, time = 0, smallest;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20], res[20];
    int completed = 0;
    int finish_time;
    int minm = INT_MAX;
    int check = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d AT BT: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];      
        res[i] = -1;        
    }

    while(completed != n) {

        minm = INT_MAX;
        check = 0;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] < minm && rt[i] > 0) {
                minm = rt[i];
                smallest = i;
                check = 1;
            }
        }

        if(check == 0) {
            time++;
            continue;
        }

        if(res[smallest] == -1)
            res[smallest] = time - at[smallest];

        rt[smallest]--;

        minm = rt[smallest];
        if(minm == 0)
            minm = INT_MAX;

        if(rt[smallest] == 0) {
            completed++;
            finish_time = time + 1;

            ct[smallest] = finish_time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
        }

        time++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i], res[i]);
    }

    return 0;
}