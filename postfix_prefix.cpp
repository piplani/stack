#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
stack <string> st;
int isoperator(char ch){
    if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^') return true;
    else return false;
}

int main(){
    string exp;
    cin>>exp;
    for(int i=0;i<exp.size();i++){
        if(!isoperator(exp[i])){
            stringstream ss;
            string s;
            ss<<exp[i];
            ss>>s;
            st.push(s);
        }
        else{
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            string res = exp[i] + op2 + op1;
            st.push(res);
        }
    }
    cout<<st.top();

}