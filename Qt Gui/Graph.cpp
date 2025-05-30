#include "Graph.h"
#include <queue>

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Undirected
}

void Graph::dfsUtil(int v, std::unordered_map<int, bool>& visited, int* result, int& index) {
    visited[v] = true;
    result[index++] = v;
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, visited, result, index);
        }
    }
}

int* Graph::dfs(int v, int& size) {
    static int result[100];
    std::unordered_map<int, bool> visited;
    size = 0;
    dfsUtil(v, visited, result, size);
    return result;
}

int* Graph::bfs(int v, int& size) {
    static int result[100];
    std::unordered_map<int, bool> visited;
    std::queue<int> q;
    size = 0;

    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        result[size++] = node;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}