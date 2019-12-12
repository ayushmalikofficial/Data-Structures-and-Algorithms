#include<iostream.h>
#include<conio.h>
#include<math.h>

class array
{
  int *a,size;
   int heapsize;

 public :
 void accept(int&);
 void display(int&);
 void buildmaxheap(int&);
 void maxheapify(int,int&);
 void heapsort(int&);
 array();
 array(int);
 ~array()
 {

  delete []a;
 }
};
void array::display(int &comp)
{
   clrscr();
   cout<<"Elements of the array : ";
   for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
   getch();
  clrscr();
  cout<<"No of Comparisons : "<<comp;
  getch();

}

void array::buildmaxheap(int &comp)
{

  if(size>1)
  {
 for(int i= floor(size-2/2);i>=0;i--)
 {
 maxheapify(i,comp);

 }
 }
}

void array::heapsort(int &comp)
{
  int temp;
 buildmaxheap(comp);

 for(int i=size-1 ;i>-1;i--)
 {
  temp=a[0];
  a[0]=a[i];
  a[i]=temp;

 heapsize--;
  maxheapify(0,comp);

 }
}
void array::accept(int &comp)
{
   clrscr();

   cout<<"Enter the No of Elements in the array : ";
   cin>>size;
     heapsize=size;
   a=new int[size];
   cout<<endl<<"Enter the elements of the array :\n\n";
   for(int i=0;i<size;i++)
   {

   cout<<i+1<<" Element : ";
   cin>>a[i];
   }



   getch();

}

void array::maxheapify(int i,int &comp)
{

  int r=2*i+2;
  int l=2*i+1;
  int largest;

 if(l<heapsize &&  a[l]>a[i])
    {  comp++;
	 largest=l;
    }
 else
     largest=i;


  if(r<heapsize && a[r]>a[largest])
    {
    comp++;
    largest =r;

    }
  if(largest!=i)
  {

    int temp=a[i];
   a[i]=a[largest];
   a[largest]=temp;
   maxheapify(largest,comp);
  }




}

array::array()
{
 heapsize=size=0;
 a=0;

}

array::array(int x)
{
  heapsize=x;
  size =x;
  a=new int[x];

  for (int i=0;i<size;i++)
  a[i]=0;

}

 void main()
 {
  array obj;
  int comp=0;
  obj.accept(comp);

  obj.heapsort(comp);
  obj.display(comp);

 }