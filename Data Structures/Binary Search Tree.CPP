#include<iostream.h>
#include<conio.h>
#include<process.h>

class node;

class nodeq
{
   node*p;
  nodeq *next;
public:

friend class queue;
friend class stack;
   nodeq(node*x,nodeq*n=0)
   {
    p=x;
    next=n;
   }
};

class stack
{
  nodeq*top;
  public:
   void push(node*);
   node* pop();
   int isempty();
   stack()
   {
    top=0;
   }
} ;


 void stack::push(node*ptr)
 {
  if(top==0)
    top=new nodeq(ptr,0);
  else
   top=new nodeq(ptr,top);

 }

 int stack::isempty()
 {
    if(top==0)
    return 1;
    return 0;
 }
 node* stack::pop()
 {
  if(top==0)
    return 0;
    else
    {
     node*temp=top->p;
     top=top->next;
     return temp;
    }
 }

class queue
{
    nodeq *front,*rear;

    public:

    void enqueue(node*);
    node* dequeue();
    int isempty();
    queue()
    {

     front=rear=0;
    }
};



int queue::isempty()
{
 if(front==0)
 return 1;
 return 0;
}
void queue::enqueue(node*x)
{
   if(front==0)
   {

    front=rear=new nodeq(x);
   }
   else
   {
    rear->next=new nodeq(x);
     rear=rear->next;
   }

}
node* queue::dequeue()
{
  if (front==0)
    return 0;
   else
    {   node*temp=front->p;
	if(front==rear)
	  {
	   front=rear=0;
	  }
	 else
	 {
	  front=front->next;

	 }
     return temp;
    }
}




class bst
{


   node *root;


public:

void mirror(node*);
void insert(int);
int search(int);
void assign(node*);
void preorder();
void preorder(node*);
void ipreorder();
node* copy(node*);
void postorder();
void postorder(node*);
void ipostorder();

int height(node*);
void inorder();
void inorder(node*);
void iinorder();

void countnoofnodes(node*,int&);
void countnoofleaves(node*,int&);
void countnoofnonleaves(node*,int&);
void findanddelete(int,int);
void deletebymerge(node*&);
void deletebycopy(node*&);
void breadthwise();

void visit(node*);

void accept();

node* retroot()
{

 return root;
}

bst()
{
root=0;
}

};


class node
{

 int info;

 node*right;
 node*left;

  public:
  friend class bst;
   node(int x ,node*l=0,node*r=0)
   {
     info=x;
     left=l;
     right=r;
   }
};
void mainmenu2(bst &);






void bst::ipreorder()
{
  node*p=root;
  stack s;
  if(p)
  {
   s.push(p);
   while(!s.isempty())
   {
    p=s.pop();
    visit(p);
    if(p->right)
    s.push(p->right);
    if(p->left)
    s.push(p->left);
    }

    }
  }


void bst::ipostorder()
{

 stack s;
 node*p=root,*q=root;
 while(p)
 {


 for(;p->left!=0;p=p->left)
 s.push(p);

  while(p!=0 && (p->right==0||p->right==q))
  {

   visit(p);
   q=p;

     if(s.isempty())
      return;



      p=s.pop();

      }
     s.push(p);
     p=p->right;


     }



}


void bst::iinorder()
{

  stack s;
  node*p=root;
  while(p!=0)
  {

  while(p!=0)
  {
   if(p->right)
   s.push(p->right);
   s.push(p);
   p=p->left;
   }

  p=s.pop();
  while(!s.isempty()&&p->right==0)
  {
   visit(p);
   p=s.pop();
   }
   visit(p);

   if(!s.isempty())
   p=s.pop();
   else
   p=0;
   }
   }









void bst:: accept()
{
  clrscr();
  root=0;
  cout<<"Enter the initial no of elements to be entered :";
  int x,y;
  cin>>x;
  for(int i=0;i<x;i++)
 {
  cout<<"Enter the element : ";
  cin>>y;
  insert(y);
 }
}
void bst::countnoofnodes(node*ptr,int&x)
{
 if(ptr)
 {
  countnoofnodes(ptr->left,x);
  countnoofnodes(ptr->right,x);
  x++;
 }
}
void bst::countnoofleaves(node*ptr,int&x)
{
  if(ptr)
 {
  countnoofleaves(ptr->left,x);
  countnoofleaves(ptr->right,x);
  if(ptr->left==0&&ptr->right==0)
  {
  x++;
  }
 }
}
void bst::countnoofnonleaves(node*ptr,int&x)
{
  if(ptr)
 {
  countnoofnonleaves(ptr->left,x);
  countnoofnonleaves(ptr->right,x);

  if(ptr->left!=0||ptr->right!=0)
  {
  x++;
  }

 }
}

