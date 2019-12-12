#include<iostream.h>
#include<conio.h>

class vertex;

////////////////////////Class Vertex Of Adjacency Linked-List///////////////

class avertex
{
   char v;
   avertex *next;
   vertex *ptr;
   int w;
   public:
   avertex(char,int p,vertex *);
   friend class adjlist;
   friend class graph_ll;
};
////////////////////////Class Vertex Original//////////////////////////////
class vertex
{
  char value;
  char  p;
  int flag;
  int k;
  adjlist *adj;

 public:

 vertex()
 {
 value='*';
 p='*';
 k=999;
 adj=0;
 flag=0;
 }

 friend class graph_ll;
 friend class adjlist;
};


////////////////////////////////////////////////////////////////////////////

avertex:: avertex(char ch,int p,vertex *x)
{
  v=ch;
  next=0;
  ptr=x;
 w=p;
}


///////////////////////////Class Adjacency List/////////////////////////////

class adjlist
{
   avertex *head1,*tail1;

   public:
   void  addtotail(char c,int,vertex *);
   adjlist();
   void display();
 friend class graph_ll;
};

void adjlist::display()
{
  avertex *temp=head1;
  if(head1)
  {
  cout<<" "<<temp->v<<"("<<temp->w<<")"<<" ("<<temp->ptr->value<<")";

  temp=temp->next;
  }
  while(temp)
  {
   cout<<" , "<<temp->v<<"("<<temp->w<<")"<<" ("<<temp->ptr->value<<")";
   temp=temp->next;
  }
}
adjlist::adjlist()
{

  head1=tail1=0;
}

void adjlist::addtotail(char ch,int p,vertex *x)
{

  if(head1==0)
  {

    head1=tail1=new avertex(ch,p,x);
  }
  else
  {

   tail1->next=new avertex(ch,p,x);
   tail1= tail1->next;
  }

}









class graph_ll
{
  vertex *a;
  int size;
  int heapsize;
  public:
  void input(char);
  graph_ll();
  void accept();
  graph_ll(int);
  void display();
  void inputadj();
  void buildminheap();
  vertex *extractmin();
  void minheapify(int);
  void prim();
  void display_prim();
};

void graph_ll::prim()
{
   vertex *temp;
    a[0].k=0;

  while(heapsize)
  {

     temp=extractmin();
     cout<<temp->value<<" "<<temp->p<<" "<<temp->k;
     cout<<"\n";
     temp->adj->display();
     getch();

   for(avertex *i=temp->adj->head1;i!=0;i=i->next)
     {

	   if((i->w < i->ptr->k)&&i->ptr->flag==0)
	   {
		i->ptr->k=i->w;
		i->ptr->p=temp->value;

	   }

     }
     buildminheap();
  }

}

void graph_ll:: display_prim()
{

 clrscr();


  cout<<"--\4\4MINIMUM SPANNING TREE\4\4--\n\n";

       for(int i=0;i<size&&a[i].p!='*';i++)
       cout<<a[i].value<<" - "<<a[i].p<<" "<<" ("<<a[i].k<<")"<<endl;



getch();
}
void graph_ll::buildminheap()
{
  int i,j;


 for( i=heapsize-1;i>=0;i--)
 {
 minheapify(i);

 }

  for(i=0;i<size;i++)
  {

   for(avertex *temp=a[i].adj->head1;temp!=0;temp=temp->next)
       {

	 for(j=0;j<size;j++)
	 {

	    if(a[j].value==temp->v)
	     {
	      temp->ptr=(&a[j]);
	      break;
	     }
	 }

       }
  }
}


vertex * graph_ll::extractmin()
{
   clrscr();
   int i,j;
   for( i=0;i<size;i++)
   {

   cout<<i+1<<a[i].value<<" "<<a[i].p<<" "<<a[i].k<<"\n";
   }

   vertex temp;
   temp=a[0];
   a[0]=a[heapsize-1];
   a[heapsize-1]=temp;
   heapsize--;
   a[heapsize].flag=1;
   minheapify(0);

   for(i=0;i<size;i++)
  {

   for(avertex *temp=a[i].adj->head1;temp!=0;temp=temp->next)
       {

	 for(j=0;j<size;j++)
	 {

	    if(a[j].value==temp->v)
	     {
	      temp->ptr=(&a[j]);
	      break;
	     }
	 }

       }
  }
  return &(a[heapsize]);

}
void graph_ll::minheapify(int i)
{
  int r,l;
  l=2*i+1;
  r=2*i+2;
  int smallest;

 if(l<heapsize &&  a[l].k<a[i].k)
    {
	 smallest=l;
    }
 else
     smallest=i;


  if(r<heapsize && a[r].k<a[smallest].k)
    {

    smallest =r;

    }
  if(smallest!=i)
  {

   vertex temp=a[i];
   a[i]=a[smallest];
   a[smallest]=temp;
   minheapify(smallest);
  }




}



void graph_ll::accept()
{

 for (int i=0;i<size;i++)
 {
    cout<<"\nEnter "<<i+1<<"th Vertex of the graph : ";
    cin>>a[i].value;


 }

 inputadj();

 display();




}

void graph_ll::display()
{
  clrscr();

  cout<<"--\4\4GRAPH\4\4--";

    cout<<endl<<endl;
  for(int i=0;i<size;i++)
  {
  cout<<a[i].value<<" : ";
  a[i].adj->display();
  cout<<endl;
  }
  getch();

}

graph_ll::graph_ll()
{
  a=0;
  size=0;
}
graph_ll::graph_ll(int x)
{

  size =x;
  a=new vertex[size];
 heapsize=size;
}


void graph_ll::inputadj()
{
  int i,j,k,n,p;
  char ch;
  cout<<"\n\n";
  for(j=0;j<size;j++)
{
   cout<<"\nEnter the no of nodes adjacent to vertex "<<a[j].value<<" : ";
   cin>>n;
   a[j].adj=new adjlist();
   cout<<"\nEnter the "<<n<<" adjacent elements ("<<a[j].value<<"): \n";
   for (int i=0;i<n;i++)
    {
       cout<<i+1<<". ";
       cin>>ch;
	 cout<<" weight : ";
	 cin>>p;
	  for(k=0;k<size;k++)
	     {
	       if(a[k].value==ch)
		    {
		    //	a[j].adj->display();
		       a[j].adj->addtotail(ch,p,&(a[k]));
		       break;
		     }
	      }

    // a[j].adj->display();

     }

}

}






//////////////////////////////////////////////////////////////////


void main()
{
 clrscr();

 cout<<"Enter the no of vertices you wish to create : ";
 int n;
 cin>>n;
 graph_ll obj(n);
 obj.accept();
 obj.prim();
 obj.display_prim();
}