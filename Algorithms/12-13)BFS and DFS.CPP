#include<iostream.h>
#include<conio.h>

class vertex;

////////////////////////Class Vertex Of Adjacency Linked-List///////////////

class avertex
{
   char v;
   avertex *next;
   vertex *ptr;
   public:
   avertex(char,vertex *);
   friend class adjlist;
   friend class graph_ll;
};

avertex:: avertex(char ch,vertex *x)
{
  v=ch;
  next=0;
  ptr=x;
}
//////////////////////////////////////////////////////////////////////////

///////////////////////////Class Adjacency List/////////////////////////////

class adjlist
{
   avertex *head1,*tail1;

   public:
   void  addtotail(char c,vertex *);
   adjlist();
   void display();
 friend class graph_ll;
};

void adjlist::display()
{

  avertex *temp=head1;
  if(head1)
  {
  cout<<" "<<temp->v<<"("<<temp->ptr<<")";
  temp=temp->next;
  }
  while(temp)
  {
   cout<<" , "<<temp->v<<"("<<temp->ptr<<")";
   temp=temp->next;
  }
}
adjlist::adjlist()
{

  head1=tail1=0;
}

void adjlist::addtotail(char ch,vertex *x)
{

  if(head1==0)
  {

    head1=tail1=new avertex(ch,x);
  }
  else
  {

   tail1->next=new avertex(ch,x);
   tail1= tail1->next;
  }

}



//////////////////////////////////////////////////////////////////////////



 ////////////////////////Class Vertex Original//////////////////////////////
class vertex
{
  char v;
  vertex *p;
  char c;
  int d;
  int des,f;
  vertex *next;
  adjlist *adj;
 public:

 vertex(char ch)
 {
  p=0;
  d=99;
  des=f=0;
  c='w';
  v=ch;
  adj=new adjlist();
  next=0;
 }

 friend class graph_ll;
 friend class queue;
 friend class adjlist;
};
/////////////////////////////////////////////////////////////////////////
///////////////////////Class Queue//////////////////////////
class queue
{
  vertex *front ,*rear;

 public:
 void enqueue(vertex * );
 vertex * dequeue();
  int isempty()
  {
      if(front!=0)
      return 1;
      return 0;

  }
  queue();

};

////////////////////////////////////////////////////////////////////////////


class graph_ll
{
  vertex *head,*tail;
  int time;
  public:
  void input(char);
  graph_ll();
  void display();
  void inputadj();
  void bfs(vertex *);
  void bfs();
  void dfs();
  void dfs_visit(vertex *);
  void dfs_search();
};
   void graph_ll::dfs_search()
   {

   clrscr();

      dfs();

      for(vertex* temp = head;temp!=0;temp=temp->next)
      {
	cout<<endl<<endl;

	cout<<"Vertex : "<<temp->v<<" ("<<temp->des<<"/"<<temp->f<<") "<<"parent ("<<temp->p->v<<" )"<<temp->c;

	getch();

	     }


  }



  void graph_ll::dfs()
  {

     vertex* u=head;
     for(;u!=0;u=u->next)
	  {
	    if(u->c=='w')
	    {
	     dfs_visit(u);
	     }
	   }


  }

  void graph_ll::dfs_visit(vertex * u)
  {
	  time=time+1;
	  u->des=time;
	  u->c='g';
	  for (avertex *v=u->adj->head1;v!=0;v=v->next)
	  {
	    if(v->ptr->c=='w')
	     {
		v->ptr->p=u;
		dfs_visit(v->ptr);

	     }

	  }
	u->c='b';
	time=time+1;
	u->f=time;
  }
  void graph_ll::bfs()
  {
	 clrscr();
	 vertex *s,*temp2;
	 char ch;
     cout<<"\nEnter the source vertex : ";
    cin>>ch;

     for(temp2=head;temp2!=0;temp2=temp2->next)
	     {
	      if(temp2->v==ch)
		 {
		     s=temp2;
		     cout<<endl<<s->v;
		     getch();
		    bfs(temp2);
		   break;
		 }
	      }

    cout<<"\n\nEnter the destination vertex : \n";
    cin>>ch;

     for(temp2=head;temp2!=0;temp2=temp2->next)
	     {
		if(temp2->v==ch)
		   {
		       cout<<endl<<temp2->v;
		       getch();
		      break;
		    }
	      }

       clrscr();
       cout<<"Required Path \n\n";


      if(temp2!=0 && temp2->c!='w')
      {
	 while(temp2!=s)
	 {

	  cout<<temp2->v<<" ->";
	  temp2=temp2->p;
	 }
	 cout<<s->v;
      }
      else
      {

       cout<<"Vertex Not Found";
      }

    getch();
  }

void graph_ll::bfs(vertex * s)
{
  vertex *u;
  s->c='g';
  s->d=0;
  s->p=0;

  queue q;
  q.enqueue(s);
  while((q.isempty()))
  {
   u=q.dequeue();
   for (avertex * v = u->adj->head1;v;v=v->next)
   {
       if(v->ptr->c == 'w')
       {
	  v->ptr->c='g';
	  v->ptr->d=u->d+1;
	  v->ptr->p=u;
	  cout<<v->ptr->v;
	  q.enqueue(v->ptr);

       }

   }

   u->c='b';
  }



}

void graph_ll::display()
{
  clrscr();

  vertex *temp=head;
  while(temp)
  {
   cout<<endl<<temp->v<<"("<<temp<<")"<<" => ";
   temp->adj->display();
   temp=temp->next;
  }

  getch();

}
graph_ll::graph_ll()
{
  head=tail=0;
  time=0;

}


void graph_ll::input(char ch)
{
   if(head==0)
   {
      head=tail=new vertex(ch);
    }


  else
   {

   tail->next =new vertex(ch);

   tail=tail->next;
  }
}

void graph_ll::inputadj()
{
  vertex *temp=head;
  vertex* temp2=head;
  int n;
  char ch;
  while(temp)
  {
   cout<<"Enter the no of nodes adjacent to vertex "<<temp->v<<" : ";
   cin>>n;
   cout<<"\nEnter the "<<n<<" adjacent elements ("<<temp->v<<"): \n";
   for (int i=0;i<n;i++)
    {
       cin>>ch;

	  for(temp2=head;temp2!=0;temp2=temp2->next)
	     {
	      if(temp2->v==ch)
		 {

		   temp->adj->addtotail(ch,temp2);
		   break;
		 }
	      }
     }

  temp=temp->next;
  }

}






 queue::queue()
 {

  front=rear=0;

 }

 vertex* queue :: dequeue()
 {
   vertex *x=front;
   if(front == rear)
   {
   front=rear=0;
   }
   else
   {
    front = front->next;

   }

   return x;
 }


 void queue::enqueue(vertex *p)
 {
  if(front==0)
  {
  front=rear=p;
  }

  else
  {
   rear->next=p;

   rear=p;
   p->next=0;
  }

 }

//////////////////////////////////////////////////////////////////


void main()
{
 clrscr();
 graph_ll obj;
 cout<<"Enter the no of vertices you wish to create : ";
 int n;
 cin>>n;
 char ch;
 for (int i=1;i<=n;i++)
 {
    cout<<"\nEnter "<<i<<"th Element of the graph : ";
     cin>>ch;
    obj.input(ch);

 }

 obj.inputadj();

 obj.display();



 //  obj.bfs();
 obj.dfs_search();

}