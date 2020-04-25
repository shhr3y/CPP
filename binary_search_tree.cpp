#include<iostream>
#include<string.h>
using namespace std;

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

class tree{
public:
	node *head;
	node *next;
public:
	void create(){
		node temp = new node();
		cout<<"Enter Number: ";
		cin>>temp.data;

		temp.left = NULL;
		temp.right = NULL;
		head = temp;
	}

	void insert(){
		node temp = new node();
		cout<<"Enter Number: ";
		cin>>temp.data;

		next = head;

		if(temp.data > next->data){

		}
		else if(temp.data < next->data){
			
		}
		else{
			cout<<"Error: Data Already Exists!!\n";
		}
	}
}























