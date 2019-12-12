#include"stackll.cpp"
#ifndef newconcept
class node
{
     int info;
     node *next;

public:

friend class queue;
node(int x,node*n);

};

node::node(int x,node *n=0)
{

info=x;
next=n;

}

#endif

class queue
{
	node*head;
	node *tail;


 public:

queue( node*n=0,node*t=0)
{
  head=n;
  tail=t;

}
queue(queue&l)
{

 head=l.head;
 tail=l.tail;

}
void enqueue(int);
int dequeue();
void clear();
int isempty();
void accept();

~queue();
void display();
};









int queue::isempty()
{
if(tail==0)
return 1;
return 0;

}
queue::~queue()
{
 clear();
}


void queue:: display()
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



void queue::clear()
{
  node *i,*j;
  while(head!=0)
  {
  i=head;
  head=head->next;
  delete i;
  }

}

void queue::accept()
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
 enqueue(y);
 }

}

int queue::dequeue()
{
  if(head!=0)
  {
   node *ptr=head;
   int x=ptr->info;

   if(head==tail)
       head=tail=0;
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

void queue::enqueue(int x)
{
  if(tail!=0)
  {
  tail->next=new node(x);
  tail=tail->next;

  }
  else
  head=tail=new node(x);

}
/*
void mainmenu(queue &l)
{
 clrscr();
 char ch;
	int x;


	cout<<"\n\t\t --\4\4 Q.U.E.U.E  M.E.N.U \4\4--\n";
	cout<<"\n\n\t\t\t1.Enqueue";
	cout<<"\n\t\t\t2.Dequeue";
	cout<<"\n\t\t\t3.Display The Queue";
	cout<<"\n\t\t\t4.Create A New Queue";

		cout<<"\n\t\t\t0.Exit";

	cout<<"\n\n\t\t\tEnter Your choice : ";
	cin>>ch;

 switch(ch)
 {

	case '1':

		 clrscr();

		 cout<<"Enter the Element : ";
		 cin>>x;
		 l.enqueue(x);
		 cout<<"\n\nElement Added Successfully ";
		 getch();
		 break;

	case '2':

		 clrscr();
		 if(l.isempty())
		 cout<<"List is empty ";
		 else
		 cout<<"Deleted Node's Information : "<<l.dequeue();
		 getch();
		 break;


	case '3':
		 l.display();
		 break;
	case '4':
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

#ifndef newconcept
void main()
{
    queue l;
 l.accept();
  mainmenu(l);

}
#endif
*/