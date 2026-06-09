#include <iostream>
#include <vector>
#include <queue>
#include <climits>

typedef std::pair<int,int> pii;

class Graph {
    int V;
    std::vector<std::vector<pii>> adj;
public:
    Graph(int v) : V(v), adj(v) {}
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    void dijkstra(int src) {
        std::vector<int> dist(V, INT_MAX);
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        for (int i = 0; i < V; i++)
            std::cout << "dist[" << i << "] = " << dist[i] << "\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1,4); g.addEdge(0,2,1);
    g.addEdge(2,1,2); g.addEdge(1,3,1);
    g.addEdge(2,3,5); g.addEdge(3,4,3);
    g.dijkstra(0);
    return 0;
}
