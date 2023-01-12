#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

int cost[N][N] = {
    {10, 2, 6, 5},
    {1, 15, 12, 8},
    {7, 8, 9, 3},
    {15, 13, 4, 10}
};

int assigned[N];
int min_cost = INT_MAX;

int min(int a, int b) {
    return a < b ? a : b;
}

int unassigned(int n) {
    for (int i = 0; i < n; i++) {
        if (assigned[i] == -1) {
            return i;
        }
    }
    return -1;
}

void copy_assigned(int *temp, int n) {
    for (int i = 0; i < n; i++) {
        temp[i] = assigned[i];
    }
}

void assign(int worker, int task) {
    assigned[worker] = task;
}

int calculate_cost(int n) {
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        if (assigned[i] != -1) {
            total_cost += cost[i][assigned[i]];
        }
    }
    return total_cost;
}

void backtrack(int n, int current_cost) {
    int worker = unassigned(n);
    if (worker == -1) {
        min_cost = min(min_cost, current_cost);
        return;
    }
    for (int task = 0; task < n; task++) {
        if (current_cost + (n - worker - 1) * cost[worker][task] < min_cost) {
            assign(worker, task);
            backtrack(n, current_cost + cost[worker][task]);
            assigned[worker] = -1;
        }
    }
}

void solve_assignment_problem() {
    int temp[N];
    for (int i = 0; i < N; i++) {
        assigned[i] = -1;
    }
    backtrack(N, 0);
    printf("Minimum cost: %d\n", min_cost);
    printf("Optimal assignment: ");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i + 1, assigned[i] + 1);
    }
}

int main() {
    solve_assignment_problem();
    return 0;
}
