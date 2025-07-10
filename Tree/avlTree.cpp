#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int balanceFactor(Node* node) {
    return height(node->left) - height(node->right);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(int key) {
    Node* t = new Node;
    t->data = key;
    t->left = t->right = nullptr;
    t->height = 1;
    return t;
}

Node* LLRotation(Node* node) {
    Node* pl = node->left;
    Node* plr = pl->right;

    pl->right = node;
    node->left = plr;

    node->height = max(height(node->left), height(node->right)) + 1;
    pl->height = max(height(pl->left), height(pl->right)) + 1;

    return pl;
}

Node* RRRotation(Node* node) {
    Node* pr = node->right;
    Node* prl = pr->left;

    pr->left = node;
    node->right = prl;

 
    node->height = max(height(node->left), height(node->right)) + 1;
    pr->height = max(height(pr->left), height(pr->right)) + 1;

    return pr;
}

Node* LRRotation(Node* node) {
    node->left = RRRotation(node->left);
    return LLRotation(node);
}

Node* RLRotation(Node* node) {
    node->right = LLRotation(node->right);
    return RRRotation(node);
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

    if (balanceFactor(node) > 1 && key < node->left->data)
    return LLRotation(node);  

    if (balanceFactor(node) < -1 && key > node->right->data)
        return RRRotation(node); 

    if (balanceFactor(node) > 1 && key > node->left->data)
        return LRRotation(node);  

    if (balanceFactor(node) < -1 && key < node->right->data)
        return RLRotation(node);  

    return node; 
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    int keys[] = {30, 10, 20, 40, 50, 25}; 
    for (int key : keys) {
        root = insert(root, key);
    }

    cout << "In-order Traversal of AVL Tree: ";
    inOrder(root);
    cout << endl;

    return 0;
}
