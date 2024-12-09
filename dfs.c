void dfs(graph *G, int start, int *vis, int destination) {
    // Mark the current node as visited
    vis[start] = 1;
    printf("%d -> ", start);

    // Check if the current node is the destination
    if (start == destination) {
        printf("Destination %d found!\n", destination);
        return; // Exit if the destination is found
    }

    // Traverse through all adjacent nodes
    node *current = G[start].head;
    while (current) {
        if (!vis[current->data]) {
            dfs(G, current->data, vis, destination);
        }
        current = current->next;
    }
}
