#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(){
        head = tail = nullptr;
    }

    void insert(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = tail = newNode;
        } else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayOddEvenCount(){
        int oddCount=0, evenCount=0;
        Node* temp = head;

        while(temp){
            if(temp->data % 2 == 0)
                evenCount++;
            else
                oddCount++;
            temp = temp->next;
        }

        cout<<"Number of even elements: "<<evenCount<<endl;
        cout<<"Number of odd elements: "<<oddCount<<endl;
    }
};

int main(){
    DoublyLinkedList dll;

    dll.insert(10);
    dll.insert(21);
    dll.insert(32);
    dll.insert(43);
    dll.insert(54);

    dll.displayOddEvenCount();
}
