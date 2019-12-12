#include<iostream.h>
#include<conio.h>
#include<process.h>

void accept();

class stack
{

 char *a;
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
  {
   cout<<a[temp]<<endl;
  }
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
       a=new char[x];
	size=x;
     }
  char pop()
  {

    clrscr();
    if(top==-1)

	  return '\a';

    else
    {
       top--;
       return a[top+1];
   }
  }

  void push(char x)
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
  char topel()

  {   clrscr();
   if(top==-1)
   {
    return '\a';
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
void mainmenu(stack &s)
{

 clrscr();
 char ch;
  cout<<"\n\n\t   M.A.I.N.M.E.N.U";
  cout<<"\n\n\t1.Push an element into the stack ";
  cout<<"\n\n\t2.Pop an element from the stack ";
  cout<<"\n\n\t3.Display top element of the stack ";
  cout<<"\n\n\t4.Clear the stack ";
  cout<<"\n\n\t5.Check if the stack is clear ";
  cout<<"\n\n\t6.Display all elements of the stack ";
  cout<<"\n\n\t7.Create a new stack ";
  cout<<"\n\n\t0.Exit";
  cout<<"\n\n\tEnter Your Choice : ";
  cin>>ch;

  switch(ch)
  {

   case '1' :
	    clrscr();
	    char x;
	    cout<<"Enter the Element : ";
	    cin>>x;
	    s.push(x);

	    break;
   case '2' :
	    clrscr();
	    {
	    if(s.isempty()==-1)
	      cout<<"Stack is Empty ";
	    else
	       cout<<s.pop();
	    }
	    getch();
	    break;

   case '3' :
	    clrscr();
	    {
	    if(s.topel()=='\a')
	      cout<<"Stack is Empty ";
	    else
	       cout<<s.topel();
	    }
	    getch();
	    break;
   case '4' :

	    clrscr();
	    s.clear();
	    cout<<"Stack cleared";
	    getch();
	    break;

   case '5' :
	    clrscr();
	    if(s.isempty()==1)
	      cout<<"Stack is empty ";
	     else
	      cout<<"Stack is non-empty";
	     getch();
	     break;

   case '6' :
	    s.display();
	    break;

   case '7' :
	    accept();
	    break;
   case '0':
	     exit(0);
   default :

	     cout<<"\n\n\tInvalid Choice Kindly Re-Enter  ";

  }

 mainmenu(s);
}

void accept()
{
 clrscr();

 int x;
 cout<<"Enter the size of the stack  : ";
 cin>>x;
 while(x<=0)
 {
   clrscr();
   cout<<"Invalid size Kindly Re-Enter the size of the stack  : ";

   cin>>x;


 }

 stack s(x);

 mainmenu(s);

}



void main()
{

clrscr();


 accept();



getch();

}