node* bst::copy(node*ptr)
{
 if(ptr)
 {
  node*temp=new node(ptr->info);
  temp->left=copy(ptr->left);
  temp->right=copy(ptr->right);
  return temp;

 }
 else
 return 0;

}

void bst::insert(int x)
{

 node *p=root,*prev=0;
 while(p!=0)
 {
  prev=p;
  if(p->info<x)
  p=p->right;
  else
  p=p->left;


 }
 if(root==0)
 root=new node(x);
 else if(prev->info<x)
 prev->right=new node(x);
 else
 prev->left=new node(x);


}

int bst::height(node*ptr)
{
  if(ptr)
  {

    int a=height(ptr->left);
    int b=height(ptr->right);
    return (a>b?a+1:b+1);
  }
  else
  return 0;
}
int bst::search (int x)
{
  node*p=root;
   while(p!=0)
   {
    if(x==p->info)
     return 1;

    else if(x<p->info)
     p=p->left;

    else
     p=p->right;

   }
  return 0;

}



void bst::findanddelete(int x,int y)
{

    node*ptr=root,*prev=0;

    while(ptr!=0)
    {

      if(ptr->info==x)
	      break;

      prev=ptr;

      if(ptr->info<x)
      ptr=ptr->right;
      else
      ptr=ptr->left;

     }

    if(ptr&&ptr->info==x)
      {
	 if(y==0)
	 {
	  if(ptr==root)
	  deletebymerge(root);
	  else if(prev->left==ptr)
	  deletebymerge(prev->left);
	  else
	  deletebymerge(prev->right);
	 }
	 else if(y==1)
	 {

	 if(ptr==root)
	  deletebycopy(root);
	  else if(prev->left==ptr)
	  deletebycopy(prev->left);
	  else
	  deletebycopy(prev->right);
	 }


      }
    else if(root)
    {
     clrscr();
     cout<<"Element Not Found";

    }
    else
      {
     clrscr();
     cout<<"Empty";


      }
}


void bst:: deletebymerge(node*&ptr)
{

   node*temp=ptr;
   if(ptr)
   {
      if(!ptr->right)
      ptr=ptr->left;
      else if(ptr->left==0)
      ptr=ptr->right;
      else
      {
	 temp=ptr->left;
	 while(temp->right)
	 temp=temp->right;

	 temp->right=ptr->right;
	 temp=ptr;
	 ptr=ptr->left;

      }
     delete temp;
   }
}

void bst:: deletebycopy(node*&ptr)
{
    node*prev,*temp=ptr;
    if(ptr->right==0)
    ptr=ptr->left;
    else if(ptr->left==0)
    ptr=ptr->right;
    else
    {
     temp=ptr->left;
     prev=ptr;
     while(temp->right)
     {

      prev=temp;
      temp=temp->right;
     }

    ptr->info=temp->info;
    if(prev==ptr)
    prev->left=temp->left;
    else
    prev->right=temp->left;
    }
    delete temp;



}

void bst:: preorder()
{
  node*p=root;
 preorder(p);

}

void bst::preorder(node*p)
{
   if(p)
   {
    visit(p);
    preorder(p->left);
    preorder(p->right);
   }

}

void bst::visit(node*p)
{

    cout<<"  "<<p->info;
}

void bst::postorder()
{

  node*p=root;

  postorder(p);

}


void bst::postorder(node*p)
{
   if(p)
   {
     postorder(p->left);
     postorder(p->right);
    visit(p);
   }
}

void bst::inorder()
{
  node*p=root;
  inorder(p);


}

void bst::inorder(node*p)
{

     if(p)
     {
      inorder(p->left);
      visit(p);
      inorder(p->right);
     }

}

void bst::mirror(node*ptr)
{
 if(ptr)
 {
  node*temp=ptr->left;
  ptr->left=ptr->right;
  ptr->right=temp;
  mirror(ptr->left);
  mirror(ptr->right);

 }

}
void bst::breadthwise()
{
    queue q;
    node*p=root;
    if(p!=0)
    {
      q.enqueue(p);
      while(!q.isempty())
      {
       p=q.dequeue();
       visit(p);
       if(p->left)
       q.enqueue(p->left);
       if(p->right)
       q.enqueue(p->right);

       }

    }

}

