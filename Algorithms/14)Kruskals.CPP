#include<conio.h>
#include<iostream.h>

class set
{
 char a;
 set *rep;
 set *next;



 public:


 set(int x)
  {

  a=x;
  rep=0;
  next=0;

  }

 void set_rep()
 {

  rep=this;

 }


void setunion(set *);
friend class vertex;
friend class graph;
};
void set::setunion(set *obj)
{

 set* temp;


 for(temp=this;temp->next!=0;temp=temp->next);
 temp->next=obj;
 for(temp=obj;temp!=0;temp=temp->next)
   {

     temp->rep=this;
   }



}

class edge
{
 char a,b;
 int w;
 int flag;
 public:
   friend class graph;
   edge()
   {

    a=b=w=flag=0 ;

   }
};

class vertex
{
  char value;
  set* p;

  public:
  vertex()
  {
   value=0;
   p=0;

  }

  friend class graph;

};


class graph
{
   vertex  *vertexarray;

   int e,v;
   public:
  edge* edgearray;
  graph();
  void display();
  void sort();
 set* findset(char );
void kruskals();
 } ;



set* graph::findset(char x)
{
   for(int i=0;i<v;i++)
   {
     if(vertexarray[i].value==x)
     {
   //   cout<<(vertexarray[i].p)->rep->a;
   //   getch();
      return (vertexarray[i].p)->rep;

     }
   }
// cout<<"Set not found";
// getch();
 return 0;
}
void graph::sort()
{
 int i,j;
 for(i=0;i<e;i++)
 {
   for(j=0;j<e-i-1;j++)
   {
     if(edgearray[j].w>edgearray[j+1].w)
     {
       edge temp;
       temp=edgearray[j];
       edgearray[j]=edgearray[j+1];
       edgearray[j+1]=temp;
     }

   }

 }

}

void graph::display()
{
 clrscr();
 int i;
 cout<<"\t\t\tTHE GRAPH  \n\n";

 cout<<"VERTEX SET \n\n";
 for(i=0;i<v;i++)
 {
  cout<<vertexarray[i].value/*<<"("<<vertexarray[i].p->a<<")"*/<<"\n";
 }
 cout<<"\n\nEDGES \n\n";
 sort();
 for(i=0;i<e;i++)
 {

    cout<<edgearray[i].a<<"-"<<edgearray[i].b<<" ("<<edgearray[i].w<<")"<<"\n";
 }
 getch();
}


void graph::kruskals()
{
   int i;
    set*r,*s;
  for( i=0;i<v;i++)
  {
    vertexarray[i].p= new set(vertexarray[i].value);
    (*(vertexarray[i].p)).set_rep();
   }
  for(i=0;i<e;i++)
  {
   r=findset(edgearray[i].a);
   s=findset(edgearray[i].b);

     if(r!=s)
     {
      edgearray[i].flag=1;
      (*r).setunion(s);
     }

  }
  clrscr();
  cout<<"Minimum Spanning Tree \n\n";

 for(i=0;i<e;i++)
 {
    if(edgearray[i].flag==1)
    cout<<edgearray[i].a<<"-"<<edgearray[i].b<<" ("<<edgearray[i].w<<")"<<"\n";

 }

 getch();

}
graph::graph()
{
 int i,j;
 clrscr();
 char ch;
 cout<<"Enter the no of vertices :";
 cin>>v;

 vertexarray=new vertex[v];

 for(i=0;i<v;i++)
 {

  cout<<"Enter "<<i+1<<" Vertex : ";
  cin>>vertexarray[i].value;

 }
 cout<<"\n\nEnter the no of edges :" ;
 cin>>e;
 edgearray=new edge[e];

  for(i=0;i<e;i++)
  {
     cout<<"Edge "<<i+1<<" Vertex 1 :";
     edgearray[i].a=getche();
     cout<<" Vertex 2 : ";
     edgearray[i].b=getche();
     cout<<" Weight : ";
     cin>>edgearray[i].w;

  }
 getch();

}


void main()
{
     char x;
     graph obj;

     obj.display();
     obj.kruskals();
}