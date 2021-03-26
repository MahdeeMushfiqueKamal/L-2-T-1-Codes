#include<bits/stdc++.h>
using namespace std;
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl;

int main(){
    string expression;
    cin>>expression;

    //num of openning brackets == number of closing bracket
    int open =0;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='(')open++;
        else if(expression[i]==')')open--;

        if(open < 0){
            cout<<"Invalid Expression"<<endl;
            return 0;
        }
    }
    if(open != 0){
        cout<<"Invalid Expression"<<endl;
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
    cout<<"After Removing Unary Operator: "<<expression<<endl;


    //Dijkstra's Two Stack;
    stack<char> ops;
    stack<int> value;

    for(int i=0;i<expression.length();i++){
        if(expression[i]>='0' || expression[i]<='9'){
            value.push(expression[i]-'0');
        }
        else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' )ops.push(expression[i]);
        else if(expression[i] == ')'){
            int rhs = value.top(); value.pop();
            int lhs = value.top(); value.pop();
            watch(lhs)
            watch(rhs)
            char sign = ops.top();ops.pop();
            watch(sign)
            if(sign == '+') value.push(lhs + rhs);
            else if(sign == '-') value.push(lhs - rhs);
            else if(sign == '*') value.push(lhs * rhs);
            else if(sign == '/') value.push(lhs / rhs);
        }
    }
    cout<<value.top()<<endl;
    main();
}
