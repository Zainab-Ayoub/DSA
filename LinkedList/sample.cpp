#include<iostream>
using namespace std;

struct Node {
    int data;  
    Node* next; 
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;      
        newNode->next = head;      
        head = newNode;            
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;      
        newNode->next = NULL;       

        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

};

int main() {
    LinkedList list1;

    list1.insertAtEnd(10);
    list1.insertAtEnd(20);

    list1.insertAtBeginning(5);

    cout << "Linked List: ";
    list1.display();
    
    return 0;
} 