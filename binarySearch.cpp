#include<iostream>
using namespace std;

int binarySearch(int* arr, int size, int search){
    int start = 0, end = size-1;

    while(start <= end){
        int mid = (start + end) / 2;
        int value = *(arr + mid);

        if(value == search){
            return mid;  
        } else if(value < search){
            start = mid + 1;
        } else{
            end = mid - 1;
        }
    }
    return -1;  
}

int main() {
    const int size = 5;
    int arr[size], search;

    cout<<"Enter "<<size<<" elements in **sorted order**:\n";
    for(int i=0; i<size; i++){
        cin>>*(arr + i);
    }

    cout<<"Enter a value you want to search: ";
    cin>>search;

    int index = binarySearch(arr, size, search);

    if(index != -1){
        cout<<"Value found at position: "<<index+1<<endl;
    } else{
        cout<<"Value not found!"<<endl;
    }
}