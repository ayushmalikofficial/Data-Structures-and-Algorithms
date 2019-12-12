#include<iostream.h>
#include<conio.h>
#include<process.h>

void mm2();

template<class z>
class node;

template<class z>
class linkedlist
{
	node<z> *head;
	node<z> *tail;

 public:

linkedlist( node<z>*n,node<z>*t)
{

  head=n;
  tail=t;
}
linkedlist()
{

 head=tail=0;
}
void sortthelist();
void addtohead(z x);
void addtotail(z x);
z deletefromhead();
z deletefromtail();        //done

void concatenate(linkedlist<z> &);
void merge(linkedlist<z>&);

void reverse();           //done
int isempty();
int isinit(z x);       //done
//void deletenode(z x);    //done
int countnoofnodes();      //done
void accept();//done
void deleteanode(z );    //done
void deletethelist();     //done
~linkedlist();
void display();           //done
};
template<class z>
class node
{
     z info;
     node <z>*next;
     node <z>*prev;
public:

friend class linkedlist<z>;
node(z x,node<z>*,node<z>*);

};

template<class z>void linkedlist<z>::reverse()
{

node <z>*temp=0, *ptr=0;

if(head!=tail)
{
  for(temp=head;temp!=0;temp=ptr )
  {
    ptr=temp->next;
    temp->next=temp->prev;
    temp->prev=ptr;

  }

 temp=head;
 head=tail;
 tail=temp;
}


}

template<class z> linkedlist<z>::~linkedlist()
{
 deletethelist();
}
template<class z>int linkedlist<z>::isempty()
{
 if(head==0)
 return 1;
 return 0;

}

template<class z>void linkedlist<z>::concatenate(linkedlist<z> &l)
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
	   l.head->prev=tail;
	   tail=l.tail;
	  }
	 l.head=0;
	 l.tail=0;

       }
       display();
}


template<class z>void linkedlist<z>:: display()
{
  clrscr();
  if(head==0)
  {
  cout<<"List is empty";

  }
  else
  {

  int k=1;
  for(node<z> *temp=head;temp!=0;temp=temp->next,k++)
  {
    cout<<"\n"<<k<<" Element Of The List : "<<temp->info;
  }
  }
  getch();
}


template<class z>void linkedlist<z>::deleteanode(z x)
{

    if(head->info==x && head==tail)
    {
      delete head;
      head=tail=0;
    }

    else if(head->info==x)
    {
     node<z>*temp=head;
     head=head->next;
     delete temp;

    }


    else
    {
      node <z>*temp=head->next;

      for(;temp!=0 &&(temp->info)!=x;)
      {

	temp=temp->next;

      }
      if(temp)
      {
	if(temp==tail)
	{
	  tail->prev->next=0;

	  tail=temp->prev;


	}
	else
	 {
	  temp->next->prev=temp->prev;
	  temp->prev->next=temp->next;
	 }
	  delete temp;

      }
      else
      {
      cout<<"Element not present ";
      getch();
      }


}

}
template<class z>void linkedlist<z>::deletethelist()
{

  while(head!=0)
  {

  head=head->next;
  delete head->prev;
  }
  delete tail;
  head=tail=0;
}

template<class z>int linkedlist<z>::isinit(z x)
{

 for(node<z>*p=head;p!=0;p=p->next)
 {
  if(x==p->info)
  return 1;
  }
 return 0;


}
template<class z> node<z>::node(z x,node<z> *n= 0,node<z> *p=0)
{

info=x;
next=n;
prev=p;
}

template<class z>void linkedlist<z> ::addtohead(z x)
{
     head=new node<z>(x,head,0);
     head->next->prev=head;
     if(tail==0)
       tail=head;
}

template<class z> void linkedlist<z>::addtotail(z x)
{
  if(tail!=0)
  {
  tail= new node<z>(x,0,tail);
  tail->prev->next=tail;

  }
  else
  head=tail=new node<z>(x,0,0);

}

template<class z> z linkedlist<z>::deletefromhead()
{
  if(head!=0)
  {

   z x=head->info;

   if(head==tail)
     {
       delete head;
       head=tail=0;
       }
   else
   {
   head=head->next;
   delete head->prev;
   head->prev=0;
   }

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

template<class z>void linkedlist<z>::sortthelist()
{
      node<z>*i,*j,*pos;
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
template<class z>z linkedlist<z>::deletefromtail()
{

   if(head!=0)
   {
    z x=tail->info;

    if(head==tail)
       {
	delete head;
	head=tail=0;
	}
     else
       {
	 tail=tail->prev;
	 delete tail->next;
	 tail->next=0;
	}

     return x;
   }
   else
     return -1;

}

template<class z> int linkedlist<z>::countnoofnodes()
{
  int k=0;
  for(node <z>*p=head;p!=0;p=p->next,k++);
  return k;
}


template<class z>void linkedlist<z>::merge(linkedlist<z> &l2)
{
 cout<<"THIS FUNCTION WILL AUTOMATICALLY SOUGHT THE 2 LISTS :";
 linkedlist l3;
 sortthelist();
 l2.sortthelist();
 node<z>*i,*j;

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


template<class z> void linkedlist<z>::accept()
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
 addtotail(y);
 }

}
template<class z>
void mainmenu(linkedlist<z> &l)
{
 clrscr();
 char ch;
	z x;
	linkedlist<z> l2;


	cout<<"\n\t\t --\4\4 D.O.U.B.L.Y - L.I.N.K.E.D. L.I.S.T. M.E.N.U \4\4--\n";
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

		 mm2();
		 break;

	case 'N':case 'n':
		 l.sortthelist();
		 clrscr();
		 cout<<"SORTED LIST";
		 getch();
		 l.display();

		 break;
	case '0':case'O':case 'o':
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
   linkedlist <int>l;
   l.accept();
  mainmenu(l);

   }
   else if(ch=='2')
   {
   linkedlist <float>l;
   l.accept();
  mainmenu(l);

   }
   else if(ch=='3')
   {

   linkedlist <char>l;
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
