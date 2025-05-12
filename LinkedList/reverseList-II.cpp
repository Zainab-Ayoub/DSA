#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    ListNode* curr = prev->next;

    for (int i = 0; i < right-left; i++) {
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout<<"Original list: ";
    printList(head);

    int left = 2, right = 4;
    head = reverseBetween(head, left, right);

    cout<<"Reversed list: ";
    printList(head);

    return 0;
}
