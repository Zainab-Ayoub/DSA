#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList() : head(NULL){}

    void insertAtBeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void merge(LinkedList& other){
        if(!head){
            head = other.head;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = other.head;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<endl;
    }
};

int main(){
    LinkedList list1;
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(4);

    LinkedList list2;
    list2.insertAtEnd(11);
    list2.insertAtEnd(22);
    list2.insertAtEnd(33);
    list2.insertAtEnd(44);

    cout<<"List 1: ";
    list1.display();

    cout<<"List 2: ";
    list2.display();

    list1.merge(list2);

    cout<<"Merged List: ";
    list1.display();
}
