#include<iostream.h>
#include<conio.h>
#include<process.h>




template<class z>
class node
{
     z info;
     node <z>*next;

public:

friend class stack<z>;

node( z,node<z>*n);
};

template<class z> node<z>::node(z x, node<z>*n= 0)
{

info=x;
next=n;

}


template<class z>
class  stack
{
	node <z>*head;


 public:

stack( node<z>*n=0)
{

  head=n;

}
stack(stack<z> &l)
{

 head=l.head;

}
void push(z x);

z pop();

int isempty();
void accept();
void clear();
~stack();
void display();
};


template<class z>int stack<z>::isempty()
{
if(head==0)
return 1;
return 0;

}
template<class z> stack<z>::~stack()
{
 clear();
}


template<class z> void stack<z>:: display()
{
  clrscr();
  if(head==0)
  {
  cout<<"List is empty";

  }
  else
  {

  int k=1;
  for(node<z>*temp=head;temp!=0;temp=temp->next,k++)
  {
    cout<<"\n"<<k<<" Element Of The List : "<<temp->info;
  }
  }
  getch();
}


template<class z>void stack<z>::clear()
{
  node <z>*i,*j;
  while(head!=0)
  {
  i=head;
  head=head->next;
  delete i;
  }

}


template<class z> void stack<z>::push(z x)
{
     head=new node <z>(x,head);

}


template<class z> z stack<z>::pop()
{
  if(head!=0)
  {
   node <z>*ptr=head;
   z x=ptr->info;

   if(head->next==0)
       head=0;
   else
   head=head->next;

   delete ptr;

   return x;
  }
   else
   {
   clrscr();
   cout<<"Linked list Already Empty";
   getch();
   return -1;
   }
}


template<class z> void stack<z>::accept()
{
 clrscr();


  int x;
  z y;
  cout<<"Enter the initial no. of nodes you wish to create : ";
  cin>>x;
 cout<<endl<<endl;
 for(int i=0;i<x;i++)
 {
 cout<<"Enter the Information for the "<<i+1<<" node: ";
 cin>>y;
 push(y);
 }

}
template <class z>
void mainmenu( stack<z> &l)
{
 clrscr();
 char ch;
	z x;



	cout<<"\n\t\t --\4\4 S.T.A.C.K  M.E.N.U \4\4--\n";
	cout<<"\n\n\t\t\t1.Push";
	cout<<"\n\t\t\t2.Pop";
	cout<<"\n\t\t\t3.Clear the Stack";
	cout<<"\n\t\t\t4.Display The Stack";
	cout<<"\n\t\t\t5.Create A New Stack";

		cout<<"\n\t\t\t0.Exit";

	cout<<"\n\n\t\t\tEnter Your choice : ";
	cin>>ch;

 switch(ch)
 {

	case '1':

		 clrscr();

		 cout<<"Enter the Element : ";
		 cin>>x;
		 l.push(x);
		 cout<<"\n\nElement Added Successfully ";
		 getch();
		 break;

	case '2':

		 clrscr();
		 if(l.isempty())
		 cout<<"List is empty ";
		 else
		 cout<<"Deleted Node's Information : "<<l.pop();
		 getch();
		 break;


	case '3':
		 l.clear();
		 clrscr();
		 cout<<"List Cleared ";
		 getch();
		 break;
	case '4':
		 l.display();
		 break;
	case '5':
		  l.clear();
		  mm2();
		  break;
	case '0':
		exit(0);
		 break;

	default :
	cout<<"\n\nINVALID CHOICE KINDLY RE-ENTER";
	getch();
  }

   mainmenu(l);
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
  mm2();
}
