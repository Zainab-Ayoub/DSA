#include<iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}; 
};

Node* insert(Node* root, int key){
    if(!root) return new Node(key);
    if(key < root->key) root->left =  insert(root->left, key);
    else if(key > root->key) root->right = insert(root->right, key);
    
    return root; // to avoid duplicates
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void mirror(Node* root){
    if(!root) return;
    
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

int main(){
    Node* root = nullptr;
    int keys[] = {1,2,3,4,5,6,7,8};
    for(int key : keys) root = insert(root, key);

    cout<<"Mirror Tree: ";
    mirror(root);
    inorder(root);
    cout<<endl;
}