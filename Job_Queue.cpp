#include<iostream>
using namespace std;
#define MAX 5


struct job{
	char job_name;
};

class queue{
public:
	job Q[MAX];
	int front,rear;

public:
	queue(){
		front = rear = -1;
	}

	void insert(job data){
		if(isEmpty()){
			front = rear = 0;
			Q[rear] = data;
		}
		else{
			rear++;
			Q[rear] = data;
		}
		cout<<"Job Added Successfully!!";
	}

	job process(){
		job j;
		j = Q[front];

		if(front == rear){
			front = rear = -1;
			return j;
		}
		else {
			front++;
			return j;
		}
	}

	bool isEmpty(){
		if(rear == -1)
			return true;
		return false;
	}

	bool isFull(){
		if(rear == MAX-1)
			return true;
		return false;
	}

	void display(){
		int i;
		i = front;

		while(i<=rear){
			cout<<Q[i].job_name<<" <== ";
			i++;
		}
	}
};


int main(){
	int choice;
	queue que;
	job j;

	while(1){
		cout<<"\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=";
		cout<<"\n1) Add Job.";
		cout<<"\n2) Process Job.";
		cout<<"\n3) Check Empty.";
		cout<<"\n4) Check Full.";
		cout<<"\n5) Print Queue.";
		cout<<"\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n";
		cout<<"Your Choice: ";
		cin>>choice;

		switch(choice){
			case 1:
				if(que.isFull()){
					cout<<"Queue is Full!!";
				}
				else{
					cout<<"\nJob Name (A,B,C,D.....): ";
					cin>>j.job_name;
					que.insert(j);
				}
				break;
			case 2:
				if(que.isEmpty()){
					cout<<"Queue is Empty!!";
				}
				else{
					j = que.process();
					cout<<j.job_name<<" is Processed Successfully!!";
				}
				break;
			case 3:
				if(que.isEmpty())
					cout<<"Queue is Empty!!";
				else
					cout<<"Queue is not Empty!!";
				break;
			case 4:
				if(que.isFull())
					cout<<"Queue is Full!!";
				else
					cout<<"Queue is not Full!!";
				break;
			case 5:
				que.display();
				break;
			default:
				cout<<"Invalid Choice!!";
		}

	}

}












