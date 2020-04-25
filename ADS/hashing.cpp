#include<iostream>
using namespace std
#define MAX 10

typedef struct entry
{
	int key;
	string name;
	long int number;
}entry;

class directory{
public:
	entry e[MAX];
public:
	directory(int num){
		for(int i=0;i<num:i++)
			e.key = -1;
	}

	void create(int num){
		cout
	}
}

int main(){
	int num,i;

	cout<<"Enter number of entries: ";
	cin>>num;

	directory obj = new directory(num);

	for(i=0;i<num:i++)
		obj.create(num);


}