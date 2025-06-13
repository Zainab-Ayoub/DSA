#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val) : data(val), next(nullptr) {}
};

class Queue{
    private:
        Node* front;
        Node* rear;

    public:
        Queue() : front(nullptr), rear(nullptr) {}

        void enqueue(int val){
            Node* newNode = new Node(val);

            if(rear == nullptr){
                front = rear = newNode;
            } else{
                rear->next = newNode;
                rear = newNode;
            }
        }

        void dequeue(){
            if(front == nullptr){
                cout<<"Queue is empty."<<endl;
                return;
            }

            Node* temp = front;
            front = front->next;

            if(front == nullptr){
                rear = nullptr;
            }

            delete temp;
        }

        int peek(){
            if(front == nullptr){
                cout<<"Queue is empty."<<endl;
                return -1;
            }
            return front->data;
        }

        void display(){
            if(front == nullptr){
                cout<<"Queue is empty."<<endl;
                return;
            }

            Node* temp = front;
            cout<<"Queue elements: ";
            while(temp != nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        ~Queue(){
            while (front != nullptr){
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout<<"Front element: "<<q.peek()<<endl;

    q.dequeue();
    q.display();

    cout<<"Front element after dequeue: "<<q.peek()<<endl;
}
