#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr){}
};

class SinglyLinkedList{
    private:
        Node* head;
        Node* tail;

    public:
        SinglyLinkedList() : head(nullptr), tail(nullptr){}

        void append(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = tail = newNode;
            } else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void prepend(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = tail = newNode;
            } else{
                newNode->next = head;
                head = newNode;
            }
        }

        void print(){
            Node* curr = head;
            while(curr){
                cout<<curr->data<<" ";
                curr = curr->next;
            }
            cout<<endl;
        }
};

int main(){
    SinglyLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    cout<<"After appending:\n";
    list.print();

    list.prepend(5);
    cout<<"After prepending:\n";
    list.print();
}
