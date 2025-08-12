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

void printChildNodes(Node* node, int parent){
    if(!node) return;
    if(node->data == parent){
        if(node->left) cout<<node->left->data<<" \n";
        else cout<<"No left child";
        if(node->right) cout<<node->right->data<<" \n";
        else cout<<"No right child";
    }
    printChildNodes(node->left, parent);
    printChildNodes(node->right, parent);
}

int main(){
    Node* root = nullptr;
    int keys[] = {9,8,27,34,12,345,12,456};
    for(int key : keys) root = insert(root, key);
    cout << "Child nodes: ";
    printChildNodes(root, 27);
    cout << "\n";
}