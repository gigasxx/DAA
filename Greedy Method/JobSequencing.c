#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char id;
    int deadline;
    int profit;
} Job;
void jobSequencing(Job jobs[], int n);
void sortJobsByProfit(Job jobs[], int n);
int main() {
    int n, i;
    printf("Enter number of jobs: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of jobs.\n");
        return 1;
    }
    Job *jobs = (Job *)malloc(n * sizeof(Job));
    if (jobs == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter Job Details (ID Deadline Profit):\n");
    for (i = 0; i < n; i++)
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    jobSequencing(jobs, n);
    free(jobs);
    return 0;
}
void sortJobsByProfit(Job jobs[], int n) {
    int i, j;
    Job temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}
void jobSequencing(Job jobs[], int n) {
    int i, j;
    sortJobsByProfit(jobs, n);
    int maxDeadline = 0;
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }
    char *slot = (char *)malloc((maxDeadline + 1) * sizeof(char));
    int *filled = (int *)calloc((maxDeadline + 1), sizeof(int));
    int totalProfit = 0;
    int countJobs = 0;
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline; j > 0; j--) {
            if (filled[j] == 0) {
                slot[j] = jobs[i].id;
                filled[j] = 1;
                totalProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }
    printf("\nScheduled Jobs Sequence: ");
    for (i = 1; i <= maxDeadline; i++) {
        if (filled[i]) {
            printf("%c ", slot[i]);
        }
    }
    printf("\nTotal Scheduled Jobs: %d", countJobs);
    printf("\nMaximum Profit: %d\n", totalProfit);
    free(slot);
    free(filled);
}
