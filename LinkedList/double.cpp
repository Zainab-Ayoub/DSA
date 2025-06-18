#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int count;

    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

        void insert(int value) {
            Node* newNode = new Node(value);
            if(!tail){
                head = tail = newNode;
            } else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            count++;
        }

        void insertAtPosition(int position, int value){
            if(position<1 || position > count+1) {
                cout<<"Invalid position.\n";
                return;
            }

            Node* newNode = new Node(value);

            if(position == 1){
                newNode->next = head;
                if(head) head->prev = newNode;
                head = newNode;
                if(!tail) tail = newNode;
            } else if(position == count+1){
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else{
                Node* temp = head;
                for(int i=1; i < position-1; i++)
                    temp = temp->next;

                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
            }
            count++;
            cout<<"Inserted "<<value<<" at position "<<position<<"\n";
        }

        void deleteValue(int value){
            Node* temp = head;
            while(temp && temp->data != value)
                temp = temp->next;

            if(!temp){
                cout<<"Value "<<value<<" not found!\n";
                return;
            }

            if(temp == head)
                head = head->next;
            if(temp == tail)
                tail = tail->prev;

            if(temp->prev)
                temp->prev->next = temp->next;
            if(temp->next)
                temp->next->prev = temp->prev;

            delete temp;
            count--;
            cout<<"Deleted value: "<<value<<"\n";
        }

        void updateValue(int oldValue, int newValue){
            Node* temp = head;
            while(temp && temp->data != oldValue)
                temp = temp->next;

            if(!temp){
                cout<<"Value "<<oldValue<<" not found.\n";
                return;
            }

            temp->data = newValue;
            cout<<"Updated value "<<oldValue<<" to "<<newValue<<"\n";
        }

        void printForward(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void printBackward(){
            Node* temp = tail;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
            cout<<endl;
        }

        void displayCount(){
            cout<<"Total number of nodes: "<<count<<endl;
        }
};

int main(){
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    cout<<"Forward List:\n";
    list.printForward();

    cout<<"Backward List:\n";
    list.printBackward();

    list.displayCount();

    cout<<"Inserting 12 at position 3:\n";
    list.insertAtPosition(4, 12);
    list.printForward();

    cout<<"Deleting value 10:\n";
    list.deleteValue(10);
    list.printForward();

    cout<<"Updating value 20 to 7:\n";
    list.updateValue(15, 99);
    list.printForward();

    list.displayCount();
}
