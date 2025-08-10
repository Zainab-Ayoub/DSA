#include<iostream>
#include<string>
using namespace std;

const int tableSize = 10;

int hashFunction(string key){
    int sum = 0;
    for(char c : key){
        sum += c;
    }
    return sum % tableSize;
}

int main(){
    string hashTable[tableSize];

    string keys[] = {"apple", "banana", "orange"};
    for(string key : keys){
        int index = hashFunction(key);
        hashTable[index] = key;
    }

    cout<<"Hash Table contents:\n";
    for(int i = 0; i < tableSize; i++){
        cout<<i<<" : "<<hashTable[i]<<endl;
    }
}