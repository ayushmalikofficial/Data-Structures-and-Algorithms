#include<iostream.h>
#include<conio.h>

int power(int a,int b)
{
   if(b==1)
   return a;
   if(b==0)
   return 1;
   return a*power(a,b-1);
}

void main()
{
int a,b;
clrscr();
cout<<"FOR a^b : \n";
cout<<"Enter a : ";
cin>>a;
cout<<"Enter b : ";
cin>>b;
cout<<power(a,b);
 getch();
}