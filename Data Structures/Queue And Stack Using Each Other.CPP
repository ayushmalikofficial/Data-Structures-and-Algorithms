#define newconcept
#include"queuell.cpp"

class q
{
  stack s1;
  public:
 void enqueue(int);
 int dequeue();
 void qa();
 void qd();

};
int q::dequeue()
{
 int x;
 stack s2;
 while(1)
 {
   x=s1.pop();

 if(s1.isempty())
 {
  while(!s2.isempty())
  {
   s1.push(s2.pop());
  }
  return x;
 }
 else
 s2.push(x);

 }
}
void q::enqueue(int x)
{

    s1.push(x);
}


void q::qa()
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
 enqueue(y);
 }



}

void q::qd()
{
  int x;
  stack s2;
  while(!s1.isempty())
  {
   x=s1.pop();
   s2.push(x);
  }
  while(!s2.isempty())
  {
   x=s2.pop();
   cout<<x<<" ";
   s1.push(x);
  }
}

class s
{
   queue q1;
   public:

int pop();
void push(int);
void sa();
void sd();

};




void s::push(int x)
{

  queue q2;
  while(!q1.isempty())
  {
  q2.enqueue(q1.dequeue());
  }
  q1.enqueue(x);
  while(!q2.isempty())
  {
   q1.enqueue(q2.dequeue());
  }

}
int s::pop()
{
    return q1.dequeue();

}


void s::sd()
{
 q1.display();

}
void s::sa()
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
 push(y);
 }

}


void main()
{

clrscr();

 s a;
 a.sa();
 a.sd();
cout<<endl<<a.pop()<<endl;
a.sd();



getch();

}