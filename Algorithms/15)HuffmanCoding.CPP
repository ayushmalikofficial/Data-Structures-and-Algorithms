#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<iomanip.h>

class tnode
{

  tnode *left,*right;
  char ch;
  public:

  friend class anode;
  friend class array;
 tnode(char z)
 {
   ch=z;
  left=right=0;
 }
 tnode()
 {
   ch='0';
  left=right=0;

 }
void d_p(tnode*,unsigned long int ,int );

void visit(tnode* z,unsigned long int p,int x)
{

  cout<<z->ch<<"  : "<<setfill('0')<<setw(x)<<p<<endl;

}
};
void tnode::d_p(tnode*p,unsigned long int pattern,int x=0)
{

if(p)
{

d_p(p->left,pattern*10+0,x+1);
d_p(p->right,pattern*10+1,x+1);

if(p->ch!='0')
visit(p,pattern,x);
}


}
class anode
{

 char value;
 int f;
 tnode *p;
  public:

  anode()
  {

   value='0';
   p=0;
   f=0;
   }

  anode(char a,tnode *p=0)
  {
    value=a;

  }
  friend class tnode;
  friend class array;
};

class array
{
   anode *a;
   int size;
   int heapsize;

 public :
 void accept();
 void display();
 void buildminheap();
 void minheapify(int);
 tnode* extractmin(int&);
 void insert(tnode*,int);
 array();
 array(int);
 ~array()
 {

  delete []a;
 }
 void huffman();
};
void array::huffman()
{
 tnode*z;
 int x,y;
 buildminheap();
while(1)
{
 z=new tnode();
 z->left=extractmin(x);
 cout<<"z->left : "<<z->left->ch;
 getch();
 z->right=extractmin(y);
 cout<<"  z->right : "<<z->right->ch;
  getch();
// cout<<z->ch;
// getch();
  display();
  if(heapsize==0)
  {
  clrscr();
cout<<"-: HUFFMAN CODES :- \n";

  z->d_p(z,0);
  getch();

  break;
  }
  insert(z,x+y);
// clrscr();
// cout<<z->ch<<x+y;
// getch();
 display();
}
clrscr();
//cout<<z->ch<<" "<<z<<"z->left "<<z->left->ch<<" z->right "<<z->right->ch;

//getch();
//z->d_p(z,0);
}
void array::display()
{
   clrscr();
   cout<<"Elements of the Array : \n";
   for(int i=0;i<heapsize;i++)
   {
   cout<<a[i].value<<" "<<a[i].f;
   cout<<endl;
   }

   getch();

}

void array::buildminheap()
{

 heapsize=size;

 for(int i=heapsize-1;i>=0;i--)
 {
 minheapify(i);

 }

}
tnode* array::extractmin(int&x)
{
   anode temp;
   temp=a[0];
   heapsize--;
   a[0]=a[heapsize];
   minheapify(0);
   x=temp.f;
  if(temp.p!=0)
  return temp.p;
  else
  {
    temp.p=new tnode(temp.value);
    return temp.p;
  }

}
void array::accept()
{
   clrscr();

   cout<<"Enter the No of Characters : ";
   cin>>size;
   heapsize=size;
   a=new anode[size];
   cout<<endl<<"Enter The Characters :\n\n";
   for(int i=0;i<size;i++)
   {
   cout<<i+1<<" Character : ";
   a[i].value=getche();
   cout<<" Frequency : ";
   cin>>a[i].f;
   }



   getch();

}

void array::minheapify(int i)
{
  int r,l;
  l=2*i+1;
  r=2*i+2;
  int smallest;

 if(l<heapsize &&  a[l].f<a[i].f)
    {
	 smallest=l;
    }
 else
     smallest=i;


  if(r<heapsize && a[r].f<a[smallest].f)
    {

    smallest =r;

    }
  if(smallest!=i)
  {

   anode temp=a[i];
   a[i]=a[smallest];
   a[smallest]=temp;
   minheapify(smallest);
  }




}

array::array()
{
 heapsize=size=0;
 a=0;

}

void array::insert(tnode* z,int x)
{
 int i,p;
 i=heapsize;
  if(i!=1)
  p=ceil((i/2)-1);
  else
  p=0;
 heapsize++;
 anode temp;
 a[i].value=z->ch;
 a[i].f=x;
 a[i].p=z;
/*cout<<a[i].value<<a[i].f;
getch();
cout<<"\n"<<a[p].value<<a[p].f;
getch();
cout<<i<<p<<endl;
getch();
*/
while(i>0 && a[p].f>a[i].f)
 {
     temp=a[i];
     a[i]=a[p];
     a[p]=temp;
     i=p;
     p=ceil((i/2)-1);

 }


}
 void main()
 {
  array obj;

  obj.accept();
  obj.display();
  obj.buildminheap();
  obj.display();
  obj.huffman();

 }