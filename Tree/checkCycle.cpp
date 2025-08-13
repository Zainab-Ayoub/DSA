#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int k) : data(k), left(nullptr), right(nullptr) {};
};

bool hasCycle(Node* node, Node* parent){
    if(!node) return false;

    if(node->left == parent || node->right == parent) return true;

    return hasCycle(node->left, node) || hasCycle(node->right, node);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    if(hasCycle(root, nullptr))
        cout<<"Tree has a cycle\n";
    else
        cout<<"Tree has no cycle\n";

    return 0;
}