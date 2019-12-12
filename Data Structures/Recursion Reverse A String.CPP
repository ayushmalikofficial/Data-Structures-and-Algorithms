#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void reverse(char *a)
{
  if(a[0]=='\0');
  else
  {
   reverse(a+1);
   cout<<a[0];
  }

}


void main()
{

clrscr();

int x;
char *a;
cout<<"Enter the size of the string: ";
cin>>x;
a=new char[x];
cout<<"\nEnter the string : ";
for(int i=0;i<x;i++)
{

 a[i]=getche();
 if(a[i]==13)
 break;
}
a[i]='\0';
getch();
clrscr();
cout<<"Reverse of the string : ";
reverse(a);




getch();
}