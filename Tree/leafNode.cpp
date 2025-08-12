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

void printLeafNodes(Node* node){
    if(!node) return;
    if(!node->left && !node->right){
        cout<<node->data<<" ";
        return;
    }
    printLeafNodes(node->left);
    printLeafNodes(node->right);
}

int main(){
    Node* root = nullptr;
    int keys[] = {9,8,27,34,12,345,12,456};
    for(int key : keys) root = insert(root, key);
    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << "\n";
}