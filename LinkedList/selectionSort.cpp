#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void selectionSort(Node* head) {
    for (Node* i = head; i != nullptr; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data < minNode->data) {
                minNode = j;
            }
        }
        if (minNode != i) {
            int t = i->data;
            i->data = minNode->data;
            minNode->data = t;
        }
    }
}
int main() {
    Node* head = new Node(4);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);

    cout << "Original list: ";
    printList(head);

    selectionSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
