#include <stdio.h>

int main() {
    int n, a[10], b[10], wt[10], tat[10], i;
    float awt = 0, att = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + b[i - 1];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + b[i];
        awt += wt[i];
        att += tat[i];
    }

    awt /= n;
    att /= n;

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t\t%d\t\t%d\n", i + 1, wt[i], tat[i]);
    }

    printf("The average waiting time is %f\n", awt);
    printf("The average turnaround time is %f\n", att);

    return 0;
}