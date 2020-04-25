#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct node
{
	string index;
	string name;
	struct node* child;
	struct node* sibling;
}node;
class Book
{
public:
	node book;
	node *head;
	node *next;
	node *last;
	node *head_top;
	node *head_stop;

public:
	Book(){
		book.index = "0";
		book.name = " ";
		book.child = NULL;
		book.sibling = NULL;

	}
	void create(){
		node *temp = new node();
		cout<<"\nEnter Chapter Name: ";
		cin>>temp->name;
		cout<<"\nEnter Index: ";
		cin>>temp->index;
		temp -> child = NULL;
		temp -> sibling = NULL;
		head = temp;
	}
	void insert_chp(){
		node *temp = new node();
		next = head;
		while(next -> sibling!=NULL){
			next = next -> sibling;
		}

		cout<<"Enter Name of Chapter: ";
		cin>>temp->name;
		cout<<"Enter Index: ";
		cin>>temp->index;

		next -> sibling = temp;

	}

	void insert_topic(){
		node *temp = new node();
		string chp;
		cout<<"Enter Index of Chapter in which you want to Insert: ";
		cin>>chp;
		next = head;
		while(strcmp(next->index,chp)){
			next = next -> sibling;
		}

		head_top = next -> child;
		next = head_top;
		while(next -> sibling!=NULL){
			next = next -> sibling;
		}

		cout<<"Enter Name of Topic: ";
		cin>>temp->name;
		cout<<"Enter Index: ";
		cin>>temp->index;
		temp -> sibling = NULL;
		temp -> child = NULL;


		next -> sibling = temp;
	}

	void insert_subtopic(){
		node *temp = new node();

		string chp;
		cout<<"Enter Index of Chapter in which you want to Insert: ";
		cin>>chp;
		next = head;
		while(strcmp(next->index,chp)){
			next = next -> sibling;
		}
		head_top = next -> child;
		next = head_top;
		string top;
		cout<<"Enter Index of Topic in which you want to Insert: ";
		cin>>top;
		while(strcmp(next->index,top)){
			next = next -> sibling;
		}

		head_stop = next -> child;
		next = head_stop;

		while(next -> sibling!=NULL){
			next = next -> sibling;
		}

		cout<<"Enter Name of Sub Topic: ";
		cin>>temp->name;
		cout<<"Enter Index: ";
		cin>>temp->index;

		next -> sibling = temp;
	}
	
	void display(){

	}
};


int main(){

	Book obj;
	int choice;
	int choice1;

	obj.create();
	while(true){
		cout<<"\n*****************************";
		cout<<"\n1.Insert.";
		cout<<"\n2.Display.";
		cout<<"\n*****************************";
		cin>>choice;

		switch(choice){
			case 1: 
			choose_insrt:
				cout<<"\nWhat do want to Insert?";
				cout<<"\n1.Chapter.";
				cout<<"\n2.Topic.";
				cout<<"\n3.Sub Topic.";
				cin>>choice1;

				switch(choice1){
					case 1:
						obj.insert_chp();
						break;
					case 2:
						obj.insert_topic();
						break;
					case 3:
						obj.insert_subtopic();
						break;
					default:
						cout<<"Enter Valid Choice!";
						goto choose_insrt;
				}

			case 2:

			default:
						cout<<"Enter Valid Choice!";


		}
	}
}



















