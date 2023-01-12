#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4
#define INF INT_MAX

int dist[V][V] = { { 0, 20, 42, 25 },
				   { 20, 0, 30, 34 },
				   { 42, 30, 0, 10 },
				   { 25, 34, 10, 0 } };

int visited[V];
int path[V];
int min_cost = INT_MAX;

void TSP(int city, int cost, int count) {
    if (count == V && dist[city][0])
    {
        min_cost = (min_cost, cost + dist[city][0]);
        return;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[city][i]) {
            visited[i] = 1;
            path[count] = i;
            TSP(i, cost + dist[city][i], count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    path[0] = 0;
    visited[0] = 1;
    TSP(0, 0, 1);
    printf("Minimum cost: %d\n", min_cost);

    printf("Optimal Path: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);

    return 0;
}
