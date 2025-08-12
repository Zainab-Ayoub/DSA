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

int printMin(Node* node){
    if(!node) return -1;
    while(node && node->left) node = node->left;
    return node ? node->data : -1;
}

int printMax(Node* node){
    if(!node) return -1;
    while(node && node->right) node = node->right;
    return node ? node->data : -1;
}

int main(){
    Node* root = nullptr;
    int keys[] = {9, 5, 10, 8, 3, 56, 7, 1, 6};
    for(int key : keys) root = insert(root, key);
    cout<<"Minimum Node: "<<printMin(root)<<endl;
    cout<<"Maximum Node: "<<printMax(root);
    cout<<"\n";
}