#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX
void dijkstra(int **graph, int V, int src);
int minDistance(int dist[], int sptSet[], int V);
int main() {
    int V, i, j;
    printf("Enter the number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }
    int **graph = (int **)malloc(V * sizeof(int *));
    for (i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }
    printf("Enter the Adjacency Matrix (Enter 0 for no edge/self-loop):\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int source;
    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &source);
    dijkstra(graph, V, source);
    for (i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int **graph, int V, int src) {
    int *dist = (int *)malloc(V * sizeof(int));
    int *sptSet = (int *)calloc(V, sizeof(int));
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("\nVertex \t Distance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%d \t\t INF\n", i);
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
    free(dist);
    free(sptSet);
}
