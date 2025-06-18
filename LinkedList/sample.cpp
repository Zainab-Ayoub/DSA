#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr){}
};

class LinkedList{
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList(){
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtBeginning(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int position, int value){
        if(position<1){
            cout<<"Invalid position\n";
            return;
        }
        if(position == 1){
            insertAtBeginning(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for(int i=1; i < position-1 && temp; ++i){
            temp = temp->next;
        }
        if(!temp){
            cout<<"Position out of bounds.\n";
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int value){
        Node* temp = head;
        Node* prev = nullptr;

        while(temp){
            if(temp->data == value){
                if(prev){
                    prev->next = temp->next;
                } else{
                    head = temp->next;
                }
                delete temp;
                cout<<"Deleted node with value "<<value<<endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout<<"Value "<<value<<" not found\n";
    }

    void update(int oldValue, int newValue){
        Node* temp = head;
        while(temp){
            if(temp->data == oldValue){
                temp->data = newValue;
                cout<<"Updated "<<oldValue<<" to "<<newValue<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"Value "<<oldValue<<" not found.\n";
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    cout<<"Initial List: ";
    list.display();

    list.insertAtBeginning(5);
    cout<<"After inserting 5 at Beginning: ";
    list.display();

    list.insertAtPosition(3, 15);
    cout<<"After inserting 15 at Position 3: ";
    list.display();

    list.update(3, 25);
    cout<<"After updating 3 to 25: ";
    list.display();

    list.deleteNode(15);
    cout<<"After deleting 15: ";
    list.display();
}
