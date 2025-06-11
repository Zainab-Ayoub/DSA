#include <iostream>
using namespace std;

struct ServiceCentre{
    string data;
    int id;
    ServiceCentre* next;

    ServiceCentre(string name, int customerId) : data(name), id(customerId), next(nullptr) {}
};

ServiceCentre* front = nullptr;
ServiceCentre* rear = nullptr;
int customerID = 1;

void enqueueCustomer(const string& name){
    ServiceCentre* newCustomer = new ServiceCentre(name, customerID++);
    if(!front){
        front = rear = newCustomer;
    } else{
        rear->next = newCustomer;
        rear = newCustomer;
    }
    cout<<"Customer "<<newCustomer->id<<" ("<<name<<") added to the queue!\n";
}

void dequeueCustomer(){
    if(!front){
        cout << "Queue is empty!\n";
        return;
    }
    ServiceCentre* temp = front;
    cout<<"Customer "<<temp->id<<" ("<<temp->data<<") has been served.\n";
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void viewQueue(){
    if(!front){
        cout<<"Queue is empty!\n";
        return;
    }
    ServiceCentre* temp = front;
    cout<<"Current Queue:\n";
    while(temp){
        cout<<temp->id<<": "<<temp->data << "\n";
        temp = temp->next;
    }
}

void prioritizeCustomer(int id){
    if (!front) {
        cout << "Queue is empty!\n";
        return;
    }

    ServiceCentre* temp = front;
    ServiceCentre* prev = nullptr;

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if(!temp){
        cout<<"Customer with ID "<<id<<" not found in the queue.\n";
        return;
    }

    if(temp == front){
        front = front->next;
        if (!front) rear = nullptr;
    } else{
        prev->next = temp->next;
        if (temp == rear) rear = prev;
    }

    cout<<"PRIORITY SERVED: Customer "<<temp->id<<" ("<<temp->data<<") has been served as a priority.\n";
    delete temp;
}

int main(){
    int choice;
    string name;
    int id;

    do {
        cout<<"\nCustomer Service Centre\n";
        cout<<"1. Add customer to the queue\n";
        cout<<"2. Serve next customer in queue\n";
        cout<<"3. Prioritize a customer by ID and serve\n";
        cout<<"4. View the queue\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore(); 

        switch(choice){
            case 1:
                cout<<"Enter customer name: ";
                getline(cin, name);
                enqueueCustomer(name);
                break;

            case 2:
                dequeueCustomer();
                break;

            case 3:
                cout<<"Enter Customer ID to prioritize: ";
                cin>>id;
                prioritizeCustomer(id);
                break;

            case 4:
                viewQueue();
                break;

            case 0:
                cout<<"Program exited successfully!\n";
                break;

            default:
                cout<<"Invalid choice!\n";
        }
    } while(choice != 0);

}
