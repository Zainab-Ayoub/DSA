#include<iostream>
#include<list>
using namespace std;

class hashTable{
    static const int size = 10;
    list<int> table[size];

    int hashFunction(int key){
        return key % size;
    }

    public:
        void insert(int key){
            table[hashFunction(key)].push_back(key);
        }

        void display(){
            for(int i=0; i<size; i++){
                cout<<i<<" ";
                for(int val : table[i])
                    cout<<val<<"->";
                cout<<"NULL\n";    
            }
        }
};

int main(){
    hashTable obj;
    obj.insert(12);
    obj.insert(22);
    obj.insert(32);
    obj.display();
}