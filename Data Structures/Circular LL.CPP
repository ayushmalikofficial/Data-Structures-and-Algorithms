#include<iostream.h>
#include<conio.h>
#include<process.h>

class node;

class linkedlist
{

	node *tail;

 public:

void addtotail(int x);
int deletefromtail();
void reverse();
int isempty();
int isinit(int x);
void accept();
void deleteanode(int );
void deletethelist();
linkedlist(node*);
~linkedlist();
void display();
};





class node
{
     int info;
     node *next;

public:

friend class linkedlist;

node(int x,node*n);

};



node::node(int x,node *n= 0)
{

info=x;
next=n;

}




linkedlist::linkedlist( node*t=0)
{


  tail=t;
}




void linkedlist::reverse()
{

 node*temp,*ptr,*prev;
 if(tail!=tail->next&&tail!=0)
 {
  temp=tail->next;
  prev=tail;
  while(temp!=tail)
  {
   ptr=temp->next;
   temp->next=prev;
   prev=temp;
   temp=ptr;


  }
  tail=tail->next;
  temp->next=prev;
 }


}


linkedlist::~linkedlist()
{
 deletethelist();
}

int linkedlist::isempty()
{
 if(tail==0)
 return 1;
 return 0;

}


void linkedlist:: display()
{
  clrscr();
  if(tail==0)
  {
  cout<<"List is empty";

  }
  else
  {

   cout<<"Elements of the list : \n\n";



  for(node*temp=tail->next;temp!=tail;temp=temp->next)
  {
    cout<<temp->info<<"  ";
  }
    cout<<temp->info<<"  ";
  }
  getch();
}



void linkedlist::deletethelist()
{
  for(node*temp=tail->next;temp!=tail;temp=temp->next)
  {
     delete temp;

  }
  delete tail;
  tail=0;

}



int linkedlist::isinit(int x)
{
 if(tail->info==x)
 return 1;
 for(node*p=tail->next;p!=tail;p=p->next)
 {
  if(x==p->info)
  return 1;
  }
 return 0;


}

void linkedlist::addtotail(int x)
{
  if(tail!=0)
  {
  tail->next= new node(x,tail->next);
  tail=tail->next;
  }
  else
  {
  tail=new node(x);
   tail->next=tail;
  }
}

int linkedlist::deletefromtail()
{

   if(tail!=0)
   {
    int x=tail->info;

    if(tail==tail->next)
       {
	delete tail;
	tail=0;
	}
     else
       {
       node*ptr;
       for(ptr=tail->next;ptr->next!=tail;ptr=ptr->next);
       ptr->next=tail->next;
       delete tail;
       tail=ptr;

	}

     return x;
   }
   else
   return -1;
}

void linkedlist::accept()
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
 addtotail(y);
 }

}

void mainmenu(linkedlist &l)
{
 clrscr();
 char ch;
	int x;



	cout<<"\n    --\4\4 C.I.R.C.U.L.A.R  S.I.N.G.L.Y - L.I.N.K.E.D. L.I.S.T. M.E.N.U \4\4--\n";
	cout<<"\n\n\t\t\t1.Add to Tail";
	cout<<"\n\t\t\t2.Delete from Tail";
	cout<<"\n\t\t\t3.Reverse the List";
	cout<<"\n\t\t\t4.Search For an Element";
	cout<<"\n\t\t\t5.Display The List";
	cout<<"\n\t\t\t6.Create A New List";
	cout<<"\n\t\t\t0.Exit";

	cout<<"\n\n\t\t\tEnter Your choice : ";
	cin>>ch;

 switch(ch)
 {
	case '1':

		clrscr();
		cout<<"Enter the ekement you wish to add :";
		cin>>x;
		l.addtotail(x);
		break;

	case '2':
		x=l.deletefromtail();
		clrscr();
		if(x==-1)
		cout<<"The List is empty";

		else
		cout<<"Element removed : "<<x;
		getch();
		break;

	case '3':
		l.reverse();
		clrscr();
		cout<<"Reversed List : ";
		getch();
		l.display();
		break;


	case '4':
		clrscr();
		cout<<"Enter the ekement you wish to search :";
		cin>>x;

		if(l.isinit(x)==0)
		cout<<"Element Not Found";
		else
		cout<<"Element Found ";
		getch();

		 break;

	case '5':
		 l.display();
		 break;


	case '6':
		 l.deletethelist();
		 l.accept();
		 break;


	case '0':
		 exit(0);
	default :
	cout<<"\n\n    INVALID CHOICE KINDLY RE-ENTER";
	getch();
  }

   mainmenu(l);
}


void main()
{
    linkedlist l;
 l.accept();
    mainmenu(l);



}
