#include <iostream>
#include <sstream>


using namespace std;

int key(int);
bool validity(string);

int main(){

	string num;
	int digit=0;
	string dig;
	int first_num[4];
	int flag=0;


	cout<<"Enter 4 Digit Code: ";
	cin>>num;

	if(validity(num)){
		for(int i=0;i<4;i++){
			dig=num[i];
			sscanf(dig.c_str(), "%d", &digit);
			first_num[i]=key(digit);
		}
	}else{
		cout<<"Invalid Input";
		return 0;
	}
	cout<<"Second Number: ";
	for(int i=0;i<4;i++){
			if(first_num[i]==0 && flag == 0){
				continue;
			}
			else
				flag=1;

			cout<<first_num[i];
		}

}

int key(int num){
	return (num+2)%10;
}

bool validity(string num){

	int count=0;
	int digit= 0;
	string temp;

	for(int i=0;i<4;i++){

		temp = num[i];
		sscanf(temp.c_str(), "%d", &digit);

		if(digit<0){
			return false;
		}
		if(digit == 8)
			count++;
	}

	if(count == 4)
		return false;
	else
		return true;
}