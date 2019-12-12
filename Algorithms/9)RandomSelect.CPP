#include<iostream.h>
#include<conio.h>


class array
{
  int *a,size;

 public :
 void accept();
 void display();
  void partition();
 array();
 array(int );
 ~array()
 {

  delete []a;
 }
 int partition(int,int);
 int randsel(int);
 int randsel(int,int,int);
};
int array::randsel(int x)
{

  int z= partition(0,size-1);

  if(x>size||x<0)
      return -1;

   else
   return randsel(0,size-1,x);

  return 0;
}

int array::randsel(int p , int r,int i)
{
  int k,q;

  if(p==r)
  return a[p];

  q=partition(p,r);

  k=q-p+1;



  if(i==k)
   return a[q];

  else if(i<k)
    return randsel(p,q-1,i);

   else
   return randsel(q+1,r,i-k);


}








int array:: partition( int p,int r)
{
 int x =a[p];
 int i=p;
 int j=r;

 while(i<j)
 {
   if(a[i]==a[j])
   {
   i++;
   }

   while(a[i]<x)
   {

    i=i+1;
   }
   while(a[j]>x)
   {
    j=j-1;
   }
 if(i<j)
 {
  int temp= a[i];
  a[i]=a[j];
  a[j]=temp;

 }
 else
 return j;


}
}




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
void array::partition()
{
 partition(0,size-1);

}
void main()
{

  array obj;
  int x;
  obj.accept();
  obj.display();

  cout<<"\n\n\n\nEnter the Rank of the element to be searched : " ;
  cin>>x;
  obj.partition();

  int r=obj.randsel(x);

  if(r==-1)
  cout<<"\n\nInvalid rank input  ";
  else
  cout<<"\n\nRequired Element: "<<r;

getch();
}