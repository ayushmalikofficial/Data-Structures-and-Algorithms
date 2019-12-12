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
void mergesort()
{
   mergesort(0,size-1);
}
void mergesort(int,int);
void merge(int,int);

void display1();
void display();
~array()
{

 delete []a;
}

};
array::array()
{
 opr=0;
 randomize();
 size=random(8)+8;
 a=new int[size];
 for (int i=0;i<size;i++)
 {

  a[i]=random(31);
 }


display();

}

void array::merge(int p,int r)
{
   int m=(p+r)/2;
   int i,j,l;
   int x=m-p+1;
   int y=r-m;
   int z=p-r+1;
   int *c=new int[x];
   int *b=new int[y];
   int *k=new int[z];

   for(i=0;i<x;i++)
    c[i]=a[i+p];

   for(i=0;i<y;i++)
   b[i]=a[i+m+1];


   i=0;j=0;l=0;
   while(i<x&&j<y)
   {
     if(c[i]<b[j])
      {
       opr++;
       k[l++]=c[i++];
      }
     else
      {
      opr++;
      k[l++]=b[j++];
      }
   }

   while(i<x)
   k[l++]=c[i++];

   while(j<y)
   k[l++]=b[j++];

  for(l=0,i=p;i<=r;i++,l++)
  a[i]=k[l];


}
void array::mergesort(int p,int r)
{
  if(p<r)
  {
    int m=(p+r)/2;
    mergesort(p,m);
    mergesort(m+1,r);
    merge(p,r);
  }
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

 cout<<"\n\n\nNo of Comparisons : "<<opr;
 getch();

}

void main()
{
clrscr();


array obj;
obj.mergesort();
obj.display1();
getch();


}