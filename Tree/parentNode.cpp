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

void findParent(Node* node, int child,  int parent = -1){
    if(!node) return;
    if(node->data == child){
        if(parent == -1) cout<<"Node has no parent\n";
        else cout<<"Parent of "<<child<<" is "<<parent<<"\n";
        return;
    }
    findParent(node->left, child, node->data);
    findParent(node->right, child, node->data);
}

int main(){
    Node* root = nullptr;
    int keys[] = {9,8,27,34,12,345,12,456};
    for(int key : keys) root = insert(root, key);
    cout << "Parent node: ";
    findParent(root, 345);
    cout << "\n";
}