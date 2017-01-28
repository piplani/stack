#include<iostream>
#include<string>
using namespace std;

int N = 0;

void push( char data, char stack[]){
	stack[N] = data;
	N++;
}

void print(char stack[]){
	for (int i = 0; i<N; i++){
		cout<<stack[i]<<", ";
	}
}

char pop(char stack[]){
	char temp = stack[N-1];
	if(N ==0){
		cout<<"underflow"<<endl;
		return 0;
	}
	N--;
	return temp;
}

bool matchpair(char ch1, char ch2){
	if (ch1 =='{' && ch2 == '}' ) {
		return 1;
	}
	else if(ch1 =='[' && ch2 == ']' ) { 
		return 1;
	}
	else if (ch1=='(' && ch2 ==')' ) {
		return 1;
	}
	else{
		return 0;
	}
}

bool ismatch(string exp, char stack[]){
	char ch;
	for(int i = 0;i<exp.size();i++){
		if (ch=='{' || ch == '[' || ch =='(' ) {
			push(ch, stack);
		}
		if( ch =='}' || ch ==']' || ch==')' ) {
			if (N==0){
				return 0;
			}
			
			else if (!matchpair(pop(stack), ch)){
					cout<<"hello";
				return 0;
			}
		}

	}
		if (N==0){
			return 1;
			
		}
		else{
			return 0;
			
		}
}


	
	

int main(){
	char stack[100];
	string str= "{]";
	if (ismatch(str, stack)==1){
		cout<<"matched";
	}
	else{
		cout<<"not matched";
	}
	
	
}