#include<iostream>
#include<vector>
using namespace std;

class priorityQueue{
    vector<int> heap;

    void heapifyUp(int i){
        while(i > 0){
            int parent = (i - 1)/2;
            if(heap[parent] < heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i){
        int size = heap.size();
        while(true){
            int largest = i;
            int left = 2*i +1;
            int right = 2*i +2;

            if(left<size && heap[left] > heap[largest]){
                largest = left;
            } else if(right<size && heap[right] > heap[largest]){
                largest = right;
            }

            if(largest != i){
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    int top() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return -1; 
        }
        return heap[0];
    }

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        for (int val : heap) cout << val << " ";
        cout << "\n";
    }
};

int main() {
    priorityQueue pq;

    pq.push(10);
    pq.push(40);
    pq.push(30);
    pq.push(50);
    pq.push(20);

    cout << "Current Queue: ";
    pq.display();

    cout << "Top element: " << pq.top() << "\n";

    pq.pop();
    cout << "After pop: ";
    pq.display();
}

