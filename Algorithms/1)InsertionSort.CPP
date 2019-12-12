#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

int insertionsort(int a[],int size);
void arraygenerator();
void main()
{
 clrscr();
  for(int i=0;i<30;i++)
  {
  clrscr();
  arraygenerator();
  getch();
  }
 getch();

}

void arraygenerator()
{
 randomize();
 int size,*a,x,m;
 size=random(26)+5;
 cout<<"No. of Elements : "<<size<<endl<<endl;
 a=new int[size];
 for(m=0;m<size;m++)
 {
   x=random(1000)+1;
   a[m]=x;
 }
 /*cout<<"\nElements of the array : \n";
 for(m=0;m<size;m++)
 {
  cout<<a[m]<<" ";
 } */
 cout<<"\n\nNo of Comparisons : "<<insertionsort(a,size);
 /*cout<<"\n\nElements of the array after sorting : \n";
 for(m=0;m<size;m++)
 {
  cout<<a[m]<<" ";
 } */

}
int insertionsort(int a[],int size)
{

  int i,j,temp,count=0;

 for( i=1;i<size;i++)
 {
  temp=a[i];
  j=i-1;

 while(j>-1)
 {
 count++;
 if(a[j]>temp)
 {
  a[j+1]=a[j];
  j--;
 }
 else
  break;

 }
 a[j+1]=temp;

 }
 return count;
}