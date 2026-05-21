#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->data) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(Node* root) {
        if (!root) return;
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }
};

int main() {
    BinaryTree bt;
    Node* root = nullptr;
    for (int x : {5, 3, 7, 1, 4, 6, 8})
        root = bt.insert(root, x);
    std::cout << "Inorder:   "; bt.inorder(root);   std::cout << "\n";
    std::cout << "Preorder:  "; bt.preorder(root);  std::cout << "\n";
    std::cout << "Postorder: "; bt.postorder(root); std::cout << "\n";
    return 0;
}
