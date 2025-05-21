#include<iostream>
using namespace std;

class stack{
	public:
		int stackArray[10], sp;
		stack(){
			sp = -1;
		}
		void push(int val){
			sp++;
			if(sp >= 10){
				cout<<"Error!\n";
			} stackArray[sp] = val;
		}
		int pop(){
			if(sp == -1){
				cout<<"Error\n";
			} return stackArray[sp--];
		}
};

int main(){
	stack obj;
	int choice;
	
	do{
		cout<<"Press 1 to push a value.\nPress 2 to pop a value.\nPress 0 to Exit.\n";
		cin>>choice;
		switch(choice){
			case 1:
				int x;
				cout<<"Enter a value: ";
				cin>>x;
				obj.push(x);
				break;
				
			case 2:
				cout<<obj.pop();
				break;
				
			case 0:
				cout<<"Program Exited Successfully!\n";
				break;
				
			default:
				cout<<"Error!\n";	
		}			
	} while(choice != 0);
}