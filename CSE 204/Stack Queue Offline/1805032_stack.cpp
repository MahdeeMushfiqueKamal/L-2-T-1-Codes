#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
int presidence(char c);
int stringtonum(string str);

class IntStack{
    int *arr;
    int top = 0;
    int Capasity = 100;
public:
    IntStack(){
        arr = new int[Capasity];
    }
    void Push(int x);
    void Pop(){
        if(top>0)top--;
        else{
            cout<<"Stack is empty, Can't pop";
            return;
        }
    }
    int Top(){
        if(top>0)return arr[top-1];
        else{
            cout<<"Stack is empty. Nothing on Top";
            return 0;
        }
    }
    int Size(){return top;}
    bool Empty(){return top==0;}
};

class CharStack{
    char *arr;
    int top = 0;
    int Capasity = 100;
public:
    CharStack(){
        arr = new char[Capasity];
    }
    void Push(char x);
    void Pop(){
        if(top>0)top--;
        else{
            cout<<"Stack is empty, Can't pop";
            return;
        }
    }
    char Top(){
        if(top>0)return arr[top-1];
        else{
            cout<<"Stack is empty. Can't show Top";
            return 0;
        }
    }
    int Size(){return top;}
    bool Empty(){return top==0;}
};

int main(){
    string expression;
    cin>>expression;

    //num of openning brackets == number of closing bracket
    int open =0;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='(')open++;
        else if(expression[i]==')')open--;

        if(open < 0){
            cout<<"Not valid."<<endl;
            return 0;
        }
    }
    if(open != 0){
        cout<<"Not valid."<<endl;
        return 0;
    }

    //tackling Unary Operator
    IntStack Unary;
    for(int i=0;i<expression.length()-1;i++){
        if(expression[i]=='(' && expression[i+1]=='-'){
            Unary.Push(i+1);
        }
    }

    while(!Unary.Empty()){
        int last_entry = Unary.Top();
        Unary.Pop();
        string temp = expression.substr(0,last_entry) + '0' + expression.substr(last_entry);
        expression = temp;
    }
    //cout<<"After Removing Unary Operator: "<<expression<<endl;

    //Two Stack Algo:
    CharStack ops;
    IntStack value;
    for(int i=0;i<expression.length();i++){
        //openning bracket
        if(expression[i]=='(') ops.Push(expression[i]);

        //value
        else if(expression[i]>='0' && expression[i]<='9'){
            int num_len = 1;
            while(expression[i+ num_len]>='0' && expression[i+num_len]<='9')num_len++;
            int num = stringtonum(expression.substr(i,num_len));
            i+=(num_len-1);
            //watch(num)
            value.Push(num);
        }

        //binary Operand
        else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' ){
            if(!ops.Empty() && presidence(ops.Top()) > presidence(expression[i]) ){
                if(value.Empty()){
                    cout<<"Not valid."<<endl;
                    return 0;
                }
                int rhs = value.Top(); value.Pop();
                if(value.Empty()){
                    cout<<"Not valid."<<endl;
                    return 0;
                }
                int lhs = value.Top(); value.Pop();

                if(ops.Top()=='*') value.Push(lhs*rhs);
                else if(ops.Top()=='/') value.Push(lhs/rhs);

                ops.Pop();
                ops.Push(expression[i]);
            }
            else ops.Push(expression[i]);
        }
        //closing bracket
        else if(expression[i]==')'){
            while(ops.Top()!='('){
                char c = ops.Top();ops.Pop();
                if(value.Empty()){
                    cout<<"Not valid."<<endl;
                    return 0;
                }
                int rhs = value.Top(); value.Pop();
                if(value.Empty()){
                    cout<<"Not valid."<<endl;
                    return 0;
                }
                int lhs = value.Top(); value.Pop();

                if(c == '+') value.Push(lhs+rhs);
                else if(c == '-') value.Push(lhs-rhs);
                else if(c == '*') value.Push(lhs*rhs);
                else if(c == '/') value.Push(lhs/rhs);
            }
            ops.Pop();
        }
    }
    //End For
    while(!ops.Empty()){
        char c = ops.Top();ops.Pop();
        if(value.Empty()){
            cout<<"Not valid."<<endl;
            return 0;
        }
        int rhs = value.Top(); value.Pop();
        if(value.Empty()){
            cout<<"Not valid."<<endl;
            return 0;
        }
        int lhs = value.Top(); value.Pop();

        if(c == '+') value.Push(lhs+rhs);
        else if(c == '-') value.Push(lhs-rhs);
        else if(c == '*') value.Push(lhs*rhs);
        else if(c == '/') value.Push(lhs/rhs);
    }

    if(value.Size()==1)cout<<"Valid expression, Computed value:  "<< value.Top();
    else{
        cout<<"Not valid."<<endl;
    }
    return 0;
}





int presidence(char c){
    if(c=='*' || c=='/')return 2;
    else if (c=='+' || c=='-') return 1;
    else return 0;
}


int stringtonum(string str){
    int num=0;
    for(int i=0;i<str.length(); i++){
        num*=10;
        num += int(str[i]-'0');
    }
    return num;
}


void IntStack::Push(int x){
    if(top<Capasity){
        arr[top++] = x;
    }
    else{
        Capasity*=2;
        int *temp = new int[Capasity];
        for(int i=0;i<top;i++){
            temp[i]=arr[i];
        }
        delete []arr;
        arr = temp;
        arr[top++] = x;
    }
}


void CharStack::Push(char x){
    if(top<Capasity){
        arr[top++] = x;
    }
    else{
        Capasity*=2;
        char *temp = new char[Capasity];
        for(int i=0;i<top;i++){
            temp[i]=arr[i];
        }
        delete []arr;
        arr = temp;
        arr[top++] = x;
    }
}
