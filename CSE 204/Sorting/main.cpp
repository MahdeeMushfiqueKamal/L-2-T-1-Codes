#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include<time.h>
#define RND 0
#define ASC 1
#define DSC 2


using namespace std;
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

void mergeArray(int arr[], int l,int mid, int r);
void mergeSort(int arr[], int l, int r);
int pivot(int arr[], int l, int r);
int * randomNumbers(int n, int order);
void quickSort(int arr[], int l, int r){//l and r inclusive
    //cout<<"quicksort "<<l<<" , "<<r<<" called"<<endl;
    if(l < r){
        int pvt = pivot(arr, l, r);
        quickSort(arr, l , pvt-1);
        quickSort(arr, pvt+1, r);
    }
}

int main()
{
    srand(time(0));
    clock_t before, after;
    int order ,n;
    while(1){
        cout<<"Enter n (0 to quit):\t";
        cin>>n;
        if(n==0) break;

        cout<<"Enter order (1- Ascending    2- Descending     0- Random):\t";
        cin>>order;

        if(!(order == ASC || order == DSC || order == RND)){
            cout<<"Invalid input"<<endl;
        }

        int *arr1 = randomNumbers(n, order);
        int *arr2 = new int[n];

        for(int i=0;i<n;i++){
            arr2[i] = arr1[i];
        }

        // merge sort
        before = clock();
        mergeSort(arr1,0,n-1);
        after = clock();
        cout<<"Time for sorting "<<n<<" numbers using merge sort is: "<<double( (after-before)* 1000000 / CLOCKS_PER_SEC)<<" micro second"<<endl;


        //quick sort
        before = clock();
        quickSort(arr2,0,n-1);
        after = clock();
        cout<<"Time for sorting "<<n<<" numbers using quick sort is: "<<double( (after-before)* 1000000 / CLOCKS_PER_SEC)<<" micro second"<<endl;

//        cout<<"\nAfter Sorting: \n";
//        for(int i=0;i<n;i++)cout<<arr1[i]<<"    "<<arr2[i]<<endl;
//        cout<<endl<<endl;

        delete []arr1;
        delete []arr2;

    }
    return 0;
}

void mergeSort(int arr[], int l, int r){
    if(l>=r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    mergeArray(arr, l, mid, r);

}

void mergeArray(int arr[], int l,int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r-mid;

    int temp1[n1], temp2[n2];

    for(int i=0;i<n1;i++) temp1[i] = arr[l+i];
    for(int i=0;i<n2;i++)  temp2[i] = arr[mid+1 +i];


    int i=0,j=0,k=l;
    while(k<= r){
        if(i< n1 && j<n2 && temp1[i] <= temp2[j]) arr[k++] = temp1[i++];
        else if( i< n1 && j<n2 && temp1[i] > temp2[j]) arr[k++] = temp2[j++];
        else if(i == n1) arr[k++] = temp2[j++];
        else arr[k++] = temp1[i++];
    }
}

int pivot(int arr[], int l, int r){
    int pivot = l, i=l, j = r, temp;
    while(i<j){
        while(arr[i] <= arr[pivot] && i+1<=r) i++;
        while(arr[j] >= arr[pivot] && j-1>=l) j--;
        if(i<j){
            //swap(arr[i],arr[j]);
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap(arr[pivot],arr[j]);
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    return j;
}


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
