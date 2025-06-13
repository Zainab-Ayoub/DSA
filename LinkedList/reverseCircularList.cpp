#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr){}
};

void reverseCircularList(Node*& head){
    if(!head || head->next == head)
        return;

    Node *prev = nullptr, *curr = head, *nextNode = nullptr;
    Node* tail = head;

    do{
        tail = tail->next;
    } while(tail->next != head);

    Node* stop = head;

    do{
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while(curr != stop);

    head->next = prev;
    head = prev;
}

void printCircularList(Node* head){
    if(!head) return;
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    } while(temp != head);
    cout<<endl;
}

void insert(Node*& head, int data){
    Node* newNode = new Node(data);
    if(!head){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

int main(){
    Node* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);

    cout<<"Original list: ";
    printCircularList(head);

    reverseCircularList(head);

    cout<<"Reversed list: ";
    printCircularList(head);
}
