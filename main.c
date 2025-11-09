#include <stdio.h>
#include <limits.h>

#define INF 99999
#define MAX 100

int V;
int graph[MAX][MAX];

// Recursive DFS to print all possible paths (with weights)
void printAllPathsUtil(int u, int d, int visited[], int path[], int path_index, int cost) {
    visited[u] = 1;
    path[path_index] = u;
    path_index++;

    if (u == d) {
        printf("Path: ");
        for (int i = 0; i < path_index - 1; i++) {
            printf("%d(%d) -> ", path[i], graph[path[i]][path[i + 1]]);
        }
        printf("%d \t(Cost = %d)\n", path[path_index - 1], cost);
    } else {
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0) {
                printAllPathsUtil(v, d, visited, path, path_index, cost + graph[u][v]);
            }
        }
    }
    path_index--;
    visited[u] = 0;
}

// Prints all paths from source to all nodes
void printAllPaths(int s) {
    int visited[MAX] = {0};
    int path[MAX];
    printf("\n----------------------------------------\n");
    printf("All Possible Paths from Source %d:\n", s);
    for (int dest = 0; dest < V; dest++) {
        if (dest != s)
            printAllPathsUtil(s, dest, visited, path, 0, 0);
    }
    printf("----------------------------------------\n");
}

// Print shortest path with weights
void printWeightedPath(int parent[], int dest) {
    if (parent[dest] == -1) {
        printf("%d", dest);
        return;
    }
    printWeightedPath(parent, parent[dest]);
    printf(" -> %d(%d)", dest, graph[parent[dest]][dest]);
}

// Dijkstra Algorithm
void dijkstra(int graph[MAX][MAX], int src, int dist[], int parent[]) {
    int visited[MAX] = {0};
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, u = -1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], u = v;

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

// Bellman–Ford Algorithm
void bellmanFord(int edges[MAX][3], int E, int src, int dist[], int parent[]) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle!\n");
            return;
        }
    }
}

int main() {
    int E, src, dest;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int edges[MAX][3];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);
    printAllPaths(src);

    int distD[MAX], parentD[MAX];
    int distB[MAX], parentB[MAX];

    dijkstra(graph, src, distD, parentD);
    bellmanFord(edges, E, src, distB, parentB);

    printf("\n=========== Dijkstra's Algorithm ===========\n");
    printf("Vertex\tDistance\tPath (with weights)\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t", i, distD[i]);
        printWeightedPath(parentD, i);
        printf("\n");
    }

    printf("\n=========== Bellman-Ford Algorithm ===========\n");
    printf("Vertex\tDistance\tPath (with weights)\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t", i, distB[i]);
        printWeightedPath(parentB, i);
        printf("\n");
    }

    printf("----------------------------------------\n");
    printf("Enter destination vertex for final result: ");
    scanf("%d", &dest);

    if (distD[dest] == INF || distB[dest] == INF) {
        printf("No path exists from %d to %d\n", src, dest);
    } else {
        printf("\n********** FINAL RESULT **********\n");
        printf("Source: %d\tDestination: %d\n", src, dest);

        printf("Shortest Distance (Dijkstra) = %d\n", distD[dest]);
        printf("Shortest Distance (Bellman-Ford) = %d\n\n", distB[dest]);

        printf("Final Shortest Path (with weights): ");
        printWeightedPath(parentD, dest);
        printf("\n");

        if (distD[dest] == distB[dest])
            printf("(Result verified by both algorithms ✅)\n");
        else
            printf("(⚠️ Results differ — check for negative weights)\n");
    }

    printf("----------------------------------------\n");
    printf("Program Completed Successfully.\n");
    return 0;
}
