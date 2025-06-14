#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class LinkedList{
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

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    Node* getHead(){
        return head;
    }

    void printIntersection(LinkedList& other){
        Node* p1 = head;
        Node* p2 = other.getHead();

        cout<<"Intersection: ";
        while(p1 && p2){
            if (p1->data == p2->data){
                cout<<p1->data<<" ";
                p1 = p1->next;
                p2 = p2->next;
            } else if(p1->data < p2->data){
                p1 = p1->next;
            } else{
                p2 = p2->next;
            }
        }
        cout<<endl;
    }
};

int main(){
    LinkedList list1, list2;

    list1.insert(1);
    list1.insert(2);
    list1.insert(3);
    list1.insert(4);
    list1.insert(6);

    list2.insert(2);
    list2.insert(4);
    list2.insert(6);
    list2.insert(8);

    cout<<"List 1: ";
    list1.display();

    cout<<"List 2: ";
    list2.display();

    list1.printIntersection(list2);
}
