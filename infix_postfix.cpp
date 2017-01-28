#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack <char> st;
int prec(char ch){
	switch(ch){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		return -1;
	}
}

int isoperand(char ch){
	return ((ch>='a'&&ch<='z') || (ch>='A' && ch<='Z'));
}

void infixToPostfix(string exp){
	for(int i=0;i<exp.size();i++){
			if(exp[i] == ' ') continue;
		if( isoperand(exp[i]) ){
			cout<<exp[i];
		}

		else if( exp[i] == '(' ) st.push(exp[i]);

		else if( exp[i] == ')' ){
			while(!st.empty() && st.top()!='(') {
				cout<<st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && st.top()!='(' && prec(exp[i]) <= prec( st.top() ) ){
				cout<<st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
		}
		while(!st.empty()){
			cout<<st.top();
			st.pop();
		}
	}

int main(){
	string exp;
	cin>>exp;
	infixToPostfix(exp);
	
}