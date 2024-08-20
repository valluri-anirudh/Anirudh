#include <stdio.h>

struct sa {
    char pro[10];
    int bt, wt, tat;
} p[10], temp[10];

void main() {
    int i, j, n, temp1 = 0;
    float awt = 0, atat = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process name and burst time:\n");
    for (i = 0; i < n; i++) {
        scanf("%s %d", p[i].pro, &p[i].bt);
    }

    // Sorting processes based on burst time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].bt > p[j].bt) {
                temp[0] = p[i];
                p[i] = p[j];
                p[j] = temp[0];
            }
        }
    }

    // Calculating waiting time and turn around time for each process
    for (i = 0; i < n; i++) {
        p[i].wt = temp1;
        p[i].tat = p[i].bt + p[i].wt;
        temp1 += p[i].bt;
    }

    // Calculating average waiting time and turn around time
    for (i = 0; i < n; i++) {
        awt += p[i].wt;
        atat += p[i].tat;
    }
    awt /= n;
    atat /= n;

    // Printing process details
    printf("Process\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%5s\t%5d\t%5d\t%5d\n", p[i].pro, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %f", awt);
    printf("\nAverage Turn Around Time: %f", atat);
}
