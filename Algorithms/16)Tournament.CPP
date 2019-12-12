#include<iostream.h>
#include<conio.h>
#include<math.h>

class node
{
  int w,cw;
  public:
  node()
  {

  w=cw=0;
  }

friend class level;
friend class array;
};

class level
{
 node*l;
 int lsize;
 public:
 level(int);
 friend class array;
 void display();
  int ret_lsize()
  {
  return lsize;
  }


};
void level::display()
{
  clrscr();
  cout<<"Level Index Array :\n\n";
  cout<<"level\twidth\tc.w.\n";
  for(int i=0;i<lsize;i++)
  cout<<i<<"\t"<<l[i].w<<"\t"<<l[i].cw<<endl;


  getch();



}
level::level(int x)
{
float n=x;
    lsize=0;
 while(n>1)
 {
  n=ceil(n/2);
  lsize++;


 }
 n=x;
 lsize++;
 l=new node[lsize];
// cout<<lsize;
 getch();
 l[0].cw=1;
 for(int i=lsize-1;i>-1;n=ceil(n/2),i--)
 {
       l[i].w=n;


 }
 for(i=1;i<lsize;i++)
 {
     l[i].cw=l[i].w+l[i-1].cw;


 }
 display();

}
class array
{
int *a;
int size,s,secs;
level *obj;
public:

array();
void accept();
void display();
void smallest();
void second();
~array()
{

 delete[]a;
}
};
void array::smallest()
{

 int i ,j ,k ,lsize;
 lsize=obj->ret_lsize();

 for(j=lsize-2;j>0;j--)
 {
	 for(i=obj->l[j-1].cw,k=obj->l[j].cw;k<obj->l[j+1].cw||i<obj->l[j].cw;k=k+2,i++)
		{
		   if(k+1<obj->l[j+1].cw)
		     {
		      if(a[k]>=a[k+1])
		      a[i]=a[k+1];
		      else
		      a[i]=a[k];
		     }
		   else
		   a[i]=a[k];


		}

   display();
 }

  if(a[1]>a[2])
  a[0]=a[2];
  else
  a[0]=a[1];

  display();


cout<<"\n\nThe Smallest No is : "<<a[0];
getch();
second();
}

void array::second()
{
  int i,j,lsize;
  lsize=obj->ret_lsize();
  s=a[0];
   cout<<endl;
   if(a[1]==a[0])
   {
   j=1;
   secs=a[2];
   }
   else
   {
   j=2;
   secs=a[1];
   }
  for(i=1;i<lsize;i++)
  {

  j=(j-obj->l[i-1].cw)*2+obj->l[i].cw;
     if(j+1<=(obj->l[i+1].cw -1))
     {
	if(a[j]==a[0])
	 {
     //		 cout<<"\nj :"<<j<<endl;
     //		getch();


		if(a[j+1]<secs)
		secs=a[j+1];

	 }

       else
       {
		j=j+1;
   //		cout<<"\nj :"<<j<<endl;
   //		getch();

		if (a[j-1]<secs)
		 secs=a[j-1];
	 }
     }
 //  cout<<secs<<endl;
 //  getch();
  }
cout<<"\n\n\nSecond Smallest No is : "<<secs;
getch();
}

void array::display()
{

 clrscr();
 int i,j;
 cout<<"-:ELEMENTS OF THE ARRAY:-\n\n\n";
 cout<<a[0]<<endl<<endl;
 int lsize=obj->ret_lsize();
//for(i=0;i<size;i++)
//cout<<a[i]<<" ";
 for(i=1;i<lsize;i++)
 {
   for(j=obj->l[i-1].cw;j<obj->l[i].cw;j++)
    cout<<a[j]<<" ";

  cout<<endl<<endl;
 }

 getch();
}
array::array()
{
 a=0;
 size=0;
 s=0;
 obj=0;
 secs=0;
}
void array::accept()
{
 clrscr();
 int i,j;
 float x;
 cout<<"Enter the size of the array : " ;
 cin>>x;
 obj=new level(x);
 while(x>1)
 {
  size=size+x;
  x=ceil(x/2);

 }
 size=size+x;
// clrscr();
// cout<<size;
// getch();
clrscr();
cout<<"Enter the Elements Of the Array : \n";
 int lsize=obj->ret_lsize();
 for(i=0;i<size;i++)
 {
  a[i]=0;
 }

 for(i=obj->l[lsize-2].cw; i<obj->l[lsize-1].cw;i++)
 {

 cin>>a[i];
 }
display();
smallest();

}
void main()
{
array obj;
obj.accept();

}

