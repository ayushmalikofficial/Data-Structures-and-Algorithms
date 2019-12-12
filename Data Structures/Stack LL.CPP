#include<iostream.h>
#include<conio.h>
#include<process.h>





#define newconcept
#ifdef newconcept
class node
{
     int info;
     node *next;

public:

friend class stack;
friend class queue;
node(int x,node*n);

};
node::node(int x,node *n= 0)
{

info=x;
next=n;

}


#endif

class  stack
{
	node *head;


 public:

stack( node*n=0)
{

  head=n;

}
stack(stack &l)
{

 head=l.head;

}
void push(int x);   //done

int pop();    //done

int isempty();
void accept();//done
void clear();     //done
~stack();
void display();           //done
};


int stack::isempty()
{
if(head==0)
return 1;
return 0;

}
stack::~stack()
{
 clear();
}


void stack:: display()
{
  clrscr();
  if(head==0)
  {
  cout<<"List is empty";

  }
  else
  {

  int k=1;
  for(node*temp=head;temp!=0;temp=temp->next,k++)
  {
    cout<<"\n"<<k<<" Element Of The List : "<<temp->info;
  }
  }
  getch();
}


void stack::clear()
{
  node *i,*j;
  while(head!=0)
  {
  i=head;
  head=head->next;
  delete i;
  }

}


void stack::push(int x)
{
     head=new node(x,head);

}


int stack::pop()
{
  if(head!=0)
  {
   node *ptr=head;
   int x=ptr->info;

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


void stack::accept()
{
 clrscr();


  int x,y;
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
/*void mainmenu(stack &l)
{
 clrscr();
 char ch;
	int x;



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
		  l.accept();
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


void main()
{
    stack l;
 l.accept();
  mainmenu(l);

}
  */