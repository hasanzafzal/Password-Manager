#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <unordered_map>

class Graph {
private:
    std::unordered_map<int, std::list<int>> adj;
    void dfsUtil(int v, std::unordered_map<int, bool>& visited, int* result, int& index);

public:
    void addEdge(int v, int w);
    int* dfs(int v, int& size);
    int* bfs(int v, int& size);
};

#endif