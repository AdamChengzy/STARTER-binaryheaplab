// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using namespace std;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){

for (auto it = start; it != end; it++) {
        vdata.push_back(*it);
    }
for (int i = vdata.size()/2 - 1; i >= 0; i--) {

        int index = i;
        int size = vdata.size();

        while (true) {
            int left = 2*index + 1;
            int right = 2*index + 2;
            int smallest = index;
            if (left < size && vdata[left] < vdata[smallest])
                smallest = left;
            if (right < size && vdata[right] < vdata[smallest])
                smallest = right;
            if (smallest == index)
                break;
            swap(vdata[index], vdata[smallest]);
            index = smallest;
        }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push (int value){
 vdata.push_back(value);
    int index = vdata.size() - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (vdata[parent] <= vdata[index])
            break;
        swap(vdata[parent], vdata[index]);
        index = parent;
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
if (empty()) return;

    vdata[0] = vdata.back();
    vdata.pop_back();

    int index = 0;
    int size = vdata.size();

    while (true) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;
        if (left < size && vdata[left] < vdata[smallest])
            smallest = left;
        if (right < size && vdata[right] < vdata[smallest])
            smallest = right;
        if (smallest == index)
            break;
        swap(vdata[index], vdata[smallest]);
        index = smallest;
    }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    
