#include <stdio.h>
#include <stdlib.h>

// Define a node structure for adjacency list
struct Node {
    int data;
    struct Node *next;
};

// Define a graph structure
struct Graph {
    struct Node *head;
};

// Function to create a new graph
struct Graph* createGraph(int numVertices) {
    struct Graph *graph = (struct Graph *)malloc(numVertices * sizeof(struct Graph));
    for (int i = 0; i < numVertices; i++) {
        graph[i].head = NULL;
    }
    return graph;
}

// Function to free the graph memory
void freeGraph(struct Graph *graph, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        struct Node *current = graph[i].head;
        while (current) {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = dest;
    newNode->next = graph[src].head;
    graph[src].head = newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = src;
    newNode->next = graph[dest].head;
    graph[dest].head = newNode;
}

// Function to print the adjacency list of the graph
void printGraph(struct Graph *graph, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        struct Node *current = graph[i].head;
        printf("%d -> ", i);
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }




    
}

// Depth-First Search (DFS) function
void dfs(struct Graph *graph, int *visited, int vertex) {
    visited[vertex] = 1;
    printf("%d -> ", vertex);

    struct Node *current = graph[vertex].head;
    while (current) {
        if (!visited[current->data]) {
            dfs(graph, visited, current->data);
        }
        current = current->next;
    }
}

// Breadth-First Search (BFS) function
void bfs(struct Graph *graph, int *visited, int *queue, int startVertex, int numVertices) {
    int front = 0, rear = 0;
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d -> ", currentVertex);

        struct Node *current = graph[currentVertex].head;
        while (current) {
            if (!visited[current->data]) {
                visited[current->data] = 1;
                queue[rear++] = current->data;
            }
            current = current->next;
        }
    }
}

// Main function
int main() {
    int numVertices = 5; // Number of vertices in the graph
    struct Graph *graph = createGraph(numVertices);
    int visited[5] = {0};
    int queue[5] = {0};

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 4);

    // Print the graph
    printf("Graph adjacency list:\n");
    printGraph(graph, numVertices);

    // Reset visited array for BFS
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Perform BFS starting from vertex 1
    printf("\nBFS traversal starting from vertex 1:\n");
    bfs(graph, visited, queue, 1, numVertices);
    printf("NULL\n");

    // Reset visited array for DFS
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Perform DFS starting from vertex 1
    printf("\nDFS traversal starting from vertex 1:\n");
    dfs(graph, visited, 1);
    printf("NULL\n");

    // Free the graph memory
    freeGraph(graph, numVertices);

    return 0;
}