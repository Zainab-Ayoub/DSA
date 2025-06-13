#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void reverseList(){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while(current != nullptr){
            next = current->next; 
            current->next = prev; 
            prev = current;        
            current = next;     
        }
        head = prev;
    }

    void displayReverse(){
        reverseList();
        display();
        reverseList(); 
    }

    void search(int key){
        Node* temp = head;
        int pos = 1;
        while(temp != nullptr){
            if(temp->data == key){
                cout<<"Value "<<key<<" found at position "<<pos<<endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout<<"Value "<<key<<" not found in the list."<<endl;
    }

    int getSize(){
        Node* temp = head;
        int count = 0;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void menu(){
        int choice, value;
        do{
            cout<<"Menu:\n";
            cout<<"Press 1 to Insert a Node\n";
            cout<<"Press 2 to Display List\n";
            cout<<"Press 3 to Display in Reverse\n";
            cout<<"Press 4 to Search a Value\n";
            cout<<"Press 5 to Display Size of List\n";
            cout<<"Press 0 to Exit\n";
            cout<<"Enter choice: ";
            cin>>choice;

            switch(choice){
                case 1:
                    cout<<"Enter value to insert: ";
                    cin>>value;
                    insertAtEnd(value);
                    break;
                case 2:
                    cout<<"Linked List: ";
                    display();
                    break;
                case 3:
                    cout<<"List in Reverse: ";
                    displayReverse();
                    break;
                case 4:
                    cout<<"Enter value to search: ";
                    cin>>value;
                    search(value);
                    break;
                case 5:
                    cout<<"Size of List: "<<getSize()<<endl;
                    break;
                case 0:
                    cout<<"Program Exited Successfully!\n";
                    break;
                default:
                    cout<<"Invalid choice. Try again.\n";
            }
        } while(choice != 0);
    }
};

int main(){
    LinkedList list;
    list.menu();
}
