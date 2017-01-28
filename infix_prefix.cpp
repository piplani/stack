#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;
stack <char> st;
string reverse(string str){
    string str1;
    for(int i=str.size()-1;i>=0;i--){
        str1 = str1 + str[i];
    }
    return str1;
}
string makeleftright(string exp){
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='(') exp[i]=')';
        if(exp[i]==')') exp[i]='(';
    }
    return exp;
}

int prec(char ch){
    switch(ch){
    case'+':
    case'-':
        return 1;
    case'/':
    case'*':
        return 2;
    case'^':
        return 3;
    return -1;
    }
    
}

int isoperand(char ch){
    //putchar(tolower(ch));
    return (ch>='a'&& ch<='z') || (ch>='A'&& ch<='Z');
}

string topostfix(string exp){
    string exp1;
    for(int i=0;i<exp.size();i++){
        if(exp[i]==' ') continue;
        if(isoperand(exp[i])) exp1 = exp1 + exp[i];
        else if(exp[i]=='(') st.push(exp[i]);
        else if(exp[i]==')'){
            while(!st.empty() && st.top()!='('){
                exp1 = exp1 + st.top();st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && st.top()!='(' && prec(exp[i])<=prec(st.top())){
                exp1 = exp1 + st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while(!st.empty()){
        exp1 = exp1 + st.top();
        st.pop();
    }
    return exp1;
}

int main(){
    string exp;
    cin>>exp;
    exp = reverse(exp);
    exp = makeleftright(exp);
    //cout<<exp;
    cout<<reverse(topostfix(exp));
}

