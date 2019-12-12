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

void insert(int,int);
void accept();
void display();
linkedlist operator+(linkedlist);
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
linkedlist linkedlist::operator+(linkedlist l2)
{


 linkedlist l3;
 node*i,*j;

 i=head,j=l2.head;

 while(i!=0&&j!=0)
 {
  if(i->deg==j->deg)
  {
     l3.insert(i->info+j->info,j->deg);
     i=i->next;
     j=j->next;
   }
  else if(i->deg<j->deg)
  {
    l3.insert(i->info,i->deg);
    i=i->next;
  }

  else
  {
   l3.insert(j->info,j->deg) ;
   j=j->next;
  }
 }
 while(j!=0)
 {

   l3.insert(j->info,j->deg) ;
   j=j->next;
 }
 while(i!=0)
 {
  l3.insert(i->info,i->deg);
    i=i->next;

 }
 clrscr();
 cout<<"Added Polynomial";
 getch();
 l3.display();
  return l3;
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
     if(d<head->deg)
       {
	 head=new node(x,d,head);
       }
      else if(d==head->deg)
      {
       head->info+=x;
      }
     else if(d>tail->deg)
     {
       tail->next=new node(x,d);
       tail=tail->next;
     }
     else if(d==tail->deg)
     {

       tail->info+=x;
     }
     else
     {
     int flag=0;
      node*temp,*prev=head;
      for(temp=head->next;d>temp->deg;temp=temp->next,prev=prev->next)
      {
	if(d==temp->deg)
	{
	 temp->info+=x;
	 flag=1;
	 break;

	}

      }
      if(flag==0)
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
    cout<<temp->info<<"x^"<<temp->deg<<" + ";
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
 cout<<"Enter the Polynomial : \n";
 for(int i=0;i<x;i++)
 {
 cout<<"Enter Co-effiecient of "<<i+1<<" term : ";
 cin>>y;

 cout<<"Enter the corresponding power of x :";
 cin>>d;
 if(y==0)
 continue;
 insert(y,d);
  cout<<"\n";
 }

}


void main()

{
  clrscr();
  linkedlist l,l2,l3;
  cout<<"1st Polynomial";
  getch();
  l.accept();
  l.display();
  clrscr();
  cout<<"2nd Polynomial";
  getch();
  l2.accept();
  l2.display();

   l3=l+l2;
   cout<<"Outside function";
   getch();
   l3.display();


}
