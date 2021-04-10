#include "Heap.h"
#include<iostream>
using namespace std;

Heap::Heap(){
    arr = new int[20+1];
    sz = 21;
    len = 0;
}

Heap::Heap(int n){
    arr = new int[n+1];
    sz = n+1;
    len = 0;
}

Heap::Heap(int A[], int n){
    arr = new int[n+1];
    sz = n+1;
    len = 0;

    for(int i=0;i<n;i++){
        arr[i+1] = A[i];
        len++;
    }

    for(int i=len/2; i>= 1; i--){
        maxHeapify(i);
    }
}

Heap::Heap(vector<int>&v){
    sz = v.size()+1;
    arr = new int[sz];
    len = 0;
    for(int i=0;i<v.size();i++){
        arr[i+1] = v[i];
        len++;
    }

    for(int i=len/2; i>= 1; i--){
        maxHeapify(i);
    }
}

void Heap::insert(int x){
    if( len+1 < sz){
        arr[++len] = x;
        //adjusting with parents
        int i = len,parent,temp;
        while(i/2 >= 1){
            parent = i/2;
            if(arr[i] > arr[parent]){
                temp = arr[i];
                arr[i] = arr[parent];
                arr[parent] = temp;
            }
            i = parent;
        }
    }
    else{
        sz*=2;
        int *arr_new = new int[sz];
        for(int i=1;i<len;i++){
            arr_new[i] = arr[i];
        }
        delete []arr;
        arr = arr_new;

        arr[++len] = x;
        //adjusting with parents
        int i = len,parent,temp;
        while(i/2 >= 1){
            parent = i/2;
            if(arr[i] > arr[parent]){
                temp = arr[i];
                arr[i] = arr[parent];
                arr[parent] = temp;
            }
            i = parent;
        }
    }
}

void Heap::deleteKey(){
    //swap arr[1], arr[len]
    int temp;
    temp = arr[1];
    arr[1] = arr[len];
    arr[len] = temp;
    len--;
    maxHeapify(1);
}

void Heap::maxHeapify(int i){
    int max_idx,temp;
    while(i<= len){
        max_idx = i;
        //left child check
        if(2*i <= len && arr[2*i] > arr[max_idx]){
            max_idx = 2*i;
        }

        //right child check
        if(2*i+1 <= len && arr[2*i+1] > arr[max_idx]){
            max_idx = 2*i+1;
        }

        if(max_idx != i){
            //swap max_idx and i
            temp = arr[max_idx];
            arr[max_idx] = arr[i];
            arr[i] = temp;
            i = max_idx;
        }
        else break;
    }
}

int Heap::getMax(){
    if (len == 0){cout<<"Heap is empty"<<endl;}
    return arr[1];
}
int Heap::size(){return len;}


void heapsort(vector<int>&v){
    Heap heapObj(v);
    int n = v.size();
    v.clear();
    for(int i=0;i<n;i++){
        v.push_back(heapObj.getMax());
        heapObj.deleteKey();
    }
}