void bst::assign(node*temp)
{

    root=temp;
}
void mainmenu(bst &t)
{


  clrscr();
	      bst t2;
	       int x,a=0;
	       node *r=t.retroot();
    char ch;
   cout<<"\n\t\t     B.I.N.A.R.Y.-S.E.A.R.C.H. T.R.E.E.\n";
   cout<<"\n\t\tA.Insert an Element";
   cout<<"\n\t\tB.Delete By Merge";
   cout<<"\n\t\tC.Delete By Copy";
   cout<<"\n\t\tD.Search an Element";
   cout<<"\n\t\tE.Preorder Traversal";
   cout<<"\n\t\tF.Post Order Traversal";
   cout<<"\n\t\tG.Inorder Traversal";
   cout<<"\n\t\tH.Breadth wise Traversal";
   cout<<"\n\t\tI.Create a New Tree";
   cout<<"\n\t\tJ.Show the Mirror";
   cout<<"\n\t\tK.Count The Total No. of Nodes";
   cout<<"\n\t\tL.Count The No. of Leaves";
   cout<<"\n\t\tM.Count The No. of Non Leaves";
   cout<<"\n\t\tN.Create The Copy Of the Tree";
   cout<<"\n\t\t0.Display The Height of The Tree";
   cout<<"\n\t\tP.Iterative Menu";


   cout<<"\n\t\tQ.Exit";
   cout<<"\n\t\tEnter Your Choice : ";
   cin>>ch;
   switch(ch)
   {
    case 'a': case'A':
	       clrscr();
	       cout<<"Enter the Element to be inserted :";
	       cin>>x;
	       t.insert(x);
	       break;

    case 'b': case'B':
	       clrscr();
	       cout<<"Enter the Element to be deleted :";
	       cin>>x;
	       t.findanddelete(x,0);
	       getch();
	       break;

    case 'c': case'C':
	       clrscr();
	       cout<<"Enter the Element to be deleted :";
	       cin>>x;
	       t.findanddelete(x,1);
	       getch();

	       break;

    case 'd': case'D':
	       clrscr();
	       cout<<"Enter the Element to be searched :";
	       cin>>x;
	       if(t.search(x))
		cout<<"\nElement Found ";

	       else
	       cout<<"\nElement Not Found";

	       getch();

	       break;

    case 'e': case'E':
	       clrscr();
	       t.preorder();
	       getch();
	       break;

    case 'f': case'F':
	       clrscr();
	       t.postorder();
	       getch();
	       break;

    case 'g': case'G':
	       clrscr();
	       t.inorder();
	       getch();
	       break;

    case 'h': case'H':
	       clrscr();
	       t.breadthwise();
	       getch();
	       break;

    case 'i': case'I':
	       t.accept();
	       break;

    case 'j':case 'J':
		   t.mirror(r);
		   clrscr();
		   t.breadthwise();
		   getch();
		   t.mirror(r);
		break;
    case 'k':case 'K':

		   t.countnoofnodes(r,a);
		   clrscr();
		   cout<<"Total no. of nodes : "<<a;
		   getch();
			break;
    case 'l':case 'L':

		   t.countnoofleaves(r,a);
		   clrscr();
		   cout<<"Total no. of leaves : "<<a;
		   getch();
		break;
    case 'm':case 'M':

		   t.countnoofnonleaves(r,a);
		   clrscr();
		   cout<<"Total no. of non leaves : "<<a;
		   getch();
		break;
    case 'n':case 'N':

		   r=t.copy(r);
		   t2.assign(r);
		   clrscr();
		   t2.breadthwise();
		   getch();
		break;
    case 'o':case 'O':
		   a=t.height(r);
		   clrscr();
		   cout<<"Height Of the tree : "<<a;
		   getch();
		break;

    case  'p': case 'P':
	       mainmenu2(t);
	       break;

    case 'q': case'Q':
      exit(0);
	       break;

   default : cout<<"\n\t\tInvalid Choice Kindly Re-Enter";

   }

   mainmenu(t);



}

void mainmenu2(bst &t)
{


  clrscr();
	      bst t2;
   char ch;
   cout<<"\n\t\t     I.T.E.R.A.T.I.V.E  M.E.N.U\n";
   cout<<"\n\t\tA.Inorder Traversal";
   cout<<"\n\t\tB.Postorder Traversal";
   cout<<"\n\t\tC.Preorder Traversal";
   cout<<"\n\t\tD.Return To Previous Menu";
   cout<<"\n\t\t0.Exit";
   cout<<"\n\t\tEnter Your Choice : ";
   cin>>ch;
   switch(ch)
   {
    case 'a': case'A':
	       clrscr();
	       t.iinorder();
	       getch();
	       break;

    case 'b': case'B':
	       clrscr();
	       t.ipostorder();
	       getch();
	       break;

    case 'c': case'C':
	       clrscr();
	       t.ipreorder();
	       getch();

	       break;

    case 'd': case'D':
	       clrscr();
	       mainmenu(t);
	       getch();

	       break;



    case 'o': case'O':
      exit(0);
	       break;

   default : cout<<"\n\t\tInvalid Choice Kindly Re-Enter";

   }

   mainmenu2(t);



}










void main()
{


bst t;
t.accept();
mainmenu(t);






}