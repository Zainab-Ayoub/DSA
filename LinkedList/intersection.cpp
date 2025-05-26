#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* getIntersectionNode(Node* head1, Node* head2) {
    unordered_set<Node*> visited;

    while (head1) {
        visited.insert(head1);
        head1 = head1->next;
    }

    while (head2) {
        if (visited.find(head2) != visited.end())
            return head2;
        head2 = head2->next;
    }

    return nullptr;
}

// Helper function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // First linked list: 1 -> 2 -> 3 \
    //                                -> 6 -> 7
    // Second linked list:     4 -> 5 /

    Node* common = new Node(6);
    common->next = new Node(7);

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    cout << "List 1: ";
    printList(head1);
    cout << "List 2: ";
    printList(head2);

    Node* intersection = getIntersectionNode(head1, head2);
    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found.\n";

    return 0;
}
