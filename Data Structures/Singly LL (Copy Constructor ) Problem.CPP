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
linkedlist(linkedlist &l)
{

 head=l.head;
 tail=l.tail;
}
linkedlist operator=(linkedlist &l)
{
  head=l.head;
  tail=l.tail;
}
void sortthelist();
void addtohead(int x);   //done
void addtotail(int x);  //done
int deletefromhead();    //done
int deletefromtail();        //done

void concatenate(linkedlist &);
void merge(linkedlist&);

void reverse();           //done
int isempty();
int isinit(int x);       //done
void deletenode(int x);    //done
int countnoofnodes();      //done
void accept();//done
void deleteanode(int );    //done
void deletethelist();     //done
~linkedlist();
void display();           //done
linkedlist operator + (linkedlist&);
};

class node
{
     int info;
     node *next;

public:

friend class linkedlist;
node(int x,node*n);

};

void linkedlist::reverse()
{

if(head!=0 && head!=tail)
{
    node*ptr=0,*temp=head,*prev=0;
    while(temp!=0)
    {
    ptr=temp->next;
    temp->next=prev;
    prev=temp;
    temp=ptr;
    }
 temp=head;
 head=tail;
 tail=temp;
}

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

void linkedlist::concatenate(linkedlist &l)
{


       clrscr();
       cout<<"1ST LIST ";
       getch();
       display();
       clrscr();
       cout<<"2ND LIST ";
       getch();
       l.display();
       clrscr();
       cout<<"NEW LIST ";
       getch();


      if(!(l.isempty()))
       {
	  if(isempty())
	  {

	    head=l.head;
	    tail=l.tail;
	  }
	  else
	  {

	   tail->next=l.head;
	   tail=l.tail;
	  }
	 l.head=0;
	 l.tail=0;

       }
       display();
}

linkedlist linkedlist::operator +(linkedlist &l)
{

     linkedlist l3;
       clrscr();
       cout<<"1ST LIST ";
       getch();
       display();
       clrscr();
       cout<<"2ND LIST ";
       getch();
       l.display();
       clrscr();
       cout<<"NEW LIST ";
       getch();
       if(isempty()&&l.isempty())
       {

	l3.head=l3.tail=0;
       }
       else if(!isempty()&&l.isempty())
       {
	l3.head=head;
	l3.tail=tail;

       }
       else if(isempty()&&!l.isempty())
       {
	 l3.head=l.head;
	 l3.tail=l.tail;

       }
       else
       {

	   l3.head=head;
	   tail->next=l.head;
	   l3.tail=l.tail;
       }


       l3.display();
       return l3;
}



void linkedlist:: display()
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


void linkedlist::deleteanode(int x)
{

    if(head->info==x && head==tail)
    {
      delete head;
      head=tail=0;
    }

    else if(head->info==x)
    {
     node*temp=head;
     head=head->next;
     delete temp;

    }


    else
    {
      node *temp=head->next,*prev=head;

      for(;temp!=0 &&(temp->info)!=x;)
      {
       prev=temp;
	temp=temp->next;

      }
      if(temp)
      {
	if(temp==tail)
	{
	  tail=prev;
	  delete temp;
	  tail->next=0;


	}
	else
	 {
	  prev->next=temp->next;
	  delete temp;
	 }


      }
      else
      {
      cout<<"Element not present ";
      getch();
      }

}

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

int linkedlist::isinit(int x)
{
 for(node*p=head;p!=0;p=p->next)
 {
  if(x==p->info)
  return 1;
  }
 return 0;


}
node::node(int x,node *n= 0)
{

info=x;
next=n;

}

void linkedlist ::addtohead(int x)
{
     head=new node(x,head);
     if(tail==0)
       tail=head;
}

void linkedlist::addtotail(int x)
{
  if(tail!=0)
  {
  tail->next= new node(x);
  tail=tail->next;

  }
  else
  head=tail=new node(x);

}

int linkedlist::deletefromhead()
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

void linkedlist::sortthelist()
{
      node*i,*j,*pos;
      int temp;
      for(i=head;i!=tail;i=i->next)
	{
	   pos=i;
	    for(j=i->next;j!=0;j=j->next)
	   {
	      if(j->info < pos->info)
	       pos=j;

	   }

	   temp=i->info;
	   i->info=pos->info;
	   pos->info=temp;

       }
}
int linkedlist::deletefromtail()
{

   if(head!=0)
   {
    int x=tail->info;

    if(head==tail)
       {
	delete head;
	head=tail=0;
	}
     else
       {
       node*ptr;
       for(ptr=head;ptr->next!=tail;ptr=ptr->next);
       delete tail;
       tail=ptr;
       tail->next=0;
	}

     return x;
   }
   else
   return -1;
}

int linkedlist::countnoofnodes()
{
  int k=0;
  for(node *p=head;p!=0;p=p->next,k++);
  return k;
}


void linkedlist::merge(linkedlist &l2)
{
 cout<<"THIS FUNCTION WILL AUTOMATICALLY SOUGHT THE 2 LISTS :";
 linkedlist l3;
 sortthelist();
 l2.sortthelist();
 node*i,*j;

 i=head,j=l2.head;

 while(i!=0&&j!=0)
 {

  if(i->info<j->info)
  {
    l3.addtotail(i->info);
    i=i->next;
  }

  else
  {
   l3.addtotail(j->info) ;
   j=j->next;
  }
 }
 while(j!=0)
 {
   l3.addtotail(j->info) ;
   j=j->next;
 }
 while(i!=0)
 {
    l3.addtotail(i->info);
    i=i->next;

 }
 clrscr();
 cout<<"NEW MERGED LIST";
 getch();
 l3.display();

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
	linkedlist l2;


	cout<<"\n\t\t --\4\4 S.I.N.G.L.Y - L.I.N.K.E.D. L.I.S.T. M.E.N.U \4\4--\n";
	cout<<"\n\n\t\t\tA.Add to Head";
	cout<<"\n\t\t\tB.Add to Tail";
	cout<<"\n\t\t\tC.Delete From Head";
	cout<<"\n\t\t\tD.Delete From Tail";
	cout<<"\n\t\t\tE.Reverse the List";
	cout<<"\n\t\t\tF.Search For an Element";
	cout<<"\n\t\t\tG.Delete a node";
	cout<<"\n\t\t\tH.Delete the list";
	cout<<"\n\t\t\tI.Concatenate to the Linked List";
	cout<<"\n\t\t\tJ.Merge 2 Linked Lists";
	cout<<"\n\t\t\tK.Count the No. of Nodes";
	cout<<"\n\t\t\tL.Display The List";
	cout<<"\n\t\t\tM.Create A New List";
	cout<<"\n\t\t\tN.Sort the Linked List";

		cout<<"\n\t\t\t0.Exit";

	cout<<"\n\n\t\t\tEnter Your choice : ";
	cin>>ch;

 switch(ch)
 {

	case 'A': case'a' :

		 clrscr();

		 cout<<"Enter the Element : ";
		 cin>>x;
		 l.addtohead(x);
		 cout<<"\n\nElement Added Successfully ";
		 getch();
		 break;

	case 'B': case'b':

		 clrscr();

		 cout<<"Enter the Element : ";
		 cin>>x;
		 l.addtotail(x);
		 cout<<"\n\nElement Added Successfully ";
		 getch();
		 break;

	case 'C': case'c':

		 clrscr();
		 if(l.isempty())
		 cout<<"List is empty ";
		 else
		 cout<<"Deleted Node's Information : "<<l.deletefromhead();
		 getch();
		 break;
	case 'D': case'd':
		 clrscr();
		 if(l.isempty())
		 cout<<"List is empty ";
		 else
		 cout<<"Deleted Node's Information : "<<l.deletefromtail();
		 getch();

		 break;
	case 'E': case'e':
		 l.reverse();
		 clrscr();
		 cout<<"List is Reversed";
		 getch();
		 l.display();
		 break;
	case 'F': case'f':
		 clrscr();
		 cout<<"Enter the element to be searched : ";
		 cin>>x;
		 if(l.isinit(x))
		 cout<<"\n\nElement Found ";
		 else
		 cout<<"\n\nElement Not Found ";
		 getch();
		 break;
	case 'G': case'g':

		 clrscr();
		 cout<<"Enter the Info of the Element To be deleted :";
		 cin>>x;

		 l.deleteanode(x);
		 break;
	case 'H': case'h':
		 l.deletethelist();
		 clrscr();
		 cout<<"List Cleared ";
		 getch();
		 break;
	case 'I': case'i':
		 clrscr();
		 cout<<"A 2nd list needs to be created to concatenate it to the previous list ";
		 getch();


		 l2.accept();
		 l.concatenate(l2);

		 break;
	case 'J': case'j':
		 clrscr();
		 cout<<"A 2nd list needs to be created to merge it with the previous list ";
		 getch();

		 l2.accept();
		 l.merge(l2);

		 break;
	case 'K': case'k':
		 clrscr();
		 if(l.countnoofnodes()==0)
		 cout<<"List is Empty ";
		 else
		 cout<<"No. of Elements in the list : "<<l.countnoofnodes();
		 getch();
		 break;
	case 'L': case'l':

		 l.display();
		 break;
	case 'M': case'm':
		 l.deletethelist();
		 clrscr();
		 cout<<"Enter the New List  ";
		 getch();
		 l.accept();
		 break;

	case 'N':case 'n':
		 l.sortthelist();
		 clrscr();
		 cout<<"SORTED LIST";
		 getch();
		 l.display();

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
    linkedlist l,l2,l3;
 l.accept();
//    mainmenu(l);
l2.accept();
l3= l+l2;
 l3.display();

}
