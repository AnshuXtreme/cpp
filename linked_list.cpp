#include <iostream>

struct Node { int data; Node* next; };

class LinkedList {
    Node* head = nullptr;
public:
    void push(int val) { head = new Node{val, head}; }
    void reverse() {
        Node *prev=nullptr, *cur=head;
        while (cur) { Node* n=cur->next; cur->next=prev; prev=cur; cur=n; }
        head = prev;
    }
    void print() {
        for (auto c=head; c; c=c->next) std::cout << c->data << " -> ";
        std::cout << "null\n";
    }
};

int main() {
    LinkedList l;
    for (int i=1; i<=5; i++) l.push(i);
    l.print();
    l.reverse();
    l.print();
    return 0;
}