#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
using namespace std;

//front
//pop
//push
//empty

int main(){
    queue <char> q;
    string old_string, new_string="";
    cin>>old_string;

    int char_count[26];
    for(int i=0;i<26;i++){
        char_count[i] = 0;
    }

    for(int i=0;i<old_string.length();i++){

        char_count[old_string[i]-'a']++;

        if(char_count[old_string[i]-'a'] <= 1)q.push(old_string[i]);

        while(!q.empty() && char_count[q.front()-'a'] > 1){
            q.pop();

        }



        if(!q.empty()) new_string += q.front();
        else new_string+= '#';

    }

    cout<<new_string<<endl;
}
