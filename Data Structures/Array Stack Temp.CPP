#include<iostream.h>
#include<conio.h>
#include<process.h>

template<class z>
class stack
{

 z *a;
 int size;
 int top;

public:

 stack()
 {

   top=-1;
   size=0;

 }
 void accept();
 void display();

 ~stack()
 {

   delete []a;
 }
  z pop()
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

  void push(z x)
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
  z topel()

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
template<class z> void stack<z>::display()
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

template<class z>
void mainmenu(stack<z> &l)
{

 clrscr();
 char ch;
  cout<<"\n\n\t   M.A.I.N.M.E.N.U";
  cout<<"\n\n\t1.Push an element into the stack ";
  cout<<"\n\t2.Pop an element from the stack ";
  cout<<"\n\t3.Display top element of the stack ";
  cout<<"\n\t4.Clear the stack ";
  cout<<"\n\t5.Check if the stack is clear ";
  cout<<"\n\t6.Display all elements of the stack ";
  cout<<"\n\t7.Create a new stack ";
  cout<<"\n\t0.Exit";
  cout<<"\n\tEnter Your Choice : ";
  cin>>ch;

  switch(ch)
  {

   case '1' :
	    clrscr();
	    z y;
	    cout<<"Enter the Element : ";
	    cin>>y;
	    l.push(y);

	    break;
   case '2' :
	    clrscr();
	    {
	    if(l.isempty()==1)
	      cout<<"Stack is Empty ";
	    else
	       cout<<l.pop();
	    }
	    getch();
	    break;
   case '3' :
	    clrscr();
	    {
	    if(l.topel()==-1)
	      cout<<"Stack is Empty ";
	    else
	       cout<<l.topel();
	    }
	    getch();
	    break;
   case '4' :
	    clrscr();
	    l.clear();
	    cout<<"Stack cleared";
	    getch();
	    break;
   case '5' :
	    clrscr();
	    if(l.isempty()==1)
	      cout<<"Stack is empty ";
	     else
	      cout<<"Stack is non-empty";
	     getch();
	    break;
   case '6' :
	    l.display();
	    break;

   case '7' :
	    mm2();
	    break;
   case '0':
	     exit(0);
   default :

	     cout<<"\n\n\tInvalid Choice Kindly Re-Enter  ";

  }

 mainmenu(l);
}

template<class z> void stack<z>::accept()
{
 clrscr();
 z y;

 cout<<"Enter the size of the stack  : ";
 cin>>size;
  a=new z[size];
 while(size<=0)
 {
   clrscr();
   cout<<"Invalid size Kindly Re-Enter the size of the stack  : ";
   cin>>size;
 }
  for(int i=0;i<size;i++)
 {
 cout<<"Enter the Information for the "<<i+1<<" node: ";
 cin>>y;
 push(y);
 }

}

void mm2()
{


 clrscr();
   char ch;

   cout<<"\"TYPE OF STACK\"";
   cout<<"\n\n1.Integer";
   cout<<"\n\n2.Float";
   cout<<"\n\n3.Character ";
   cout<<"\n\nEnter Your Choice : ";
   cin>>ch;
   if(ch=='1')
   {
   stack <int>l;
   l.accept();
  mainmenu(l);

   }
   else if(ch=='2')
   {
   stack <float>l;
   l.accept();
  mainmenu(l);

   }
   else if(ch=='3')
   {

   stack <char>l;
   l.accept();
  mainmenu(l);

   }

   else
   {
    cout<<"\n\nInvalid Choice Kindly Re-enter";
    getch();
    mm2();
   }

}

void main()
{

clrscr();

mm2();




getch();

}