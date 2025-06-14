#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack{
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value){
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int topElement(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == nullptr;
    }

    void display(){
        cout<<"Stack (Top to Bottom): ";
        Node* temp = top;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Stack s;
    int arr[5] = {1,2,3,4,5};
    for(int i=0; i<5; i++)
        s.push(arr[i]);

    s.display();        

    cout<<"Popped one element"<<endl;
    s.pop();
    s.display();

    cout<<"Top element is: "<<s.topElement()<<endl;
}
