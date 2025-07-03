#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// -------------------- Traversal Functions --------------------

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// -------------------- Tree Classification Functions --------------------

// 1. Print Leaf Nodes
void printLeafNodes(Node* root) {
    if (!root) return;

    if (!root->left && !root->right)
        cout << root->data << " ";

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// 2. Print Parent Nodes
void printParentNodes(Node* root) {
    if (!root) return;

    if (root->left || root->right)
        cout << root->data << " ";

    printParentNodes(root->left);
    printParentNodes(root->right);
}

// 3. Print Sibling Pairs (With Parent)
void printSiblingPairs(Node* root) {
    if (!root) return;

    if (root->left && root->right) {
        cout << "Parent: " << root->data 
             << " → Siblings: " << root->left->data 
             << " & " << root->right->data << endl;
    }

    printSiblingPairs(root->left);
    printSiblingPairs(root->right);
}

// 4. Print Child Nodes (With Parent)
void printChildren(Node* root) {
    if (!root) return;

    if (root->left)
        cout << "Parent: " << root->data << " → Left Child: " << root->left->data << endl;

    if (root->right)
        cout << "Parent: " << root->data << " → Right Child: " << root->right->data << endl;

    printChildren(root->left);
    printChildren(root->right);
}

// -------------------- Driver Code --------------------

int main() {
    // Constructing the tree:
    //         1
    //        / \
    //       2   3
    //      /   / \
    //     4   5   8
    //        / \  / \
    //       6  7 9  10

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(8);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl << endl;

    cout << "Leaf Nodes: ";
    printLeafNodes(root);
    cout << endl;

    cout << "Parent Nodes: ";
    printParentNodes(root);
    cout << endl;

    cout << "Sibling Pairs:\n";
    printSiblingPairs(root);
    cout << endl;

    cout << "Child Nodes:\n";
    printChildren(root);
    cout << endl;

    return 0;
}
