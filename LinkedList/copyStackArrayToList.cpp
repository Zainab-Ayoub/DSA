#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* createNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	
	return newNode;
}

Node* copyStackToList(int arr[], int size){
	Node* head = NULL;
	Node* tail = NULL;
	
	for(int i=0; i<size; i++){
		Node* newNode = createNode(arr[i]);
		if(!head){
			head=newNode;
			tail=newNode;
		} else{
			tail->next = newNode;
			tail = newNode; 
		}
	}
	return head;
}

void printList(Node* head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	int arr[5] = {1,2,3,4,5};
	Node* head = copyStackToList(arr, 5);
	cout<<"Values in List are: \n";
	printList(head);
}