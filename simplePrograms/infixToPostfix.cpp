#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '*' || c == '/'){
        return 3;
    }
    else if(c == '+' || c == '-'){
        return 2;
    }
    else{
        return -1;
    }
}

void toPostfix(string infix){
    // infix = infix + ")";
    string postfix = "";
    stack<char> stk;
    // stk.push('(') 
    for(int i = 0; i < infix.length(); i++){
        //char is an operand
        if(('a' <= infix[i] && infix[i] <= 'z') || ('A' <= infix[i] && infix[i] <= 'Z')){
            postfix += infix[i];
        }

        //char is (
        else if(infix[i] == '('){
            stk.push('(');
        }

        //char is ')'
        else if(infix[i] == ')'){
            while(stk.top() != '('){
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }

        //char is an operator
        else{
            while((!stk.empty() && prec(infix[i]) <= prec(stk.top()))){
                postfix += stk.top();
                stk.pop();
            }
            stk.push(infix[i]);
        }

    }
    while(!stk.empty()){
        postfix += stk.top();
        stk.pop();
    }
        cout<<postfix<<endl;
}

int main()
{
    string infix;
    cin >> infix;
    toPostfix(infix);
    return 0;
}
