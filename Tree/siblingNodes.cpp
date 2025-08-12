#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (!root) return new Node(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void printSiblingNodes(Node* node){
    if(!node) return;
    if(node->left && node->right){
        cout<<node->left->data<<", "<<node->right->data;
        cout<<endl;
    }
    printSiblingNodes(node->left);
    printSiblingNodes(node->right);
}

int main(){
    Node* root = nullptr;
    int keys[] = {9, 5, 10, 8, 3, 56, 7, 1, 6};
    for(int key : keys) root = insert(root, key);
    cout << "Sibling nodes: ";
    printSiblingNodes(root);
    cout << "\n";
}