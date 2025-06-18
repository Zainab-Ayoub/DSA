#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList{
    private:
        Node* head;
        Node* tail;

    public:
        CircularLinkedList() : head(nullptr), tail(nullptr) {}

        void createFromUserInput(){
            int n, value;
            cout<<"Enter number of nodes: ";
            cin>>n;

            for(int i=0; i<n; ++i){
                cout<<"Enter value for node "<<i+1<<": ";
                cin>>value;
                insertAtEnd(value);
            }
        }

        void insertAtEnd(int value){
            Node* newNode = new Node(value);
            if(!head){
                head = tail = newNode;
                tail->next = head;
            } else{
                tail->next = newNode;
                tail = newNode;
                tail->next = head;
            }
        }

        void insertAtPosition(int position, int value){
            if(position<1){
                cout<<"Invalid position."<<endl;
                return;
            }

            Node* newNode = new Node(value);

            if(position == 1){
                if(!head){
                    head = tail = newNode;
                    tail->next = head;
                } else{
                    newNode->next = head;
                    head = newNode;
                    tail->next = head;
                }
                cout<<"Inserted "<<value<<" at position 1\n";
                return;
            }

            Node* temp = head;
            for (int i=1; i < position-1; ++i){
                temp = temp->next;
                if(temp == head){
                    cout<<"Position out of bounds.\n";
                    delete newNode;
                    return;
                }
            }

            newNode->next = temp->next;
            temp->next = newNode;

            if(temp == tail)
                tail = newNode;

            cout<<"Inserted "<<value<<" at position "<<position<<"\n";
        }

        void deleteValue(int value){
            if(!head){
                cout<<"List is empty!\n";
                return;
            }

            Node* curr = head;
            Node* prev = tail;

            do{
                if(curr->data == value){
                    if(curr == head){
                        if(head == tail){
                            delete head;
                            head = tail = nullptr;
                        } else{
                            head = head->next;
                            tail->next = head;
                            delete curr;
                        }
                    } else{
                        prev->next = curr->next;
                        if(curr == tail)
                            tail = prev;
                        delete curr;
                    }
                    cout<<"Deleted value "<<value<<"\n";
                    return;
                }
                prev = curr;
                curr = curr->next;
            } while(curr != head);

            cout<<"Value "<<value<<" not found!\n";
        }

        void updateValue(int oldValue, int newValue){
            if(!head){
                cout<<"List is empty!\n";
                return;
            }

            Node* temp = head;
            do{
                if(temp->data == oldValue){
                    temp->data = newValue;
                    cout<<"Updated "<<oldValue<<" to "<<newValue<<"\n";
                    return;
                }
                temp = temp->next;
            } while(temp != head);

            cout<<"Value "<<oldValue<<" not found!\n";
        }

        void display(){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }

            Node* temp = head;
            cout<<"Circular Linked List: ";
            do{
                cout<<temp->data<<" ";
                temp = temp->next;
            } while(temp != head);
            cout<<endl;
        }

        ~CircularLinkedList(){
            if(!head) return;

            Node* temp = head->next;
            while(temp != head){
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            delete head;
        }
};

int main(){
    CircularLinkedList list;
    list.createFromUserInput();
    list.display();

    cout<<"Inserting 100 at position 2:\n";
    list.insertAtPosition(2, 100);
    list.display();

    cout<<"Deleting value 100:\n";
    list.deleteValue(100);
    list.display();

    cout<<"Updating value 10 to 111:\n";
    list.updateValue(10, 111);
    list.display();
}
