#include<iostream>
#include <string>
using namespace std;

struct node
{
	char data;
	struct node *next;
}*top,*temp,*p;

void push(char x){
	p = new node;
	p->data = x;
	p->next = NULL;

	if (top==NULL){
		top = p;
	}
	else{
		temp = top;
		top = p;
		p->next = temp;
	}
}

char pop(){
	if(top == NULL){
		cout<<"Stack is Empty!!";
		return NULL;
	}
	else {
		temp = top;
		top = top->next;
		return temp->data;
	}
}

int precedence(char x){
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/')
		return 2;
	if(x == '^')
		return 3;
	else
		return 0;
}

int evaluate(int op1,int op2,char x){
	if(x == '+')
		return op1+op2;
	if(x == '-')
		return op1-op2;
	if(x == '/')
		return op1/op2;
	if(x == '*')
		return op1*op2;
}

int main(){

	char infix[20],postfix[20];
	int choice;
	int i=0;
	char x;
	int op1,op2;

	while(1){
		cout<<"\n*********************************";
		cout<<"\n1) Infix to Postfix.";
		cout<<"\n2) Evaluate";
		cout<<"\n*********************************";
		cin>>choice;

		switch(choice){

			case 1:
				cout<<"Enter Infix: ";
				cin>>infix;
				while(infix[i]!=0){
					if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*'){
						if(top==NULL)
							x = 'a';
						else 
							x = top->data;
						if(precedence(infix[i])<precedence(x)){
							cout<<pop();
							push(infix[i]);
						}
						else{
							push(infix[i]);
						}
					}
					else{
						cout<<infix[i];
					}
					i++;
				}
				while(top!=NULL){
					cout<<pop();
				}
				break;
			case 2:
				cout<<"Enter Postfix Expression: ";
				cin>>postfix;
				i=0;
				while(postfix[i]!='\0'){
					if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/' || postfix[i] == '*'){
						op1 = +pop();
						op2 = +pop();
						push(evaluate(+op1,+op2,postfix[i]));
					}
					else{
						push(postfix[i]);
					}
					i++;
				}
				cout<<+pop()<<endl;
				break;
			default:
				cout<<"Invalid Choice";
		}
	}

}