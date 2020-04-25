#include<iostream>
using namespace std;

struct node{
	char data;
	struct node *next;
}*top=NULL,*temp,*p;

void push(char x){
	p = new node;
	p->data = x;
	p->next = NULL;

	if(top==NULL)
		top=p;
	else{
		temp = top;
		top = p;
		p->next = temp;
	}
}

char pop(){
	if(top==NULL){
		return NULL;
	}
	else{
		temp = top;
		top = top->next;
		return temp->data;
	}
}

int main(){

	char exp[20],a,b,c;
	int i=0;

	while(1){
		cout<<"Enter Expression to Check: ";
		cin>>exp;

		while(exp[i]!='\0'){

			if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
				push(exp[i]);
			}
			switch(exp[i]){
				case ')':
					a = pop();
					if(a!='('){
						cout<<"\n() Not Balanced!!\n";
						return 0;
					}
					break;
				case ']':
					b = pop();
					if(b!='['){
						cout<<"\n[] Not Balanced!!\n";
						return 0;
					}
					break;
				case '}':
					c = pop();
					if(c!='{'){
						cout<<"\n{} Not Balanced!!\n";
						return 0;
					}
					break;
			}
			i++;
		}
		if(top==NULL)
			cout<<"Balanced!!\n\n";
		else
			cout<<"Not Balanced!!\n\n";
	}
}
