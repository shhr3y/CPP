#include<iostream>
using namespace std;


int partition(int *arr,int start,int end){//Quick Sort
	int i;
	int	pivot = arr[end];
	int partitionIndx = start;
	for(i=start;i<end;i++){
		if(arr[i]<=pivot){
			swap(arr[i],arr[partitionIndx]);
			partitionIndx++;
		}
	}
	swap(arr[partitionIndx],arr[end]);
	return partitionIndx;
}void quicksort(int *arr,int start,int end){//Quick Sort

	if(start < end){
		int partitionIndx = partition(arr,start,end);
		quicksort(arr,start,partitionIndx-1);
		quicksort(arr,partitionIndx+1,end);
	}
}

void selectionsort(int *arr,int num){// Selection Sort
	int i,j;
	int minIdx;

	for(i = 0; i<num-1 ; i++){
		minIdx = i;
		for(j = i+1; j<num ; j++){
			if(arr[j]<arr[minIdx])
				minIdx = j;
		}
		if(minIdx!=i)
			swap(arr[minIdx],arr[i]);
	}
}

void insertionsort(int *arr,int num){//Insertion Sort

	int i,hole,value;
	for(i=1;i<num;i++){
		value = arr[i];
		hole = i;
		while(hole>0 && arr[hole-1]>value){
			arr[hole] = arr[hole-1];
			hole--;
		}
		arr[hole] = value;
	}
}


int main(){
	int a[]={1,6,3,9,4,7};
	insertionsort(a,6);

	for(int i = 0;i<6;i++)
		cout<<a[i]<<"\t";
}