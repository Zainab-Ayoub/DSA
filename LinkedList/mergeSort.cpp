#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    private:
        Node* head;

        Node* findMiddle(Node* h){
            if (!h) return h;

            Node* slow = h;
            Node* fast = h->next;

            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }

        Node* mergeSortedLists(Node* l1, Node* l2){
            Node dummy;
            Node* tail = &dummy;
            dummy.next = nullptr;

            while(l1 && l2){
                if(l1->data <= l2->data){
                    tail->next = l1;
                    l1 = l1->next;
                } else{
                    tail->next = l2;
                    l2 = l2->next;
                }
                tail = tail->next;
            }

            if(l1)
                tail->next = l1;
            else
                tail->next = l2;

            return dummy.next;
        }

        Node* mergeSort(Node* h){
            if(!h || !h->next) return h;

            Node* mid = findMiddle(h);
            Node* rightHalf = mid->next;
            mid->next = nullptr;

            Node* leftSorted = mergeSort(h);
            Node* rightSorted = mergeSort(rightHalf);

            return mergeSortedLists(leftSorted, rightSorted);
        }

    public:
        LinkedList() : head(NULL) {}

        void insertAtEnd(int value){
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;

            if(!head){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void sort(){
            head = mergeSort(head);
        }

        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main(){
    LinkedList list;
    list.insertAtEnd(44);
    list.insertAtEnd(11);
    list.insertAtEnd(33);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(99);

    cout<<"Original List: ";
    list.display();
    list.sort();
    cout<<"Sorted List: ";
    list.display();
}