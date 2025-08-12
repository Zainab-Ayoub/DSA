#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int key) {
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

int height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

bool isBalanced(Node* root) {
    if (!root) return true;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) > 1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node; 

    node->height = max(height(node->left), height(node->right)) + 1;
    return node; 
}

int main() {
    Node* root = nullptr;

    int keys[] = {30, 10, 20, 40, 50, 25}; 
    for (int key : keys) {
        root = insert(root, key);
    }

    cout << (isBalanced(root) ? "Tree is balanced" : "Tree is NOT balanced") << endl;

    return 0;
}