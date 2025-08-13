// open addressing

#include<iostream>
using namespace std;

class hashTable{
    static const int size = 10;
    int table[size];

    public:
        hashTable(){
            for(int i=0; i<size; i++)
                table[i] = -1;
        }
        int hashFunction(int key){
            return key % size;
        }

        void insert(int key){
            int index = hashFunction(key);
            while(table[index] != -1){
                index = (index+1) % size;
            }
            table[index] = key;
        }

        void display(){
            for(int i=0; i<size; i++)
                cout<<i<<": "<<table[i]<<"\n";
        }
};

int main(){
    hashTable obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.display();
}