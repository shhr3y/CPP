#include<iostream>
using namespace std;
#define MAX 20


int main(){

		int strngth_arr[MAX],strngth_count;
		int cric_arr[MAX],cric_count;
		int badm_arr[MAX],badm_count;
		int i,j;
		int common_count = 0,common_arr[MAX];
		int both;
		int only_cric_arr[MAX],only_badm_arr[MAX];
		int count_only_cric , count_only_badm;
			count_only_cric = count_only_badm = 0;
		int flag;


		cout<<"Enter Strength of Class: ";
		cin>>strngth_count;

		for(i=0;i<strngth_count;i++){
			cout<<"Enter Roll Number of Student ["<<i+1<<"]: ";
			cin>>strngth_arr[i];
		}


cricket:
		cout<<"\n\nEnter Number of Students who play Cricket: ";
		cin>>cric_count;
		if(cric_count>strngth_count){
			cout<<"Students playing Cricket cannot be greater than Class Strength!\n";
			goto cricket;
		}
		else{
			cout<<"\n";
			for(i=0;i<cric_count;i++){
				cout<<"Enter Roll Number of Student ["<<i+1<<"] who plays Cricket: ";
				cin>>cric_arr[i];
			}
		}


badminton:
		cout<<"\n\nEnter Number of Students who play Badminton: ";
		cin>>badm_count;
		if(badm_count>strngth_count){
			cout<<"Students playing Badminton cannot be greater than Class Strength!\n";
			goto badminton;
		}
		else{
			cout<<"\n";
			for(i=0;i<badm_count;i++){
				cout<<"Enter Roll Number of Student ["<<i+1<<"] who plays Badminton: ";
				cin>>badm_arr[i];
			}
		}

		for(i=0;i<cric_count;i++){//Array for Common Students
			for(j=0;j<badm_count;j++){
				if(cric_arr[i] == badm_arr[j]){
					common_arr[common_count] = cric_arr[i];
					common_count++; 
				}
			}
		}

		for(i=0;i<cric_count;i++){//Array for Only Cricket Students
			flag = 0;
			for(j=0;j<common_count;j++){
				if(cric_arr[i] == common_arr[j]){
					flag = 1; 
				}
			}
			if(!flag){
				only_cric_arr[count_only_cric] = cric_arr[i];
				count_only_cric++;
			}
		}

		for(i=0;i<badm_count;i++){//Array for Only Badminton Students
			flag = 0;
			for(j=0;j<common_count;j++){
				if(badm_arr[i] == common_arr[j]){
					flag = 1; 
				}
			}
			if(!flag){
				only_badm_arr[count_only_badm] = badm_arr[i];
				count_only_badm++;
			}
		}


		both = (cric_count+badm_count)-strngth_count;
		cout<<"\n\n\nNumber of Students who Play Both: "<<both<<endl;
		cout<<"Number of Students who Play Only Cricket: "<<count_only_cric<<endl;
		cout<<"Number of Students who Play Only Badminton: "<<count_only_badm<<endl;

		cout<<"\n\nRoll Number of Common Students: ";
		for(i=0;i<common_count;i++){
			cout<<common_arr[i]<<"\t";
		}
		cout<<"\n";

		cout<<"Roll Number of Only Cricket Students: \t";
		for(i=0;i<count_only_cric;i++){
			cout<<only_cric_arr[i]<<"\t";
		}
		cout<<"\n";

		cout<<"Roll Number of Only Badminton Students: ";
		for(i=0;i<count_only_badm;i++){
			cout<<only_badm_arr[i]<<"\t";
		}
		cout<<"\n";cout<<"\n";
}