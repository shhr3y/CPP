#include<iostream>

using namespace std;
struct node
{
int data;
struct node *next,*pr;

}*head,*h1,*p,*a,*p1,*B1,*temp,*B2;

node *create(int a);
void display(node *p);
node *add(node *p,node *p1);
void complement(node *p)
{
h1=new node;
p1=new node;
temp=new node;
head=new node;
head=p;
p1->pr='\0';
while(p!='\0')
{
if(p->data==0)
p->data=1;
else
p->data=0;
h1=p;
p=p->pr;
p1->data=0;
p1->next=new node;
temp=p1;
p1=p1->next;
p1->pr=temp;
}
temp->next='\0';
temp->data=1;
cout<<"\n1's complement is:";
display(h1);
head=add(head,temp);
cout<<"\n2's complement is:";
display(head);
//return head;
}

node *add(node *p,node *p1)
{
int carry=0,sum=0;
a=new node;
a->next='\0';
while(p!='\0')
{
if(carry==0)
{
if(p->data==p1->data)
{
if(p->data==1)
carry=1;
sum=0;
}
else
sum=1;
}
else
{
if(p->data==p1->data)
{
if(p->data==0)
carry=0;
sum=1;
}
else
sum=0;
}
a->data=sum;
a->pr=new node;
temp=a;
a=a->pr;
a->next=temp;
a->pr='\0';
p=p->pr;
p1=p1->pr;
}
if(carry==1)
a->data=1;
else
{
temp=a;
a=a->next;
a->pr='\0';
delete temp;
}
return a;
}




int main()
{
int ch,p,m,n;
char ans='y';
B1=new node;
B2=new node;
head=new node;
cout<<"Enter bit size :\n";
cin>>m;
cout<<"Enter binary no. :";
B1=create(m);
while(ans=='y')
{
  cout<<"enter yor choice\n";
  cout<<"1.complement\n2.addition\n";
  cin>>ch;
   switch(ch)
   {
    case 1:complement(B1);
       break;
    case 2:cout<<"\nEnter 2nd binary no. :";
       B2=create(m);
       head=add(B1,B2);
       display(head);
       break;
   }
  cout<<"\nreturn to main menu:";
  cin>>ans;
}
return 0;
}


node *create(int a)
{ p=new node;
head=new node;
temp=new node;
cin>>head->data;
head->pr='\0';
head->next='\0';
p=head;
for(int i=0;i<a-1;i++)
 { p->next=new node;
   temp=p;
   p=p->next;
  cin>>p->data;
  p->pr=temp;
  p->next='\0';
 }
return p;
}
void display(node *p)
{
while(p!='\0')
{
cout<<p->data<<" ";
p=p->next;
}

}
