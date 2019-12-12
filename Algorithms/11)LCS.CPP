#include<iostream.h>
#include<conio.h>



class sequence
{
  int m,n;
  char *a1,*a2;

public:
  void lcs();
  void print_lcs(char** b,char X[],int,int);
  void accept();
  void display();
   sequence()
   {
    a1=a2=0;
    m=n=0;
   }
  ~sequence()
  {
   delete[]a1;
   delete[]a2;
  }
};
void sequence::print_lcs(char **b,char X[],int i,int j)
{
  if(i==0||j==0)
   return;
   if(b[i][j]=='D')
   {
    print_lcs(b,X,i-1,j-1);
    cout<<X[i-1]<<" ";
   }
   else if(b[i][j]=='U')
   {
   print_lcs(b,X,i-1,j);
   }
   else if(b[i][j]=='L')
   print_lcs(b,X,i,j-1);
}
void sequence::lcs()
{
 int i,j;
 char **b;
 int **c;

 b=new char*[m+1];
 for(i=0;i<=m;i++)
 b[i]=new char[n+1];

 c=new int*[m+1];
 for(i=0;i<=m;i++)
 c[i]=new int[n+1];

 for(i=0;i<=m;i++)
 {
 c[i][0]=0;
 b[i][0]='0';
 }
 for(i=0;i<=n;i++)
 {
  c[0][i]=0;
  b[0][i]='0';

 }
 for(i=1;i<=m;i++)
 {

    for(j=1;j<=n;j++)
    {
     if(a1[i-1]==a2[j-1])
     {
      c[i][j]=c[i-1][j-1]+1;
      b[i][j]='D';
     }
      else if(c[i-1][j]>=c[i][j-1])
      {
      c[i][j]=c[i-1][j];
      b[i][j]='U';

      }
      else
      {
	c[i][j]=c[i][j-1];
       b[i][j]='L';

      }

     }

    }

 clrscr();
 cout<<"\n\nTABLE :\n\n";
 for(i=0;i<=m;i++)
 {
 for(j=0;j<=n;j++)
 cout<<c[i][j]<<"("<<b[i][j]<<")"<<" ";
 cout<<endl;
 }
 getch();


 cout<<"\n\n\nLargest Common Subsequence : ";





 print_lcs(b,a1,m,n);
 getch();

}

void sequence :: display()
{
 clrscr();
 int i;
 cout<<"SEQUENCE 1 : ";
 for( i=0;i<m-1;i++)
 cout<<a1[i]<<",";
 cout<<a1[i];

 cout<<"\n\nSEQUENCE 2 : ";
 for(i=0;i<n-1;i++)
 cout<<a2[i]<<",";
 cout<<a2[i];
 getch();
lcs();
}
void sequence:: accept()
{
 clrscr();
 int i;

 cout<<"Enter the Size Of the First Sequence : ";
 cin>>m;

 cout<<endl<<endl;

 cout<<"Enter the  First Sequence :  ";

  a1=new char[m+1];

 for (i=0;i<m-1;i++)
 {a1[i]=getche();cout<<",";}
  a1[i]=getche();
  a1[i+1]='\0';
 cout<<"\n\n\n\nEnter the Size Of the Second Sequence : ";
 cin>>n;

 cout<<endl<<endl;

  a2=new char[n+1];
 cout<<"Enter the  Second Sequence :  ";
 for (i=0;i<n-1;i++)
 {a2[i]=getche();cout<<",";}
  a2[i]=getche();
  a2[i+1]='\0';

  getch();
}

void main()
{
  sequence obj;
   obj.accept();
   obj.display();
}