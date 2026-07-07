#include <iostream>
#include <vector>

class SegmentTree {
    int n;
    std::vector<int> tree;

    void build(const std::vector<int>& arr, int node, int l, int r) {
        if (l == r) { tree[node] = arr[l]; return; }
        int mid = l + (r-l)/2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = val; return; }
        int mid = l + (r-l)/2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = l + (r-l)/2;
        return query(2*node, l, mid, ql, qr) +
               query(2*node+1, mid+1, r, ql, qr);
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n, 0);
        build(arr, 1, 0, n-1);
    }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }
};

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    std::cout << "Sum(1,3): " << st.query(1, 3) << "\n"; // 15
    st.update(2, 10);
    std::cout << "Sum(1,3): " << st.query(1, 3) << "\n"; // 20
    return 0;
}
