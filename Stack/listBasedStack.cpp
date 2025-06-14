#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int value){
        this->data = value;
        this->next = nullptr;
    }
};

class Stack {
    Node* head;

public:
    Stack() : head(nullptr) {}

    bool isEmpty(){
        return head == nullptr;
    }

    void push(int value){
        Node* newNode = new Node(value);
        if(!newNode){
            cout<<"Stack Overflow\n";
        }
        newNode->next = head;
        head = newNode;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n"<<endl;
        } else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int topElement(){
        if(!isEmpty())
            return head->data;
        else{
            cout<<"Stack is empty\n";
            return -1;
        }
    }

    void display(){
        cout<<"Stack (Top to Bottom): ";
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.display();
    cout<<"Top element is: "<<st.topElement()<<endl;
    st.pop();
    cout<<"After popping one element the top element is: "<<st.topElement()<<endl;
    st.display();
}