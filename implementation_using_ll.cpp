#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head;

void push(int data){
	 Node* node = new Node();
	node->data = data;
	Node* temp = head;
	if(head == NULL){
		head = node;
		return ;
	}
	while(temp->next){
		temp = temp->next;
	}
	temp->next = node;
}

int pop(){
	Node* temp = head;
	while(temp->next->next){
		temp = temp->next;
	}
	int d = temp->next->data;
	temp->next = NULL;
	return d;
}


void print(Node* head){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

int main(){
	push(10);
	push(20);
	push(30);
	push(40);
	pop();
	print(head);
}
	