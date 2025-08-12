#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

Node* insert(Node* root, int data){
    if(!root) return new Node(data);

    if(data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

void printRight(Node* node){
    if(node != nullptr){
        printRight(node->left);
        cout<<node->data<<" ";
        printRight(node->right);
    }
}

int main(){
    Node* root = nullptr;
    int values[] = {9,5,10,9,8,3,56,7,1,6};
    for(int value : values) root = insert(root, value);
    cout<<"Right subtree:\n";
    if(root && root->right) printRight(root->right);
    else cout<<"empty\n";
}