#include <iostream>
#include <vector>
#include <queue>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;
public:
    Graph(int v) : V(v), adj(v) {}
    void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
    void bfs(int src) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;
        q.push(src); visited[src] = true;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            std::cout << node << " ";
            for (int nb : adj[node])
                if (!visited[nb]) { visited[nb]=true; q.push(nb); }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1); g.addEdge(0,2); g.addEdge(1,3); g.addEdge(2,4);
    g.bfs(0); // 0 1 2 3 4
    return 0;
}