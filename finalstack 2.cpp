#include<iostream>
#include<stack>
using namespace std;
// ****************** Global Area ****************
struct tree {
	char data;
	struct tree *left = NULL;
	struct tree *right = NULL;
	
};
stack <struct tree *> op;
stack <struct tree *> operand;
// ***********************************************


// Functional Module 


// logic to check precedence of operator
int pre(char c)
{
	if(c == '^')
		return 3;
	else if(c == '*' || c=='/')
		return 2;
	else if(c == '+' || c=='-')
		return 1;
	else
		return -1;   
}
// arr is the expression 
void create(char arr[])
{
	int i=0; // array iterator 
	while(arr[i]!='\0') 
	{
		if((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
		{
			struct tree *t = new tree();
			t->data=arr[i];
			operand.push(t);
		}
		else
		{
		
			struct tree *new_node = new tree();
			if(!op.empty())
			{
					if((pre(arr[i])>=pre(op.top()->data)))
					{
					
			 			new_node->data = arr[i];
			    		op.push(new_node);
					}
					else
					{
						struct tree * top=op.top();op.pop();
						top->right=operand.top();operand.pop();
						top->left=operand.top();operand.pop();
						operand.push(top);
						new_node->data = arr[i];
			    		op.push(new_node);`
					}
			}
			else
			{
					 		new_node->data = arr[i];
					    	op.push(new_node);
			}
		}
	  i++;
	}
  // Logic to empty operator	
	while(!op.empty())
	{
	
	  			struct tree * top=op.last();op.pop();
				top->left=operand.last();operand.pop();
				top->right=operand.top();operand.pop();			
				operand.push(top);
	}
}// end of create 
void display(struct tree * node)
{
 if(node!=NULL)
 {
   display(node->right);
   display(node->left);
   cout<<node->data;
  }
}

int main()
{
	char exp[10]={};
	cout<<"Enter Expression:";
	cin>>exp;
	create(exp);
	cout<<exp<<endl<<"The Postfix Notation is:"<<endl;
	display(operand.top());
	cout<<endl;
	return 0;
}
		
					
