#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>


class stack
{

 int *a;
 int size;
 int top;

public:

  void display()
  {
	 clrscr();
	  if(top==-1)
	  cout<<"Stack Is Empty ";
	  else
	  {
	   cout<<"Elements of the stack : \n\n";

	   for(int temp=top;temp>=0;temp--)
		cout<<a[temp]<<endl;

	 }

  getch();
 }

 ~stack()
 {

   delete []a;
 }


 stack(int x)
   {
       top=-1;
       a=new int[x];
	size=x;
     }


  int pop()
  {

    clrscr();
    if(top==-1)

	  return -1;

    else
    {
       top--;
       return a[top+1];
   }
  }


  void push(int x)
  {

   if(top==size-1)
   {
    clrscr();
    cerr<<"Stack overflow ";
    getch();
    }

   else
   {
    a[++top]=x;
    }
   }


  int topel()

  {   clrscr();
   if(top==-1)
   {
    return -1;
   }
   else
      return a[top];
   }



   int isempty()
   {
      if(top==-1)
	{
	 return 1;
	}
     return 0;
   }



   void clear()
   {

    top=-1;
   }


};

int postfix(char *a)
{
   int size,x,y;

  for(int i=0;a[i]!='\0';i++);
  size=i;
  stack s(i);
  i=0;
  while(i<size)
  {
     if(a[i]>=48 && a[i]<=57)
     s.push(a[i]-48);
     else if(a[i]=='/')
     {

       y=s.pop();
       x=s.pop();
       s.push(x/y);

     }
     else if(a[i]=='+')
     {
	y=s.pop();
       x=s.pop();
       s.push(x+y);

     }
     else if(a[i]=='-')
     {
       y=s.pop();
       x=s.pop();
       s.push(x-y);

     }
     else if(a[i]=='*')
     {
       y=s.pop();
       x=s.pop();
       s.push(x*y);

     }

     else
     return -1;

   i++;
  }

  x=s.pop();
  if(s.isempty())
  return x;
  else
  return -1;
}

void main()
{

clrscr();
char *a;
int x,size;
cout<<"Enter the Size of the postfix expression : \n\nFor example :\n       236+*\n     size=5\n\nInput :";
cin>>x;
a=new char[x];
clrscr();
cout<<"Enter the "<<x<<" character postfix expression :\n";
for(int i=0;i<x;i++)
{
a[i]=getche();
if(a[i]==(13))
	break;
}
a[i]='\0';
getch();
clrscr();
cout<<"Expression : "<<a;
getch();
x=postfix(a);
if(x==-1)
cout<<"\n\n\nExpression is incorrect";
else
cout<<"\nResult of the expression : "<<x;
getch();

}