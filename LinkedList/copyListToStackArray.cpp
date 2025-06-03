#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int val): data(val), next(NULL){};
};

void copyToStack(Node* head){
	int stack[5], i=0;
	while(head){
		stack[i] = head->data;
		cout<<stack[i++]<<" ";                                                                                                   
		head = head->next;
	}
}

int main(){
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	cout<<"Values in Stack: ";
	copyToStack(head);
}