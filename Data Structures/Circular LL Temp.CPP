#include<iostream.h>
#include<conio.h>
#include<process.h>

template <class z>
class linkedlist
{

	node <z> *tail;

 public:

void addtotail(z x);
z deletefromtail();
void reverse();
int isempty();
int isinit(z x);
void accept();
void deleteanode(z );
void deletethelist();
linkedlist(node<z>*);
linkedlist()
{
 tail=0;
}
~linkedlist();
void display();
};




template <class z>
class node
{
     z info;
     node <z>*next;

public:

friend class linkedlist<z>;

node(z x,node<z>*n);

};



template <class z> node<z>::node(z x,node<z>*n=0)
{

info=x;
next=n;

}




template <class z>linkedlist<z>::linkedlist( node<z>*t=0)
{


  tail=t;
}




template <class z> void linkedlist<z>::reverse()
{

 node <z>*temp,*ptr,*prev;
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


template <class z>linkedlist<z>::~linkedlist()
{
 deletethelist();
}

template <class z>int linkedlist<z>::isempty()
{
 if(tail==0)
 return 1;
 return 0;

}


template <class z>void linkedlist<z>:: display()
{
  clrscr();
  if(tail==0)
  {
  cout<<"List is empty";

  }
  else
  {

   cout<<"Elements of the list : \n\n";



  for(node<z>*temp=tail->next;temp!=tail;temp=temp->next)
  {
    cout<<temp->info<<"  ";
  }
    cout<<temp->info<<"  ";
  }
  getch();
}



template<class z> void linkedlist<z>::deletethelist()
{
  for(node<z>*temp=tail->next;temp!=tail;temp=temp->next)
  {
     delete temp;

  }
  delete tail;
  tail=0;

}



template <class z>int linkedlist<z>::isinit(z x)
{
 if(tail->info==x)
 return 1;
 for(node<z>*p=tail->next;p!=tail;p=p->next)
 {
  if(x==p->info)
  return 1;
  }
 return 0;


}

template <class z>void linkedlist<z>::addtotail(z x)
{
  if(tail!=0)
  {
  tail->next= new node<z>(x,tail->next);
  tail=tail->next;
  }
  else
  {
  tail=new node<z>(x,0);
   tail->next=tail;
  }
}

template <class z> z linkedlist<z>::deletefromtail()
{

   if(tail!=0)
   {
    z x=tail->info;

    if(tail==tail->next)
       {
	delete tail;
	tail=0;
	}
     else
       {
       node<z>*ptr;
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

template <class z>void linkedlist<z>::accept()
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

template <class z>
void mainmenu(linkedlist <z>&l)
{
 clrscr();
 char ch;
	z x;



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
		 mm2();
		 break;


	case '0':
		 exit(0);
	default :
	cout<<"\n\n    INVALID CHOICE KINDLY RE-ENTER";
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
