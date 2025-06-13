#include<iostream>
using namespace std;

int linearSearch(int* arr, int size, int search){
    for(int i=0; i<size; i++){
        if(*(arr+i) == search){
            return i;  
        }
    }
    return -1; 
}

int main(){
    const int size = 5;
    int arr[size], search;

    cout<<"Enter "<<size<<" elements:\n";
    for(int i=0; i<size; i++){
        cin>>*(arr+i); 
    }

    cout<<"Enter a number you want to search: ";
    cin>>search;

    int index = linearSearch(arr, size, search);

    if(index != -1){
        cout<<"Value found at position: "<<index+1<<endl;
    } else{
        cout<<"Value not found!"<<endl;
    }
}