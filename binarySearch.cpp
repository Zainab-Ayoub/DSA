#include<iostream>
using namespace std;

int main(){
    int arr[5]= {10, 20, 30, 40, 50}, *ptr, x;
    int start = 0, end = 4;
    int flag = -1; 
    ptr = arr;
    cout<<"Enter a value you want to search: ";
    cin>>x;
    while(start <= end){
        int mid = (start + end)/2;
        int value = *(ptr + mid);

        if(value == x){
            flag = mid;
            cout<<"Value found at index: "<<flag<<endl;
            return 0;
        } else if(value < x][]){
            start = mid + 1;
        } else{
            end = mid - 1;
        }
    }
    if(flag == -1){
        cout<<"Value not found!"<<endl;
    }
}