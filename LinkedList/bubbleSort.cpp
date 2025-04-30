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
void bubbleSort(Node* head) {
    if (!head) return;

    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }

    for (int i = 0; i < n - 1; ++i) {
        Node* curr = head;
        while (curr->next) {
            if (curr->data > curr->next->data) {
                int t = curr->data;
                curr->data = curr->next->data;
                curr->next->data = t;
            }
            curr = curr->next;
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

    cout << "Sorted list: ";
    bubbleSort(head);
    printList(head);
    
    return 0;
}
