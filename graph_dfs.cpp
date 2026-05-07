#include <iostream>
#include <vector>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;
    void dfsHelper(int node, std::vector<bool>& visited) {
        visited[node] = true;
        std::cout << node << " ";
        for (int nb : adj[node])
            if (!visited[nb]) dfsHelper(nb, visited);
    }
public:
    Graph(int v) : V(v), adj(v) {}
    void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
    void dfs(int src) {
        std::vector<bool> visited(V, false);
        dfsHelper(src, visited);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1); g.addEdge(0,2); g.addEdge(1,3); g.addEdge(2,4);
    g.dfs(0); // 0 1 3 2 4
    return 0;
}