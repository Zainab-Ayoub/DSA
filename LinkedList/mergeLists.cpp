#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int val): data(val), next(NULL){} 	
}; 

Node* mergeTwoLists(Node* head1, Node* head2){
	Node* temp = head1;
	while(temp->next){
		temp = temp->next;
	} temp->next = head2;
	return head1;
}

int main(){
	Node* head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(4);
	
	Node* head2 = new Node(11);
	head2->next = new Node(22);
	head2->next->next = new Node(33);
	head2->next->next->next = new Node(44);
	
	head1 = mergeTwoLists(head1, head2);
	
	while(head1){
		cout<<head1->data<<" ";
		head1 = head1->next;
	}
}