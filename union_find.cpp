#include <iostream>
#include <vector>

class UnionFind {
    std::vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) std::swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py]) rank[px]++;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

int main() {
    UnionFind uf(6);
    uf.unite(0, 1);
    uf.unite(1, 2);
    uf.unite(3, 4);

    std::cout << uf.connected(0, 2) << "\n"; // 1
    std::cout << uf.connected(0, 3) << "\n"; // 0
    uf.unite(2, 3);
    std::cout << uf.connected(0, 4) << "\n"; // 1
    return 0;
}
