#include<iostream.h>
#include<conio.h>

class array
{
  int *a,size;

 public :
 void accept();
 void display();
 array();
 array(int );
 int range();
 void countsort(int&);
 ~array()
 {

  delete []a;
 }
};

array::array()
{
 size=0;
 a=0;

}

array::array(int x)
{
  size =x;
  a=new int[x];

  for (int i=0;i<size;i++)
  a[i]=0;

}
int array::range()
{

 int i,max=a[0];
  clrscr();

  for(i=1;i<size;i++)
  {
   if(a[i]>max)
   max=a[i];

  }
  return max;
}

void array::countsort(int &opr)
{
  int i,j;

  int *c;
  int x=range();
  x++;
  c=new int[x];

 for (i=0;i<x;i++)
 {
   opr++;
  c[i]=0;
 }

  for (j=0;j<size;j++)
  {
   opr++;
   c[a[j]]++;
   }


  clrscr();
  for(i=0;i<x;i++)
  cout<<c[i]<<" ";
  getch();


 for (i=1;i<x;i++)
 {
 opr++;
 c[i]=c[i]+c[i-1];
 }
  clrscr();
  for(i=0;i<x;i++)
  cout<<c[i]<<" ";
  getch();

  int *b=new int[size];
  for( i=0;i<size;i++)
  {
  
  b[i]=0;
  }
  for(j=size;j>-1;j--)
  {
    b[c[a[j]]-1]=a[j];
    c[a[j]]--;
   opr++;
  }

  for(i=0;i<size;i++)
  {
  opr++;
  a[i]=b[i];
  }
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

   a=new int[size];
   cout<<endl<<"Enter the elements of the array :\n\n";
   for(int i=0;i<size;i++)
   {

   cout<<i+1<<" Element : ";
   cin>>a[i];
   }
   getch();

}

void main()
{

 array obj;
 int opr=0;
 obj.accept();
 obj.display();
 obj.countsort(opr);
 clrscr();
  cout<<"Sorted Array : ";
 getch();
 obj.display();
 clrscr();
 cout<<"No of operations : "<<opr;
 getch();
}
