Write a C program to implement DFS and BFS.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct Edge
{
   int destination;
   struct Edge* next;
} Edge;
 
typedef struct Vertex
{
   int id;
   Edge* head; // Pointer to the head of the adjacency list
} Vertex;
 
typedef struct Graph
{
   int numVertices;
   Vertex* vertices;
} Graph;
 
Edge* createEdge(int destination)
{
   Edge* newEdge = (Edge*)malloc(sizeof(Edge));
   newEdge->destination = destination;
   newEdge->next = NULL;
   return newEdge;
}
 
Graph* createGraph(int numVertices)
{
   Graph* graph = (Graph*)malloc(sizeof(Graph));
   graph->numVertices = numVertices;
   graph->vertices = (Vertex*)malloc(numVertices * sizeof(Vertex));
   for (int i = 0; i < numVertices; i++)
  {
       graph->vertices[i].id = i;
       graph->vertices[i].head = NULL;
   }
   return graph;
}
 
void addEdge(Graph* graph, int source, int destination)
{
   Edge* newEdge = createEdge(destination);
   newEdge->next = graph->vertices[source].head;
   graph->vertices[source].head = newEdge;
   newEdge = createEdge(source);
   newEdge->next = graph->vertices[destination].head;
   graph->vertices[destination].head = newEdge;
}
 
void DFSUtil(Graph* graph, int vertex, int* visited)
{
   visited[vertex] = 1;
   printf("%d ", vertex);
   Edge* current = graph->vertices[vertex].head;
   while (current)
   {
       if (!visited[current->destination])
           DFSUtil(graph, current->destination, visited);
       current = current->next;
    }
}
 
void DFS(Graph* graph, int startVertex)
{
   int visited[MAX_VERTICES] = {0}; // Initialize visited array
   printf("DFS starting from vertex %d:\n", startVertex);
   DFSUtil(graph, startVertex, visited);
   printf("\n");
}
 
void BFS(Graph* graph, int startVertex)
{
   int visited[MAX_VERTICES] = {0}; // Initialize visited array
   int queue[MAX_VERTICES], front = 0, rear = 0;
   visited[startVertex] = 1;
   queue[rear++] = startVertex;
   printf("BFS starting from vertex %d:\n", startVertex);
   while (front < rear)
  { 
       int currentVertex = queue[front++];
       printf("%d ", currentVertex);
       Edge* current = graph->vertices[currentVertex].head;
       while (current)
       {
           if (!visited[current->destination])
​{
               visited[current->destination] = 1;
               queue[rear++] = current->destination;
           }
           current = current->next;
       }
   }
   printf("\n");
}
 
void freeGraph(Graph* graph)
{
   for (int i = 0; i < graph->numVertices; i++)
  {
       Edge* current = graph->vertices[i].head;
       while (current)
       {
           Edge* temp = current;
           current = current->next;
           free(temp);
       }
   }
   free(graph->vertices);
   free(graph);
}
 
int main()
{
   int numVertices, numEdges;
   printf("Enter the number of vertices: ");
   scanf("%d", &numVertices);
 
   Graph* graph = createGraph(numVertices);
   printf("Enter the number of edges: ");
   scanf("%d", &numEdges);
   for (int i = 0; i < numEdges; i++)
   {
       int source, destination;
       printf("Enter edge %d (source destination): ", i + 1);
       scanf("%d %d", &source, &destination);
       addEdge(graph, source, destination);
   }
   int startVertex;
   printf("Enter the starting vertex for DFS and BFS: ");
   scanf("%d", &startVertex);
   DFS(graph, startVertex);
   BFS(graph, startVertex);
   freeGraph(graph);
   return 0;
}