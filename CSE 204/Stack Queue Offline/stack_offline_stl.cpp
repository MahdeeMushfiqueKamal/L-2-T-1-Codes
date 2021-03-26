#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;
int presidence(char c);
int stringtonum(string str);

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
    stack<int> Unary;
    for(int i=0;i<expression.length()-1;i++){
        if(expression[i]=='(' && expression[i+1]=='-'){
            Unary.push(i+1);
        }
    }

    while(!Unary.empty()){
        int last_entry = Unary.top();
        Unary.pop();
        string temp = expression.substr(0,last_entry) + '0' + expression.substr(last_entry);
        expression = temp;
    }
    //cout<<"After Removing Unary Operator: "<<expression<<endl;

    //Infix to postfix:
    stack<char> ops;
    stack<int> value;
    for(int i=0;i<expression.length();i++){
        //openning bracket
        if(expression[i]=='(') ops.push(expression[i]);

        //value
        else if(expression[i]>='0' && expression[i]<='9'){
            int num_len = 1;
            while(expression[i+ num_len]>='0' && expression[i+num_len]<='9')num_len++;
            int num = stringtonum(expression.substr(i,num_len));
            i+=(num_len-1);
            //watch(num)
            value.push(num);
        }

        //binary Operand
        else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' ){
            if(!ops.empty() && presidence(ops.top()) > presidence(expression[i]) ){
                if(value.empty()){
                    cout<<"Not valid."<<endl;
                    return 0;
                }
                int rhs = value.top(); value.pop();
                if(value.empty()){
                    cout<<"Not valid."<<endl;
                    return 0;
                }
                int lhs = value.top(); value.pop();

                if(ops.top()=='*') value.push(lhs*rhs);
                else if(ops.top()=='/') value.push(lhs/rhs);

                ops.pop();
                ops.push(expression[i]);
            }
            else ops.push(expression[i]);
        }
        //closing bracket
        else if(expression[i]==')'){
            while(ops.top()!='('){
                char c = ops.top();ops.pop();
                if(value.empty()){
                    cout<<"Not valid."<<endl;
                    return 0;
                }
                int rhs = value.top(); value.pop();
                if(value.empty()){
                    cout<<"Not valid."<<endl;
                    return 0;
                }
                int lhs = value.top(); value.pop();

                if(c == '+') value.push(lhs+rhs);
                else if(c == '-') value.push(lhs-rhs);
                else if(c == '*') value.push(lhs*rhs);
                else if(c == '/') value.push(lhs/rhs);
            }
            ops.pop();
        }
    }
    //End For
    while(!ops.empty()){
        char c = ops.top();ops.pop();
        if(value.empty()){
            cout<<"Not valid."<<endl;
            return 0;
        }
        int rhs = value.top(); value.pop();
        if(value.empty()){
            cout<<"Not valid."<<endl;
            return 0;
        }
        int lhs = value.top(); value.pop();

        if(c == '+') value.push(lhs+rhs);
        else if(c == '-') value.push(lhs-rhs);
        else if(c == '*') value.push(lhs*rhs);
        else if(c == '/') value.push(lhs/rhs);
    }

    if(value.size()==1)cout<<"Valid expression, Computed value:  "<< value.top();
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
