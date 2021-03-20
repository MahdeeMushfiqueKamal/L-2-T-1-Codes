#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
void null_message();
class Array{
    int Size = 0;
    int Length = 0;
    string* Arr;
public:
    Array();
    Array(int n);

    Array(string A[],int n);

    //methods:
    Array getArray();
    int length(){return Length;}
    bool isEmpty(){return Length==0;}
    string getAnElement(int i);
    void add(string element);
    void add(int i,string element);
    void remove(string element);
    Array subArray(int start, int end);
    int* findIndex(string element);
    void showArray();
    void merge(string A1[],string A2[],int len1, int len2);
    void merge(Array A1, Array A2);

};

int main(){
    Array arrobj1,arrobj2(5);
    string A[]={"Name1","Name2","Name3"};
    Array arrobj3(A,3);

    cout<<"Lengths:  "<<endl;
    cout<<arrobj1.length()<<endl;
    cout<<arrobj2.length()<<endl;
    cout<<arrobj3.length()<<endl;

    arrobj3.showArray();

    cout<<"Arrobj1,empty?  "<<arrobj1.isEmpty()<<endl;
    cout<<"Arrobj3,empty?  "<<arrobj3.isEmpty()<<endl;


    for(int i=1;i<=8;i++){
        arrobj2.add("Hello");
    }
    arrobj2.add(4,"Dhrubo");
    arrobj2.add(3,"Kamal");
    arrobj2.add(0,"CSE");
    arrobj2.add(1,"OK");
    arrobj2.showArray();

    arrobj2.remove("Dhrubo");
    cout<<"Result after removing: "<<endl;
    arrobj2.showArray();

    arrobj1 = arrobj2.subArray(1,4);

    arrobj1.showArray();

    int *x = arrobj2.findIndex("Hello");
    while(*x != -1){
        cout<<*x<<" ";
        x++;
    }
    cout<<endl;
    string A1[]={"Apple","Google","Zebra"};
    string A2[]={"Ball","Cat","Dhrubo"};

    //merging two arrays of string
    arrobj1.merge(A1,A2,3,3);
    arrobj1.showArray();

    //merging two Array objects
    Array ArrA1(A1,3),ArrA2(A2,3);
    arrobj1.merge(ArrA1,ArrA2);
    arrobj1.showArray();
}


Array::Array(){
    Size = 16;
    Arr = new string[Size];
    if(Arr == NULL)null_message();
}

Array::Array(int n){
    Size = n;
    Arr = new string[Size];
    if(Arr == NULL)null_message();
}

Array::Array(string A[],int n){
    Size = n+16;
    Arr = new string[Size];
    if(Arr == NULL)null_message();

    for(int i=0;i<n;i++){
        string element = A[i];
        Arr[i] = element;
    }

    Length = n;
}


Array Array::getArray(){
    Array new_array(Size+16);
    for(int i=0;i<Size;i++){
        new_array.add(Arr[i]);
    }
    return new_array;
}

string Array:: getAnElement(int i){
    if(i<0 || i>=Size){
        cout<<"Index out of range exception"<<endl;
        exit(0);
    }
    return Arr[i];
}

void Array:: add(string element){
    if(Length < Size){
        Arr[Length++] = element;
    }
    else{
        //cout<<"Array is full, adding new space"<<endl;
        Size+=16;
        string *temp = new string[Size];
        if(temp == NULL)null_message();
        for(int i=0;i<Length;i++){
            temp[i] = Arr[i];
        }
        Arr = temp;
        Arr[Length++] = element;
    }
}

void Array::add(int i,string element){
    if(i<0 || i>=Size){
        cout<<"Index out of range exception"<<endl;
        exit(0);
    }
    Arr[i] = element;
}

void Array::remove(string element){
    int deleted =0;
    string *temp = new string[Size];
    if(temp == NULL)null_message();
    for(int i=0,j=0;i<Length;i++){
        if(Arr[i]!=element){
            temp[j++] = Arr[i];
        }
        else deleted++;
    }
    Arr = temp;
    Length -= deleted;
}


Array Array::subArray(int start, int end){
    int len = end - start + 1;
    Array sub_array(len);
    for(int i=start;i<=end;i++)sub_array.add(Arr[i]);
    return sub_array;

}

int* Array::findIndex(string element){
    int *p = new int[Length+1];
    if(p == NULL)null_message();
    int j=0;
    for(int i=0;i<Length;i++){
        if(Arr[i]==element){
            p[j++] = i;
        }
    }
    p[j]= -1;
    return p;
}

void Array::merge(string A1[],string A2[],int len1, int len2){
    delete Arr;
    Size = len1 + len2;
    Arr = new string[Size];
    if(Arr == NULL)null_message();
    Length= Size;

    for(int i=0,j=0,k=0;i<Size;i++){
        //watch(i)
        if(j==len1){
            Arr[i] = A2[k++];
        }
        else if(k==len2){
            Arr[i] = A1[j++];
        }
        else if(A1[j] <= A2[k]){
            Arr[i] = A1[j++];
        }
        else{
            Arr[i] = A2[k++];
        }
    }
}

void Array::merge(Array A1, Array A2){
    delete Arr;
    Size = A1.length() + A2.length();
    Arr = new string[Size];
    if(Arr == NULL)null_message();
    Length=Size;

    for(int i=0,j=0,k=0;i<Size;i++){
        if(j==A1.length()){
            Arr[i] = A2.getAnElement(k++);
        }
        else if(k==A2.length()){
            Arr[i] = A1.getAnElement(j++);
        }
        else if(A1.getAnElement(j) <= A2.getAnElement(k)){
            Arr[i] = A1.getAnElement(j++);
        }
        else{
            Arr[i] = A2.getAnElement(k++);
        }
    }
}

void Array::showArray(){
    for(int i=0;i<Length;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

void null_message(){
    cout<<"Allocated memory is NULL, Exiting Program..."<<endl;
    exit(0);
}
