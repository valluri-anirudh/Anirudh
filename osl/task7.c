#include <stdio.h>
#include <stdlib.h>

int main() {
    int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
    /* Max denotes max required resource
       alloc denotes already allocated resources for each process
       avail denotes available resource of each kind
       completed array indicates whether each process has met with its requirements and completed
       or not.
       Safe sequence is an array which holds order of execution that can result in completion of all
       processes */

    int p, r, i, j, process, count;
    count = 0;

    printf("Enter the no of processes: ");
    scanf("%d", &p);

    for (i = 0; i < p; i++)
        completed[i] = 0; /* initially no process is completed */

    printf("\nEnter the no of resources: ");
    scanf("%d", &r);

    printf("\nEnter the Max Matrix for each process: ");
    for (i = 0; i < p; i++) {
        printf("\nFor process %d: ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }

    printf("\nEnter the allocation for each process: ");
    for (i = 0; i < p; i++) {
        printf("\nFor process %d: ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("\nEnter the Available Resources: ");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j]; // process still needs these many resources.

    do {
        printf("\n Max matrix:\tAllocation matrix:\n");
        for (i = 0; i < p; i++) {
            for (j = 0; j < r; j++)
                printf("%d ", Max[i][j]);
            printf("\t\t");
            for (j = 0; j < r; j++)
                printf("%d ", alloc[i][j]);
            printf("\n");
        }

        process = -1; // indicates process cannot be completed.
        for (i = 0; i < p; i++) {
            if (completed[i] == 0) { // if not completed.
                process = i; // ith process not yet completed.
                for (j = 0; j < r; j++) {
                    if (avail[j] < need[i][j]) {
                        process = -1; // excess required which is not possible
                        break;
                    }
                }
            }
            /* end if */
            if (process != -1)
                break; /* that means there exists a process that can complete its requirement */
        } /* for end */

        /* process holds i-th process which is not yet completed */
        if (process != -1) {
            printf("\nProcess %d runs to completion!", process);
            safeSequence[count] = process; /* join it to safe sequence */
            count++; // identifying number of completed processes

            for (j = 0; j < r; j++) {
                avail[j] += alloc[process][j]; /* return back the resources */
                alloc[process][j] = 0;
                Max[process][j] = 0;
            }
            completed[process] = 1;
        }
    } while (count != p && process != -1); /* for all processes */

    if (count == p) {
        printf("\nThe system is in a safe state!!\n");
        printf("Safe Sequence: < ");
        for (i = 0; i < p; i++)
            printf("%d ", safeSequence[i]);
        printf(">\n");
    } else {
        printf("\nThe system is in an unsafe state!!");
    }

    return 0;
}
