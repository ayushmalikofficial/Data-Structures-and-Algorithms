#include<iostream.h>
#include<conio.h>
#include<process.h>

class node;

class linkedlist
{
	node *head;
	node *tail;

 public:

linkedlist( node*n=0,node*t=0)
{

  head=n;
  tail=t;
}

void merge(linkedlist&);

int isempty();
void addtotail(int x);
void deletenode(int x);    //done
void insert(int);
void accept();//done
void deleteanode(int );    //done
void deletethelist();     //done
~linkedlist();
void display();           //done

};

class node
{
     int info;
     int deg;
     node *next;

public:

friend class linkedlist;
node(int x,int d,node*n);

};
node::node(int x,int d,node *n=0)
{

info=x;
deg=d;
next=n;

}

void linkedlist::deletethelist()
{
  node *i,*j;
  while(head!=0)
  {
  i=head;
  head=head->next;
  delete i;
  }
  tail=0;
}

linkedlist::~linkedlist()
{
 deletethelist();
}

int linkedlist::isempty()
{
 if(head==0)
 return 1;
 return 0;

}
void linkedlist::insert(int x,int d)
{
  if(head==0)
  {

   head=new node(x,d);
   tail=head;
  }
  else
  {
     if(d<=head->deg)
       {
	 head=new node(x,d,head);
       }
     else if(d>=tail->deg)
     {
       tail->next=new node(x,d);
       tail=tail->next;
     }
     else
     {
      node*temp,*prev=head;
      for(temp=head->next;d>temp->deg;temp=temp->next,prev=prev->next);
      prev->next=new node(x,d,temp);

     }

  }

}
void linkedlist:: display()
{
  clrscr();
  cout<<"Polynomial : ";
  if(head==0)
  {
  cout<<"0x";

  }
  else
  {


  for(node*temp=head;temp!=tail;temp=temp->next)
  {
    cout<<temp->info<<"x^"<<temp->deg<<"+";
  }
   cout<<temp->info<<"x^"<<temp->deg;
  }
  getch();
}




void linkedlist::accept()
{
 clrscr();


  int x,y,d;
  cout<<"Enter the no. of terms of the polynomial : ";
  cin>>x;
 cout<<endl<<endl;
 for(int i=0;i<x;i++)
 {
 cout<<"
 insert(y,d);
 }

}


void main()
{
  linkedlist l;
  l.accept();
  l.display();
}
