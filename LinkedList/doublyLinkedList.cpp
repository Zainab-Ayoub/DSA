#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int val): data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
    
    public:
        DoublyLinkedList(): head(nullptr), tail(nullptr) {}

        void insertAtBeginning(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = tail = newNode;
            } else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void insertAtEnd(int val){
            Node* newNode = new Node(val);
            if(!tail){
                head = tail = newNode;
            } else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        } 

        void printForward(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            } cout<<endl; 
        }

        void printBackward(){
            Node* temp = tail;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->prev;
            } cout<<endl; 
        }
};

int main(){
    DoublyLinkedList list;

    list.insertAtBeginning(5);
    list.insertAtEnd(10);
    list.insertAtEnd(15);
    list.insertAtEnd(20);

    cout<<"Forward List: \n";
    list.printForward();

    cout<<"Backward List: \n";
    list.printBackward();
}