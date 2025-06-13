#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList() : head(nullptr){}

    void insertAtEnd(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void selectionSort(){
        for(Node* i = head; i != nullptr; i = i->next){
            Node* minNode = i;
            for(Node* j = i->next; j != nullptr; j = j->next){
                if(j->data < minNode->data){
                    minNode = j;
                }
            }
            if(minNode != i){
                int temp = i->data;
                i->data = minNode->data;
                minNode->data = temp;
            }
        }
    }
};

int main(){
    LinkedList list;

    list.insertAtEnd(4);
    list.insertAtEnd(3);
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    cout<<"Original list: ";
    list.display();

    list.selectionSort();

    cout<<"Sorted list: ";
    list.display();
}
