#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    void createFromUserInput() {
        int n, value;
        cout << "Enter number of nodes: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cout << "Enter value for node " << i + 1 << ": ";
            cin >> value;
            insertAtEnd(value);
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            tail->next = head;  
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;  
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~CircularLinkedList() {
        if (!head) return;

        Node* temp = head->next;
        while (temp != head) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete head;
    }
};

int main() {
    CircularLinkedList cll;
    cll.createFromUserInput();
    cll.display();

    return 0;
}
