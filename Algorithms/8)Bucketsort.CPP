#include<iostream.h>
#include<conio.h>
#include<math.h>



//Note : exam mai singly linked list mai orderly se karni hai bajaye selection sort ke

class node
{
     float info;
     node *next;

public:

friend class bucket;
friend class array;
node(float x,node*n);

};

class bucket
{
	node *head;
	node *tail;

 public:

bucket( node*n=0,node*t=0)
{

  head=n;
  tail=t;
}

void insertionsort(int&);
void addtotail(float x);  //done

int isempty();
void accept();//done
void deletethelist();     //done
~bucket();
void display();           //done
friend class array;
};



class array
{
  float *a,size;

 public :
 void accept();
 void display();
 array();
void  bucketsort(int&);
 array(float );
 ~array()
 {

  delete []a;
 }
};

void array::bucketsort(int&opr)
{
    bucket *obj;
     node *temp;
    int i,j;
    obj=new bucket[size];
    for( i=0;i<size;i++)
    {
      opr++;
     obj[floor(a[i]*size)].addtotail(a[i]);
    }

    for(i=0;i<size;i++)
    {
    
    obj[i].insertionsort(opr);
    }
    for(i=0,j=0;i<size;i++)
    {

      for(temp=obj[i].head;temp!=0;temp=temp->next,j++)
      {
	    opr++;
	    a[j]=temp->info;
      }

    }


}
array::array()
{
 size=0;
 a=0;

}

array::array(float x)
{
  size =x;
  a=new float[x];

  for (int i=0;i<size;i++)
  a[i]=0;

}


void array::display()
{
   clrscr();
   cout<<"Elements of the array : ";
   for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
   getch();

}
void array::accept()
{
   clrscr();

   cout<<"Enter the No of Elements in the array : ";
   cin>>size;

   a=new float[size];
   cout<<endl<<"Enter the elements of the array :\n\n";
   for(int i=0;i<size;i++)
   {

   cout<<i+1<<" Element : ";
   cin>>a[i];
   }
   getch();

}



class node;

bucket::~bucket()
{
 deletethelist();
}
int bucket::isempty()
{
 if(head==0)
 return 1;
 return 0;

}


void bucket:: display()
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


void bucket::deletethelist()
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

node::node(float x,node *n= 0)
{

info=x;
next=n;

}

void bucket::addtotail(float x)
{
  if(tail!=0)
  {
  tail->next= new node(x);
  tail=tail->next;

  }
  else
  head=tail=new node(x);

}

void bucket::insertionsort(int &opr)
{
      node*i,*j,*pos;
      float temp;
      for(i=head;i!=tail;i=i->next)
	{
	   pos=i;
	    for(j=i->next;j!=0;j=j->next)
	   {
	      opr++;
	      if(j->info < pos->info)
	       pos=j;

	   }

	   temp=i->info;
	   i->info=pos->info;
	   pos->info=temp;

       }
}


void bucket::accept()
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


void main()
{


     array obj;
     int opr =0;
     obj.accept();
     obj.bucketsort(opr);
     obj.display();
     clrscr();
     cout<<"No of Operations : "<<opr;
     getch();
}
