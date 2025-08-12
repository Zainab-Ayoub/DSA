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

void printAscending(Node* node){
    if(!node) return;
    
    printAscending(node->left);
    cout<<node->data<<endl;
    printAscending(node->right);
}

void printDescending(Node* node){
    if(!node) return;
    
    printDescending(node->right);
    cout<<node->data<<endl;
    printDescending(node->left);
}

int main(){
    Node* root = nullptr;
    int keys[] = {9, 5, 10, 8, 3, 56, 7, 1, 6};
    for(int key : keys) root = insert(root, key);
    cout << "Nodes in Ascending Order: ";
    printAscending(root);
    cout << "Nodes in Descending Order: ";
    printDescending(root);
    cout << "\n";
}