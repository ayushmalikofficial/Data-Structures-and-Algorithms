#include<iostream.h>
#include<conio.h>
#include<math.h>
class array
{
  int *a,size;

 public :

 void accept();
 void display();
 array();
 array(int );
 int range();
 void radixsort(int &);
 void countsort(int,int,int&);

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

void array::countsort(int z,int x,int &opr)
{
  int i,j;

  int c[10];

 for (i=0;i<10;i++)
 {
  c[i]=0;
 opr++;
 }

  for (j=0;j<size;j++)
  {

   c[(a[j]%z)/x]++;
   opr++;
   }


/*  clrscr();
  for(i=0;i<10;i++)
  cout<<c[i]<<" ";
  getch();
  */

 for (i=1;i<10;i++)
 {
 c[i]=c[i]+c[i-1];
 opr++;
 }
/*  clrscr();
  for(i=0;i<10;i++)
  cout<<c[i]<<" ";
  getch();
 */
  int *b=new int[size];
  for( i=0;i<size;i++)
  {
  
  b[i]=0;
  }
  for(j=size-1;j>-1;j--)
  {
    b[c[(a[j]%z)/x]-1]=a[j];
    c[(a[j]%z)/x]--;
     opr++;
  }

  for(i=0;i<size;i++)
  a[i]=b[i];


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

int no_of_digits(int x)
{
  int n=0;
   while(x)
   {
    n++;
    x=x/10;
   }

   return n;
 }


void array :: radixsort(int &opr)
{

 int x=range();
 int d=no_of_digits(x);

 for (int i=0;i<d;i++)
 {

     countsort(pow(10,i+1),pow(10,i),opr);
 }

 getch();

}

void main()
{

 array obj;
 int opr;
 obj.accept();
 obj.radixsort();
 obj.display();
 clrscr();
 cout<<"No of Operations : "<<opr;

 getch();
}