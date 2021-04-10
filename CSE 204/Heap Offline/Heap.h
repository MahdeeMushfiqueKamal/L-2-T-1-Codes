#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<vector>
using namespace std;

class Heap
{
    public:
        Heap();
        Heap(int n);
        Heap(int A[], int n);
        Heap(vector<int>&v);
        void insert(int x);
        void deleteKey();
        int getMax();
        int size();

    private:
        int *arr;
        int len;
        int sz;
        void maxHeapify(int i);
};


void heapsort(vector<int>&v);

#endif // HEAP_H
