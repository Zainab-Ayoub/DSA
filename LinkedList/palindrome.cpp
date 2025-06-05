#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int val): data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(): head(nullptr), tail(nullptr) {}

    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(!tail){
            head = tail = newNode;
        } else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome(){
        Node* left = head;
        Node* right = tail;

        while(left != nullptr && right != nullptr && left != right && left->prev != right){
            if(left->data != right->data){
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void printList(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    DoublyLinkedList list;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        list.insertAtEnd(x);
    }

    cout<<"List: ";
    list.printList();

    if(list.isPalindrome())
        cout<<"The list is a palindrome.\n";
    else
        cout<<"The list is NOT a palindrome.\n";
}
