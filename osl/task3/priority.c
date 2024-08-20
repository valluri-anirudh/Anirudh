#include <stdio.h>

struct sq {
    char pro[10];
    int bt, wt, prior, tat;
} P[10], temp;

int main() {
    int i, j, n, temp1 = 0;
    float awt = 0, atat = 0;

    printf("Enter number of processes ::\n");
    scanf("%d", &n);
    
    printf("Enter name, burst time, priority ::\n");
    for (i = 0; i < n; i++) {
        scanf("%s%d%d", P[i].pro, &P[i].bt, &P[i].prior);
    }

    // Sorting processes based on priority
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (P[i].prior > P[j].prior) {
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }

    // Calculating waiting time and turn around time for each process
    for (i = 0; i < n; i++) {
        P[i].wt = temp1;
        P[i].tat = P[i].wt + P[i].bt;
        temp1 += P[i].bt;
    }

    // Calculating average waiting time and turn around time
    for (i = 0; i < n; i++) {
        awt += P[i].wt;
        atat += P[i].tat;
    }
    awt /= n;
    atat /= n;

    // Printing process details
    printf("Process\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\n", P[i].pro, P[i].bt, P[i].wt, P[i].tat);
    }
    printf("Average Waiting Time = %f\n", awt);
    printf("Average Turn Around Time = %f\n", atat);

    return 0;
}
