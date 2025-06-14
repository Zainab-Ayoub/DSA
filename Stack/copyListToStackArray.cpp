#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
	Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void copyToStack(){
        int stack[5], i = 0;

        Node* temp = head;
        while(temp){
            stack[i++] = temp->data;
            temp = temp->next;
        }

        cout<<"Values popped from Stack (LIFO): ";
        for(int j = i-1; j>=0; j--)
            cout<<stack[j]<<" ";
        cout<<endl;
    }
};

int main(){
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    list.copyToStack();
}
