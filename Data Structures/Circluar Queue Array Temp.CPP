#include<iostream.h>
#include<conio.h>
#include<process.h>

template <class z>
class queue
{

 z *a;
 int size;
 int front,rear;


public:

 void accept()
 {
	front=rear=-1;

	clrscr();
	z x;
	cout<<"Enter the size of the queue  : ";
	cin>>size;

	 while(size<=0)
	 {
	   clrscr();
	   cout<<"Invalid size Kindly Re-Enter the size of the queue  : ";

	  cin>>size;


	  }
      a=new z[size];

     cout<<"Enter the "<<size<<" elements of the queue : ";

   for(int i=0;i<size;i++)
    {
     cin>>x;
     enqueue(x);
    }

}

 void display()
 {
   clrscr();

  if(front==-1)
  cout<<"Queue Is Empty ";
  else
  {
  cout<<"Elements of the queue : \n\n";

  for(int i=front;i!=rear;i++)
  {
    cout<<a[i]<<" ";
  if(i==size-1)
  i=-1;
  }
  cout<<a[i];
  }

  getch();
 }

 ~queue()
 {

   delete []a;
 }

 queue()
   {
       front=rear=-1;
       size=0;

     }
  z dequeue()
  {

    clrscr();

    if(front==-1)
	  return -1;
    else
    {

     z x=a[front];

     if(front==rear)
       rear=front=-1;

    else
      {
       front=(front+1)%size;
       }

     return x;
    }
  }

  void enqueue(z x)
  {



    if((rear==size-1&&front==0)||(rear+1==front))
    {
    cerr<<"Queue is Full ";
    getch();
    }
    else
    {
    if(front==-1)
    front=0;

    rear=(rear+1)%size;

    a[rear]=x;
    }

  }

  z frontel()

  {   clrscr();
   if(front==-1)
   {
    return -1;
   }
   else
      return a[front];
   }

   int isempty()
   {
      if(front==-1)
	{
	 return 1;
	}
     return 0;
   }

   void clear()
   {

    front=rear=-1;
   }


};
template<class z>
void mainmenu(queue<z> &);

void mm2()
{


 clrscr();
   char ch;

   cout<<"\"TYPE OF QUEUE\"";
   cout<<"\n\n1.Integer";
   cout<<"\n\n2.Float";
   cout<<"\n\n3.Character ";
   cout<<"\n\nEnter Your Choice : ";
   cin>>ch;
   if(ch=='1')
   {
   queue <int>l;
   l.accept();
  mainmenu(l);

   }
   else if(ch=='2')
   {
     queue <float>l;
   l.accept();
  mainmenu(l);

   }
   else if(ch=='3')
   {

    queue <char>l;
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


template<class z>
void mainmenu(queue<z> &s)
{

 clrscr();
 char ch;
  cout<<"\n\n\t   M.A.I.N.M.E.N.U";
  cout<<"\n\t1.Add an element into the queue ";
  cout<<"\n\t2.Remove an element from the queue ";
  cout<<"\n\t3.Display top element of the queue ";
  cout<<"\n\t4.Clear the queue ";
  cout<<"\n\t5.Check if the queue is clear ";
  cout<<"\n\t6.Display all elements of the queue";
  cout<<"\n\t7.Create a new queue ";
  cout<<"\n\t0.Exit";
  cout<<"\n\tEnter Your Choice : ";
  cin>>ch;

  switch(ch)
  {

   case '1' :
	    clrscr();
	    z x;
	    cout<<"Enter the Element : ";
	    cin>>x;
	    s.enqueue(x);

	    break;
   case '2' :
	    clrscr();
	    {
	    if(s.isempty()==1)
	      cout<<"Queue is Empty ";
	    else
	       cout<<s.dequeue();
	    }
	    getch();
	    break;
   case '3' :
	    clrscr();
	    {
	    if(s.frontel()==-1)
	      cout<<"Queue is Empty ";
	    else
	       cout<<s.frontel();
	    }
	    getch();
	    break;
   case '4' :
	    clrscr();
	    s.clear();
	    cout<<"Queue cleared";
	    getch();
	    break;
   case '5' :
	    clrscr();
	    if(s.isempty()==1)
	      cout<<"Queue is empty ";
	     else
	      cout<<"Queue is non-empty";
	     getch();
	    break;
   case '6' :
	    s.display();
	    break;

   case '7' :
	    mm2();
	    break;
   case '0':
	     exit(0);
   default :

	     cout<<"\n\n\tInvalid Choice Kindly Re-Enter  ";

  }

 mainmenu(s);
}




void main()
{
mm2();
}