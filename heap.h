//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] =idx;
        int pos = size;
        size++;
        upheap(pos, weightArr);

        }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
    if(size == 0) {

        return -1;
}
    int root = data[0];
    size--;
    data[0] = data[size];
    downheap(0, weightArr);
    return root;

    }

void upheap(int pos, int weightArr[]) {
    while(pos>0){
        int parent = (pos-1)/2;
    if(weightArr[data[pos]] >= weightArr[data[parent]])
    break;
    std::swap(data[pos] , data[parent]);
    pos = parent;

}

        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        while(pos < size){
            int left = (pos*2)+1;
            int right = (pos*2)+2;
            int smallestChild = pos;

           if(left < size && weightArr[data[left]] < weightArr[data[smallestChild]]){
        smallestChild = left;}
        if(right<size && weightArr[data[right]] < weightArr[data[smallestChild]]){
        smallestChild = right;}
if(smallestChild == pos)
break;
std::swap(data[pos] ,data[smallestChild]);
pos = smallestChild;
}
        // TODO: swap parent downward while larger than any child
    }
};

#endif