#include<iostream>
using namespace std;
#define MAX 8


struct node
{
	int index;
	int weigh;
	struct * next;
}*head[MAX],*iterator;

int main(){
	int num_nodes;
	int num_links;
	int i,j;
	int idx;
	int weight;
	cout<<"Enter number of Nodes: ";
	cin>>num_nodes;

	for(i=0;i<num_nodes;i++){
		head[i] -> index = i+1;
		head[i] -> weigh = 0;
		head[i] -> next = NULL;
	}

	for(i = 0;i < num_nodes;i++){
		cout<<"Enter number of links from Node "<<i+1" :";
		cin>>num_links;
		

		for(j=0;j<num_links;j++){
			node* temp = new node();

			cout<<"["<<j+1<<"] is linked to :";
			cin>>idx;
			cout<<"["<<j+1<<"] weigh is :";
			cin>>weight;

			temp -> index = idx;
			temp -> weigh = weight;
			temp -> next = NULL;

			iterator = head[i];

			if(head->next == NULL){
				head->next = temp;
			}
			else{
				while(iterator -> next != NULL){
					iterator = iterator -> next;
				}
				iterator -> next = temp;
			}
		}
	}

	//Displayy all the indexes

	for(i = 0;i < num_nodes;i++){
		for()
	}
}



















