#include<iostream>
#include<string.h>
using namespace std;

struct node{
	string name;
	int prn;
	struct node *next;
};

class member{
public:
	node* head;
public:
	member(){
		head = NULL;
	}
	node* create();
	int count(node* head);
	void insertMember(node* head);
	void deleteMember(node* head);
	void display(node* head);
};

int member::count(node* head){
	node * nn = new node;
	nn = head;
	int count;
	while(nn!=NULL){
		i++;
		nn = nn->next;
	}
	return count;
}

node* member::create(){

	char choice;

	node* head;
	node* nn = new node;
	head = nn;

	cout<<"Enter President Name: ";
	cin>>nn->name;
	cout<<"Enter PRN: ";
	cin>>nn->prn;

	do{
		nn->next = new node;
		nn = nn->next;

		cout<<"Enter Member Name: ";
		cin>>nn->name;
		cout<<"Enter PRN: ";
		cin>>nn->prn;

		cout<<"Want to Continue?(Y/N): ";
		cin>>choice;
	}while(choice == 'y' || choice == 'Y');

	nn->next = new node;
	nn = nn->next;

	cout<<"Enter Secretary Name: ";
	cin>>nn->name;
	cout<<"Enter PRN: ";
	cin>>nn->prn;

	nn->next = NULL;

	cout<<"List Created!! With "<<count(head)<<" Members!";

	return head;
}

void member::insert(node* head){
	node *nn;
	nn = head;
	node *temp;

	int pos;

	cout<<"Enter Position at which you want to Insert: ";
	cin>>pos;

	node* an = new node;

	if(pos == 1){
		
		cout<<"Enter President Name: ";
		cin>>an->name;
		cout<<"Enter PRN: ";
		cin>>an->prn;

		an->next = head;
		head = an;
	}
	else{
		for(i=1;i<pos;i++){
			temp = nn;
			nn = nn->next;
		}

		if(pos>1 && nn->next==NULL){
			cout<<"Enter Secretary Name: ";
			cin>>nn->name;
			cout<<"Enter PRN: ";
			cin>>nn->prn;

		}
	}
}




int main(){

	int choice;

	member m;
	m.head = m.create();

	while(true){
		cout<<"\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=";
		cout<<"\n1) Insert Member.";
		cout<<"\n2) Delete Member.";
		cout<<"\n3) Display Member.";
		cout<<"\n4) Display Member.";
		cout<<"\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=";
		cout<<"\nYour Choice: ";
		cin>>choice;

		switch(choice){}
	};
}