#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>




class stack
{

 int *a;
 int size;
 int top;

public:

 void accept()
 {


 clrscr();
 int x;
 cout<<"\aEnter the No of Digits in the no.  : ";
 cin>>x;
 while(x<=0)
 {
   clrscr();
   cout<<"\aInvalid size Kindly Re-Enter the size of the stack  : ";
   cin>>x;


 }
  char y;
  a=new int[x];
  size=x;
  clrscr();
  cout<<"\aEnter The "<<x<<" Digit No. : ";

  for(;top<size-1;)
   {
     y=getche();
     if(y==(13))
	break;
     push(int(y)-48);
    }

   getch();
 }
 void display()
 {
   clrscr();
  if(top==-1)
  cout<<"\aStack Is Empty ";
  else
  {
  cout<<"\aElements of the stack : \n\n";
  for(int temp=top;temp>=0;temp--)

  {
   cout<<a[temp]<<endl;
  }
  }
   getch();
 }

 stack()
   {
       top=-1;
       size=0;
     }
     stack(int x)
     {

     top =-1;
     size=x;
     a=new int[x];
     }
  int pop()
  {

    clrscr();
    if(top==-1)

	  return -1;

    else
    {
       top--;
       return a[top+1];
   }
  }

  void push(int x)
  {

   if(top==size-1)
   {
    clrscr();
    cerr<<"\aStack overflow ";
    getch();
    }

   else
   {
    a[++top]=x;
    }
   }
  int topel()

  {   clrscr();
   if(top==-1)
   {
    return -1;
   }
   else
      return a[top];
   }
   int isempty()
   {
      if(top==-1)
	{
	 return 1;
	}
     return 0;
   }

   void clear()
   {

    top=-1;
   }

 stack sum(stack s)
   {
    clrscr();
    int x,y,k,c=0;
    if(size>=s.size)
    {
     stack s3(size+1);
     while(s.top>-1)
     {
      y=s.pop();
      x=pop();
      s3.push((x+y+c)%10);
      c=(x+y+c)/10;
     }
     while(top>-1)
     {
      x=pop();
      s3.push((x+c)%10);
      c=(x+c)/10;

     }
     s3.push(c);

    return s3;

    }
    else
    {
      stack s3(s.size+1);

     while(top>-1)
     {
      y=s.pop();
      x=pop();
      s3.push((x+y+c)%10);
      c=(x+y+c)/10;
     }
     while(s.top>-1)
     {
      x=s.pop();
      s3.push((x+c)%10);
      c=(x+c)/10;

     }
     s3.push(c);

    return s3;

    }

    getch();
    }


   ~stack()
   {
   delete []a;
   }
};

void main()
{

clrscr();

   stack s1,s2;
 s1.accept();
  s1.display();
   s2.accept();
  s2.display();

 stack s3=s1.sum(s2);
s3.display();




}