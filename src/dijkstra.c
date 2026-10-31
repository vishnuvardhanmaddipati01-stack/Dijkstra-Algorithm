#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main(void) {
    int n, graph[MAX][MAX], source;
    int dist[MAX], visited[MAX] = {0}, parent[MAX];

    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (0 means no edge; diagonal should be 0):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &graph[i][j]) != 1 || graph[i][j] < 0) {
                printf("Invalid edge weight. Use non-negative weights.\n");
                return 1;
            }
        }
    }

    printf("Enter source vertex (0-%d): ", n - 1);
    if (scanf("%d", &source) != 1 || source < 0 || source >= n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1, best = INF;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < best) {
                best = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);
    for (int v = 0; v < n; v++) {
        if (dist[v] == INF) {
            printf("To %d: unreachable\n", v);
        } else {
            int path[MAX], length = 0, current = v;
            while (current != -1 && length < MAX) {
                path[length++] = current;
                current = parent[current];
            }
            printf("To %d: distance = %d, path = ", v, dist[v]);
            for (int i = length - 1; i >= 0; i--) {
                printf("%d", path[i]);
                if (i > 0) printf(" -> ");
            }
            printf("\n");
        }
    }
    return 0;
}
