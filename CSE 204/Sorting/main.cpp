#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

#define ASC 0
#define DSC 1
#define RND 2

//Implement Quicksort and Merge sort algorithms for sorting a number of integers in ascending order.

int * randomNumbers(int n, int order){
    int *arr = new int[n];
    arr[0] = rand() * (rand())%100 + (rand())%15;

    if(order == RND){
        for (int i=1;i<n;i++) arr[i] = rand();
    }

    else if(order == ASC){
        for (int i=1;i<n;i++) arr[i] = arr[i-1] + (rand()%100 + 1);
    }

    else if(order == DSC){
        for (int i=1;i<n;i++) arr[i] = arr[i-1] - (rand()%100 + 1);
    }


    return arr;
}

int main()
{
    srand(time(0));

    int order ,n;
    while(1){
        cout<<"Enter n (0 to quit):\t";
        cin>>n;
        if(n==0) break;

        cout<<"Enter order (0 - Ascending    1- Descending     2- Random):\t";
        cin>>order;

        if(!(order == ASC || order == DSC || order == RND)){
            cout<<"Invalid input"<<endl;
        }

        int *arr1 = randomNumbers(n, order);
        int *arr2 = new int[n];

        for(int i=0;i<n;i++){
            arr2[i] = arr1[i];
        }
        cout<<"\nAfter Sorting: \n";
        for(int i=0;i<n;i++)cout<<arr1[i]<<"    "<<arr2[i]<<endl;
        cout<<endl<<endl;

    }
    return 0;
}
