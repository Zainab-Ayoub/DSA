#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int>umap;
    umap["apple"] = 3;
    umap["banana"] = 5;

    for(auto& p : umap){
        cout<<p.first<<" -> "<<p.second<<endl;
    }
}