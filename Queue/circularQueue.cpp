#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* pre;
    Node(int d) {
        data = d;
        next = NULL;
        pre=NULL;
    }
};

class Queue {
    Node *front, *rear;
public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* temp = new Node(val);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        else{
        rear->next = temp;
        temp->pre=rear;
        rear = temp;
    }
    front->pre=rear;
    rear->next=front;
    }
    

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }
        else{
        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;
        front = front->next;
        front->pre = rear;
        rear->next = front;
}
        delete temp;
}

};
int main(){
	Queue c;
	c.dequeue();
	c.enqueue(10);
	c.enqueue(20);
	c.dequeue();
}