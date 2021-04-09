#include<iostream>
#include<fstream>
#include<cstdio>
#include<queue>
#include<ctime>
#include <stdlib.h>
//#include "heap.h" //You need to implement this.

using namespace std;
class Heap{
    int *arr;
    int len;
    int sz;
    void maxHeapify(int i){
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
public:
    Heap(int n){
        arr = new int[n+1];
        sz = n+1;
        len = 0;
    }

    void insert(int x){
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
    }

    void deleteKey(){
        //swap arr[1], arr[len]
        int temp;
        temp = arr[1];
        arr[1] = arr[len];
        arr[len] = temp;
        len--;
        maxHeapify(1);


    }

    int getMax(){
        if (len == 0){cout<<"Heap is empty"<<endl;}
        return arr[1];
    }
    int size(){return len;}

    void test(){
        for(int i=0;i<sz;i++){cout<<arr[i]<<" ";}
        cout<<endl;
    }

};



int main()
{
    priority_queue<int>pq;
    vector<int>numbers;

    //reading from file begins. Loading all the numbers in the vector
    string myText;
    ifstream MyReadFile("numbers.txt");
    while (getline (MyReadFile, myText))
      numbers.push_back(atoi(myText.c_str()));
    MyReadFile.close();
    //reading from file ends

    clock_t time_of_insertion_in_pq = clock();

    for(int i = 0; i < numbers.size(); i++)
        pq.push(numbers[i]);

    cout << "Inserting " << pq.size() << " numbers in priority queue takes "<< float(clock() - time_of_insertion_in_pq) / CLOCKS_PER_SEC << " seconds\n";

    Heap h(numbers.size());// Passing the maximum size of the heap as parameter to constructor. You need to implement this.

    clock_t time_of_insertion_in_my_heap = clock();

    for(int i = 0; i < numbers.size(); i++)
        h.insert(numbers[i]); // inserting numbers in the heap. You need to implement this.

    cout << "Inserting " << h.size() << " numbers in my heap takes "<< float(clock() - time_of_insertion_in_my_heap) / CLOCKS_PER_SEC << " seconds\n"; // You need to implement size() function

    cout<<pq.top()<<endl;
    cout<<h.getMax()<<endl; // returning the maximum number of the heap. You need to implement this.

    clock_t time_of_deletion_in_pq = clock();

    int number_of_numbers = pq.size();

    for(int i = 0; i < number_of_numbers; i++)
        pq.pop();

    cout << "Deleting " << numbers.size() << " numbers from priority queue takes "<< float(clock() - time_of_deletion_in_pq) / CLOCKS_PER_SEC << " seconds\n";

    clock_t time_of_deletion_in_my_heap = clock();

    for(int i = 0; i < number_of_numbers; i++)
        h.deleteKey(); // deleting the root of the heap. You need to implement this.

    cout << "Deleting " << numbers.size() << " numbers from my heap takes "<< float(clock() - time_of_deletion_in_my_heap) / CLOCKS_PER_SEC << " seconds\n";

    h.test();
//    heapsort(numbers); // You need to implement this function in heap.h. You should use the heap class implemented by you to do this. Hint: the function declaration should be void heapsort(vector<int>&v);
    // Now, "numbers" vector contains the numbers in descending order
    return 0;
}
