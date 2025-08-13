// open addressing

#include<iostream>
using namespace std;

class hashTable{
    static const int size = 10;
    int table[size];

    public:
        hashTable(){
            for(int i=0; i<size; i++){
                table[i] = -1;
            }
        }

        int hashFunction(int key){
            return key % size;
        }

        void insert(int key){
            int index = hashFunction(key);
            int i = 0;
            while(table[(index + i*i) % size] != -1){
                i++;
            }
        table[(index + i*i) % size] = key;
        }

        void display(){
            for(int i=0; i<size; i++){
                cout<<i<<": "<<table[i]<<endl;
            }
        }
};

int main(){
    hashTable obj;
    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.display();
}