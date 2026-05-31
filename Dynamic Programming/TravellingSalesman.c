#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 9999999
int n;
int **cost;
int **dp;
int tsp(int mask, int pos);
int main() {
    int i, j;
    printf("Enter the number of cities: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of cities.\n");
        return 1;
    }
    cost = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        cost[i] = (int *)malloc(n * sizeof(int));
    printf("Enter the cost matrix (Enter 0 or 9999999 for no direct path/self-loop):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    int num_states = 1 << n;
    dp = (int **)malloc(num_states * sizeof(int *));
    for (i = 0; i < num_states; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    int min_tour_cost = tsp(1, 0);
    printf("\nMinimum Traveling Salesman Tour Cost: %d\n", min_tour_cost);
    for (i = 0; i < num_states; i++)
        free(dp[i]);
    free(dp);
    for (i = 0; i < n; i++)
        free(cost[i]);
    free(cost);
    return 0;
}
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return cost[pos][0];
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    int min_cost = INF;
    for (int nxt = 0; nxt < n; nxt++) {
        if ((mask & (1 << nxt)) == 0) {
            int new_cost = cost[pos][nxt] + tsp(mask | (1 << nxt), nxt);
            if (new_cost < min_cost)
                min_cost = new_cost;
        }
    }
    return dp[mask][pos] = min_cost;
}
