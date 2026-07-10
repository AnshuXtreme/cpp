#include <iostream>

class CircularQueue {
    int* arr;
    int front, rear, size, cap;
public:
    CircularQueue(int c) : cap(c), front(0), rear(0), size(0) {
        arr = new int[cap];
    }
    ~CircularQueue() { delete[] arr; }

    bool enqueue(int val) {
        if (size == cap) { std::cout << "Queue full\n"; return false; }
        arr[rear] = val;
        rear = (rear + 1) % cap;
        size++;
        return true;
    }

    int dequeue() {
        if (size == 0) { std::cout << "Queue empty\n"; return -1; }
        int val = arr[front];
        front = (front + 1) % cap;
        size--;
        return val;
    }

    int peek() { return size ? arr[front] : -1; }
    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == cap; }

    void print() {
        for (int i = 0; i < size; i++)
            std::cout << arr[(front+i) % cap] << " ";
        std::cout << "\n";
    }
};

int main() {
    CircularQueue q(4);
    q.enqueue(1); q.enqueue(2); q.enqueue(3); q.enqueue(4);
    q.print();        // 1 2 3 4
    q.enqueue(5);     // Queue full
    q.dequeue();
    q.enqueue(5);
    q.print();        // 2 3 4 5
    return 0;
}
