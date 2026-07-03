#include <iostream>

struct Node {
    int data, height;
    Node* left;
    Node* right;
    Node(int val) : data(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
    int height(Node* n) { return n ? n->height : 0; }
    int balance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

    void updateHeight(Node* n) {
        n->height = 1 + std::max(height(n->left), height(n->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T = x->right;
        x->right = y; y->left = T;
        updateHeight(y); updateHeight(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T = y->left;
        y->left = x; x->right = T;
        updateHeight(x); updateHeight(y);
        return y;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        else return node;

        updateHeight(node);
        int bal = balance(node);

        if (bal > 1 && val < node->left->data)  return rotateRight(node);
        if (bal < -1 && val > node->right->data) return rotateLeft(node);
        if (bal > 1 && val > node->left->data)  { node->left = rotateLeft(node->left);  return rotateRight(node); }
        if (bal < -1 && val < node->right->data) { node->right = rotateRight(node->right); return rotateLeft(node); }
        return node;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }

    Node* root = nullptr;
public:
    void insert(int val) { root = insert(root, val); }
    void print() { inorder(root); std::cout << "\n"; }
};

int main() {
    AVLTree tree;
    for (int x : {30, 20, 10, 40, 50, 25})
        tree.insert(x);
    tree.print(); // 10 20 25 30 40 50
    return 0;
}
