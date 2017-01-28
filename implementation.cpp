#include<iostream>
using namespace std;

int N = 0;

void push( int A[],int data){
	if (2 == N){
		cout<<"Stack overflow"<<endl;
		return ;
	}
	A[N] = data;
	N++;
}

void print(int A[]){
	for (int i = 0; i<N; i++){
		cout<<A[i]<<", ";
	}
}

int pop(int A[]){
	int temp = A[N-1];
	if(N ==0){
		cout<<"underflow"<<endl;
		return 0;
	}
	N--;
	return temp;
}

	
	

int main(){
	int A[2];
	push(A, 10);
	push(A, 12);
	pop(A);
	print(A);
	
}

