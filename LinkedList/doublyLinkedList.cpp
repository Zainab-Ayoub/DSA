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
        int count;
    
    public:
        DoublyLinkedList(): head(nullptr), tail(nullptr), count(0) {}

        void insert(int val){
            Node* newNode = new Node(val);
            if(!tail){
                head = tail = newNode;
            } else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            count++;
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

        void displayCount(){
            cout<<"Total number of nodes: "<<count<<endl;
        }
};

int main(){
    DoublyLinkedList list;

    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insert(20);

    cout<<"Forward List: \n";
    list.printForward();

    cout<<"Backward List: \n";
    list.printBackward();

    list.displayCount();
}