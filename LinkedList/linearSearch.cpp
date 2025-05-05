#include<iostream>
using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5}, *ptr;
    ptr = arr;
    int x;
    cout<<"Enter a number you want to search: ";
    cin>>x;
    for(int i=0; i<5; i++){
        if(*(ptr+i) == x){
            cout<<"Value found at index: "<<i+1<<endl;
            return 0;
        }
    } cout<<"Value not found!"<<endl;
}