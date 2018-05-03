#include <iostream>
#include<stack>
#include<string>
using namespace std;

//code for infix to postfix

bool isoperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

int postfix(string s){
    
    string res;
    stack <char> stack;
    int len = s.length();
    for( int i=0;i<len;i++){
        if(s[i] == ' ' || s[i] == ',') continue; 
        if(isoperand(s[i])){
            res+=s[i];
        }
        else if(s[i]=='('){
            stack.push(s[i]);
        }
        else if(s[i]==')'){
            while(!stack.empty()&&stack.top()!='('){
                res+=stack.top();
                stack.pop();
                
            }
            stack.pop();
        }
        else{
            while (!stack.empty() &&stack.top()!='('&& precedence(s[i]) <= precedence(stack.top())){
                res+=stack.top();
                stack.pop();
                
            }
            stack.push(s[i]); 
        }
    }
    while(!stack.empty()){
        res+=stack.top();
        stack.pop();
    }
    cout<<res;
    return 0;
}

int main() {
    
    string infix ="2+3+(4*5)/3";
    postfix(infix);    
}
