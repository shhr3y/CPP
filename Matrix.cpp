
#include <iostream>
using namespace std;

void accept(int[20][20],int,int);
void display(int[20][20],int,int);
bool upperTriangular(int [20][20],int,int);
bool lowerTriangular(int [20][20],int,int);
void addMatrix(int[20][20],int[20][20],int[20][20],int,int);
void subMatrix(int[20][20],int[20][20],int[20][20],int,int);
void multiply(int[20][20],int[20][20],int[20][20],int,int);

int main(){
	int row, col;
	int mat[20][20];
	int mat1[20][20];
	int mat2[20][20];
	int mat3[20][20];

	int choice;

	while(1){
		cout<<"\n*******************************";
		cout<<"\n1.Accept MATRIX";
		cout<<"\n2.Display MATRIX";
		cout<<"\n3.Check Upper Triangular MATRIX";
		cout<<"\n4.Check Lower Triangular MATRIX";
		cout<<"\n5.Addtion of two MATRIX";
		cout<<"\n6.Subtraction of two MATRIX";
		cout<<"\n7.Multiplication of two MATRIX";
		cout<<"\n25.Exit";
		cout<<"\n*******************************\n";
		cin>>choice;

		switch(choice){
			case 1://Accept
				cout<<"Enter Number of Rows in MATRIX: ";
				cin>>row;
				cout<<"Enter Number of Columns in MATRIX: ";
				cin>>col;
				accept(mat,row,col);
				break;
			case 2://Display
				display(mat,row,col);
				break;
			case 3://Check Upper Triangle
				if(upperTriangular(mat,row,col))
					cout<<"\nIt is Upper Triangular MATRIX!!";
				else
					cout<<"\nIt is not an Upper Triangular MATRIX!!";
				break;
			case 4://Check Lower Triangle
				if(lowerTriangular(mat,row,col))
					cout<<"\nIt is Lower Triangular MATRIX!!";
				else
					cout<<"\nIt is not an Lower Triangular MATRIX!!";
				break;
			case 5://Matrix Addition
				cout<<"Enter Number of Rows in MATRIX: ";
				cin>>row;
				cout<<"Enter Number of Columns in MATRIX: ";
				cin>>col;
				cout<<"Enter MATRIX 1:"<<endl;
				accept(mat1,row,col);
				cout<<"\nEnter MATRIX 2:"<<endl;
				accept(mat2,row,col);

				addMatrix(mat1,mat2,mat3,row,col);
				cout<<"Addition is:\n";
				display(mat3,row,col);
				break;
			case 6://Matrix Subtraction
				cout<<"Enter Number of Rows in MATRIX: ";
				cin>>row;
				cout<<"Enter Number of Columns in MATRIX: ";
				cin>>col;
				cout<<"Enter MATRIX 1:"<<endl;
				accept(mat1,row,col);
				cout<<"\nEnter MATRIX 2:"<<endl;
				accept(mat2,row,col);

				subMatrix(mat1,mat2,mat3,row,col);
				cout<<"Subtraction is:\n";
				display(mat3,row,col);
				break;
			case 7://Matrix Multiplication
				cout<<"Enter Number of Rows in MATRIX: ";
				cin>>row;
				cout<<"Enter Number of Columns in MATRIX: ";
				cin>>col;
				cout<<"Enter MATRIX 1:"<<endl;
				accept(mat1,row,col);
				cout<<"\nEnter MATRIX 2:"<<endl;
				accept(mat2,row,col);

				multiply(mat1,mat2,mat3,row,col);
				display(mat3,row,col);
				break;
			case 25:
				return 0;
		}
	}
}


void addMatrix(int mat1[20][20],int mat2[20][20],int mat3[20][20],int row,int col){
	int i,j;

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat3 [i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

void subMatrix(int mat1[20][20],int mat2[20][20],int mat3[20][20],int row,int col){
	int i,j;

	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat3 [i][j] = mat1[i][j] - mat2[i][j];
		}
	}
}

void multiply(int mat1[20][20],int mat2[20][20],int mat3[20][20],int row,int col){
	    int i,j,k;
    for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat3[i][j]=0;
			for(k=0;k<col;k++)
			 	mat3[i][j]=mat3[i][j] + (mat1[i][k] * mat2[k][j]);
		}
	}
}


bool lowerTriangular(int mat[20][20],int row, int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=i+1;j<row;j++){
			if(mat[i][j]!=0)
				return false;
		}
	}
	return true;
}

bool upperTriangular(int mat[20][20],int row, int col){
	int i,j;
	for(i=1;i<row;i++){
		for(j=0;j<i;j++){
			if(mat[i][j]!=0)
				return false;
		}
	}
	return true;
}

void accept(int mat[20][20],int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			cout<<"Enter Element at ["<<i<<"]["<<j<<"]: ";
			cin>>mat[i][j];
		}
	}
}

void display(int mat[20][20],int row,int col){
		int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
}