#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

class array
{
   int *a;
   int size;
   int opr;


public:
array();
void quicksort()
{

 quicksort(0,size-1);
}

void quicksort(int,int);
int partition(int,int);

void display1();
void display();
~array()
{

 delete []a;
}

};

void array::quicksort(int p,int r)
{
if(p<r)
{
 int q;
 q=partition(p,r);
 quicksort(p,q-1);
 quicksort(q+1,r);
}

}
int array:: partition(int p,int r)
{
 int i,x,j;
  x=a[p];
  i=p;
  j=r;
  while(1)
  {
     while(a[j]>x)
     {
     opr++;
     j=j-1;
     }
     while(a[i]<x)
     {
     opr++;
     i=i+1;
     }
     if(a[i]==a[j])
     {
     opr++;
     i=i+1;
     }
     if(i<j)
     {
      int temp=a[i];
      a[i]=a[j];
      a[j]=temp;

     }
     else
     return j;

  }

}


array::array()
{

 randomize();
 opr=0;
 size=random(8)+8;
 a=new int[size];
 for (int i=0;i<size;i++)
 {

  a[i]=random(31);
 }


display();

}

void array::display()
{

 clrscr();

 cout<<"ARRAY\n\n";
 for(int i=0;i<size;i++)
 cout<<i+1<<") "<<a[i]<<"\n";
 getch();

}
void array::display1()
{

 clrscr();

 cout<<"ARRAY\n\n";
 for(int i=0;i<size;i++)
 cout<<i+1<<") "<<a[i]<<"\n";

 cout<<"\n\nNo of Comparisons  : "<<opr;
 getch();

}

void main()
{
clrscr();


array obj;
obj.quicksort();
obj.display1();
getch();


}