#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
      int data;
      struct node *next;
}node;

typedef struct graph{
      node * head;
}graph;

graph * create(int n){
      graph * G = (graph *)malloc(n*sizeof(graph));
      for(int i = 0 ; i < n ; i++)
            G[i].head = NULL;

      return G;
}

void addedge(graph * G, int s, int d){
      node * newnode = (node *)malloc(sizeof(node));
      newnode->data = d;
      newnode->next = G[s].head;
      G[s].head = newnode;

      newnode = (node *)malloc(sizeof(node));
      newnode->data = s;
      newnode->next = G[d].head;
      G[d].head = newnode;
}

void printgraph(graph * G,int n){
      node * current = NULL;
      for(int i = 0 ; i < n ; i++){
            current = G[i].head;
            printf("Vertex %d: ",i);
            while(current != NULL){
                  printf("%d->",current->data);
                  current = current->next;
            }
            printf("NULL\n");
      }
      }

void bfs(graph *G, int start, int n) {
    int f = 0 , r = 0;
    int *visited = (int *)calloc(n , sizeof(int));
    int *queue = (int *)calloc(n , sizeof(int));
    visited[start] = 1;
    queue[r++] = start;
    while(f<r){
      int curr = queue[f++];
      printf("%d ",curr);
      node * t = G[curr].head;
      while(t){
            if(!visited[t->data]){
                  visited[t->data] = 1;
                  queue[r++] = t->data;
            }
            t = t->next;
      }
    }
}

void dfs(graph *G, int start,int * vis) {
    vis[start] = 1;
    printf("%d -> ", start);

    node *current = G[start].head;
    while (current) {
        if (!vis[current->data]) {
            dfs(G, current->data,vis);
        }
        current = current->next;
    }
    
}

int main(){
      int n,a,b;
      int visited[100] = {0};
      printf("Enter number of vertices: ");
      scanf("%d",&n);

      graph * G = create(n);

      for(int i = 0 ; i < n ; i++){
            printf("Add Edge: ");
            scanf("%d%d",&a,&b);
            addedge(G,a,b);
      }

      printgraph(G,n);
      bfs(G,0,n);
      dfs(G,0,visited);
      return 0;
}
