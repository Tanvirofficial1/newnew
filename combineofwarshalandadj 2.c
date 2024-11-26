#include <stdio.h>
#define INF 99
#define MAX 100

void warshal(int g[][MAX], int v) {
    int dist[MAX][MAX];

    // Copy graph into dist matrix
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            dist[i][j] = g[i][j];
        }
    }

    // Perform Floyd-Warshall algorithm
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print shortest path matrix
    printf("Shortest path matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF) {
                printf("%4s", "INF");
            } else {
                printf("%4d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void createAdjMatrix(int gr[][MAX], int v) {
    printf("Use %d for infinity (no direct path).\n", INF);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j) {
                gr[i][j] = 0; // Distance to self is 0
            } else {
                printf("Enter distance from city %d to city %d: ", i + 1, j + 1);
                scanf("%d", &gr[i][j]);
            }
        }
    }

    // Print adjacency matrix
    printf("Adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (gr[i][j] == INF) {
                printf("%4s", "INF");
            } else {
                printf("%4d", gr[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int gr[MAX][MAX];
    int choice, v;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create an adjacency matrix\n");
        printf("2. Compute shortest paths using Floyd-Warshall algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of cities: ");
                scanf("%d", &v);
                createAdjMatrix(gr, v);
                break;

            case 2:


               printf("Enter the number of vertex: ");
               scanf("%d",&v);


              for(int i=0;i<v;i++)
               {
                 for(int j=0;j<v;j++)
                  {
                    printf("Enter the value row %d and column %d : ",i+1,j+1);
                    scanf("%d",&gr[i][j]);
                  }
                }
             warshal(gr,v);
             break;
            case 3:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
