#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

using namespace std;

class CharQueue{
    char *arr;
    int capasity = 10;
    int head=0;
    int tail=-1;
    int sz = 0;

public:
    CharQueue(){
        arr = new char[capasity];
    }
    void Push(char x){
        if (sz<capasity){
            tail = (tail+1)%capasity;
            arr[tail] = x;
            sz++;
        }
        else{
            char *temp = new char [capasity*2];
            for(int i=0;i< capasity; i++){
                temp[i] = arr[i];
            }
            delete []arr;
            arr = temp;
            capasity*=2;
            tail = (tail+1)%capasity;
            arr[tail] = x;
            sz++;
        }
    }
    char Front(){
        if(sz==0){
            cout<<"Queue is Empty. Can't provide front"<<endl;
            return 0;
        }
        else{
            return arr[head];
        }
    }
    bool Empty(){return head == tail +1;}
    void Pop(){
        if(sz==0){
            cout<<"Queue is Empty. Can't pop"<<endl;
            return;
        }
        head = (head+1)%capasity;
        sz--;
    }
    int Size(){return sz;}
};

int main(){
    CharQueue q;
    string old_string, new_string="";
    cin>>old_string;

    int char_count[26];
    for(int i=0;i<26;i++){
        char_count[i] = 0;
    }

    for(int i=0;i<old_string.length();i++){

        char_count[old_string[i]-'a']++;

        if(char_count[old_string[i]-'a'] <= 1)q.Push(old_string[i]);

        while(!q.Empty() && char_count[q.Front()-'a'] > 1){
            q.Pop();

        }



        if(!q.Empty()) new_string += q.Front();
        else new_string+= '#';

    }

    cout<<new_string<<endl;
}
