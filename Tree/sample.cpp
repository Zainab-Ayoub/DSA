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

bool search(Node* root, int key){
    if(!root) return false;
    if(root->key == key) return true;

    return (key < root->key) ? search(root->left, key) : search(root->right, key);
}

void preOrder(Node* root){
    if(!root) return;
    cout<<root->key<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->key<<" ";
}

void inOrder(Node* root){
    if(!root) return;
    inOrder(root->left);
    cout<<root->key<<" ";
    inOrder(root->right);
}

void freeTree(Node* root){
    if(!root) return;
    freeTree(root->left);
    freeTree(root->right);
    
    delete root;
}

int main(){
    Node* root = nullptr;
    int keys[] = {1,2,3,4,5,6,7,8};
    for(int key : keys) root = insert(root, key);

    cout<<"PreOrder: ";
    preOrder(root);
    cout<<endl;

    cout<<"PostOrder: ";
    postOrder(root);
    cout<<endl;

    cout<<"InOrder: ";
    inOrder(root);
    cout<<endl;

    cout<<"Search 4: "<<(search(root, 8) ? "Found\n" : "Not found\n");

    freeTree(root);
}