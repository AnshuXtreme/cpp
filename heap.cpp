#include <iostream>
#include <vector>

class MinHeap {
    std::vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] > heap[i]) {
                std::swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int smallest = i, l = 2*i+1, r = 2*i+2;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (smallest == i) break;
            std::swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }
public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    int extractMin() {
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return min;
    }
    int top() { return heap[0]; }
    bool empty() { return heap.empty(); }
};

int main() {
    MinHeap h;
    for (int x : {5, 3, 8, 1, 9, 2}) h.insert(x);
    while (!h.empty())
        std::cout << h.extractMin() << " "; // 1 2 3 5 8 9
    return 0;
}
