#include <iostream>
#include <queue>

class MyStack {
    std::queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < (int)q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() { int t = q.front(); q.pop(); return t; }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    MyStack s;
    s.push(1); s.push(2); s.push(3);
    std::cout << s.top() << "\n"; // 3
    s.pop();
    std::cout << s.top() << "\n"; // 2
    return 0;
}