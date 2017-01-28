#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack <int> st;

int evaluate(int op1, int op2, char ch){
	if(ch=='/') return op2/op1;
	if(ch=='*') return op2*op1;
	if(ch=='+') return op2+op1;
	if(ch=='-') return op2-op1;
}

int main(){
	char exp[30];
	cin>>exp;
	int size = strlen(exp);
	for(int i=0;i<size;i++){
		if(isdigit(exp[i])) st.push(exp[i]-'0');
		else{
			int op1 = st.top();
			st.pop();
			int op2 = st.top();
			st.pop();
			int res = evaluate(op1, op2, exp[i]);
			st.push(res);
		}
	}
	cout<<st.top();

}
