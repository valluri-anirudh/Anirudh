#include <stdio.h>

struct process {
    char name[10];
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void main() {
    struct process p[10];
    int n, i;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &p[i].burst_time);
        printf(p[i].name, "P%d", i+1);
    }

    p[0].waiting_time = 0;
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }

    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    for (i = 0; i < n; i++) {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\n", p[i].name, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
}
