#include<iostream>
#include<stack>
using namespace std;


struct tree {
	char data;
	struct tree *left = NULL;
	struct tree *right = NULL;
	
};
stack <struct tree *> op;
stack <struct tree *> operand;



int pre(char c)
{
	if(c == '^')
		return 3;
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;   
}


void create(char arr[])
{
	int i=0;
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
						struct tree* top = new tree();
						
						new_node = op.top();op.pop();
						new_node->data = arr[i];
			    		op.push(new_node);
						new_node->left = operand.top();operand.pop();

						new_node->right = operand.top();operand.pop();

						operand.push(new_node);
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



	while(!op.empty())
	{
	
	  			struct tree * top=op.pop();
				top->left=operand.pop();
				top->right=operand.pop();			
				operand.push(top);
	}
}


void display(struct tree * node)
{
 if(node!=NULL)
 {
   display(node->left);
   display(node->right);
   cout<< node->data;
  }
}


int main()
{
	char exp[20]={};
	cout<<"Enter Expression:";
	cin>>exp;
	create(exp);
	cout<<exp<<endl<<"The Postfix Notation is:"<<endl;
	display(operand.top());
	cout<<endl;
	return 0;
}
		
					
