#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack <int> st;

int evaluate(int op1, int op2, char ch){
	if(ch=='/') return op1/op2;
	if(ch=='*') return op1*op2;
	if(ch=='+') return op1+op2;
	if(ch=='-') return op1-op2;
}

int prefixevaluate(string exp){
	for(int i= exp.size()-1;i>=0;i--){
		if(isdigit(exp[i])) st.push(exp[i] - '0');
		else{
			int op1 = st.top();st.pop();
			int op2 = st.top(); st.pop();
			int res = evaluate(op1,op2,exp[i]);
			st.push(res);
		}
	}
	return st.top();
}
int main(){
	string exp;
	cin>>exp;
	cout<<prefixevaluate(exp);
}