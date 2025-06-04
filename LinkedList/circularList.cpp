#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Create nodes
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};

    // Link them circularly
    head->next = second;
    second->next = third;
    third->next = head; // Circular link

    // Traverse and print the list once
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;

    // Free memory (optional but good practice)
    delete head;
    delete second;
    delete third;

    return 0;
}
