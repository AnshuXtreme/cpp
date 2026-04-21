// implement the code of dsa by using push method and pop method
#include <iostream> 
using namespace std;
class Stack {
    int top;
    int arr[100];
public:
    Stack() { top = -1; }
    void push(int x) {
        if (top >= 99) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }
    void pop() {
        if (top < 0) {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }
    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return (top < 0);
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element is: " << s.peek() << endl;
    s.pop();
    cout << "Top element after pop is: " << s.peek() << endl;
    return 0;
}