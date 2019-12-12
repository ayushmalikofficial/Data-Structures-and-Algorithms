#include<iostream.h>
#include<conio.h>
#include<process.h>

class node
{

 int info;
 node *left,*right,*parent;
 char color;
 node();
 node(int);
 friend class rbt;

};

node::node()
 {

   info=0;
   left=right=parent=0;
   color='b';

}

node::node(int x)
 {

   info=x;
   color='r';
   left=right=parent=0;
 }

class rbt
{
  node *root;
  node *sentinal;
  public:
  rbt();
  node* search(int x);
  void insert(int x);
  void leftrotate(node*);
  void rightrotate(node*);
  void preorder();
  void preorder(node*);
  void postorder();
  void postorder(node*);
  void inorder();
  void inorder(node*);
  void visit(node*);
  void fixup(node*);
  node *ret()
  {
   return sentinal;
  }
 void del(node*);
 void del_fixup(node*);
};
rbt::rbt()
{
  sentinal=new node();
  sentinal->left=sentinal->right=sentinal->parent=0;
  root=sentinal;
  }

void rbt::del(node *z)
{
 node*y,*x;

 if(z->left==sentinal||z->right==sentinal)
   y=z;
 else
  {
      for (node*temp=z->right;temp->left!=sentinal;temp=temp->left);

	y=temp;

  }

 if(y->left!=sentinal)
   x=y->left;
 else
  x=y->right;

  x->parent=y->parent;

  if(y->parent==sentinal)
    root=x;

  else if(y==y->parent->left)
     y->parent->left=x;

  else
    y->parent->right=x;

   if(y!=z)
    z->info=y->info;

   if(y->color=='b')
	del_fixup(x);
   delete y;

}
void rbt::del_fixup(node *x)
{
 node*w;
  while( x!=root&&x->color=='b')
  {

       if(x==x->parent->left)
	{
		  w=x->parent->right;

		 if(w->color=='r')
		  {
			w->color='b';
			x->parent->color='r';
			leftrotate(x->parent);
			w=x->parent->right;
		  }

		if(w->left->color=='b'&&w->right->color=='b')
		  {
			w->color='r';
			x=x->parent;

		   }
		else
		{

			if(w->right->color=='b')
			  {

			    w->left->color='b';
			    w->color='r';
			    rightrotate(w);
			    w=x->parent->right;

			   }

			w->color=x->parent->parent->color;
			x->parent->color='b';
			 w->right->color='b';
			leftrotate(x->parent);
			 x=root;
		}
       }
       else
       {
		  w=x->parent->left;

		 if(w->color=='r')
		  {
			 w->color='b';
			 x->parent->color='r';
			rightrotate(x->parent);

		     w=x->parent->left;
		   }

		 if(w->left->color=='b'&&w->right->color=='b')
		{
			 w->color='r';
			x=x->parent;

		}
		else
		{

			 if(w->left->color=='b')
			  {

			 w->right->color='b';
			 w->color='r';
			   leftrotate(w);
			w=x->parent->left;

			    }

		 w->color=x->parent->parent->color;
		 x->parent->color='b';
		 w->left->color='b';
		  rightrotate(x->parent);
		x=root;
	    }


	  }



  }


  x->color='b';
}
void rbt::fixup(node* z)
{
     while(z->parent->color=='r')
     {

       if(z->parent==z->parent->parent->left)
       {
	node*y= z->parent->parent->right;

	if(y->color=='r')
	 {
	  z->parent->color='b';
	 y->color='b';
	 z->parent->parent->color='r';
	 z=z->parent->parent;
	 }
	 else
	 {
	  if(z==z->parent->right)
	  {

	  z=z->parent;
	  leftrotate(z);

	  }
	    z->parent->color='b';
	    z->parent->parent->color='r';
	    rightrotate(z->parent->parent);

	  }

	  }
	  else
	  {
	   node*y= z->parent->parent->left;

	if(y->color=='r')
	 {
	  z->parent->color='b';
	 y->color='b';
	 z->parent->parent->color='r';
	 z=z->parent->parent;
	 }
	 else
	 {
	  if(z==z->parent->left)
	  {

	  z=z->parent;
	  rightrotate(z);

	  }
	    z->parent->color='b';
	    z->parent->parent->color='r';
	    leftrotate(z->parent->parent);

	  }



	  }
   }

 root->color='b';
}
void rbt::insert(int x)
{

 node *p=root,*prev=sentinal;
 node*z;
 while(p!=sentinal)
 {
  prev=p;
  if(p->info<x)
  p=p->right;
  else
  p=p->left;


 }
 if(root==sentinal)
 {
  root=new node(x);
  z=root;

    }
 else if(prev->info<x)
 {
 prev->right=new node(x);
  z=prev->right;
  }
 else
 {
 prev->left=new node(x);
 z=prev->left;
 }
 z->left=z->right=sentinal;
 z->parent=prev;

fixup(z);

}
void rbt:: preorder()
{
  node*p=root;
 preorder(p);

}

void rbt::preorder(node*p)
{
   if(p!=sentinal)
   {
    visit(p);
    preorder(p->left);
    preorder(p->right);
   }

}

void rbt::visit(node*p)
{

    cout<<"  "<<p->info<<"("<<p->color<<")";
}

void rbt::postorder()
{

  node*p=root;

  postorder(p);

}


void rbt::postorder(node*p)
{
   if(p!=sentinal)
   {
     postorder(p->left);
     postorder(p->right);
    visit(p);
   }
}

void rbt::inorder()
{
  node*p=root;
  inorder(p);


}

void rbt::inorder(node*p)
{

     if(p!=sentinal)
     {
      inorder(p->left);
      visit(p);
      inorder(p->right);
     }

}

void rbt::leftrotate(node* x)
{

 node *y=x->right;
 x->right=y->left;

 if(y->left!=sentinal)
  y->left->parent=x;

 y->parent=x->parent;

 if(x->parent==sentinal)
   root=y;

 else if(x==x->parent->left)
 x->parent->left=y;

 else
  x->parent->right=y;

  y->left=x;
  x->parent=y;

}
node* rbt::search(int x)
{
  node*p=root;

while(p!=sentinal)
   {
    if(x==p->info)
     return p;

    else if(x<p->info)
     p=p->left;

    else
     p=p->right;

   }
 return p;

}

void rbt::rightrotate(node* x)
{

 node *y=x->left;
 x->left=y->right;

 if(y->right!=sentinal)
  y->right->parent=x;

 y->parent=x->parent;

 if(x->parent==sentinal)
   root=y;

 else if(x==x->parent->right)
 x->parent->right=y;

 else
  x->parent->left=y;

  y->right=x;
  x->parent=y;

}


void main()
{
 clrscr();

 rbt t1;
 t1.insert(26);
 t1.insert(17);
 t1.insert(14);
 t1.insert(24);
 t1.insert(16);
 t1.insert(20);
 t1.insert(25);
 t1.insert(18);
 t1.insert(22);
 cout<<"\n\nPreorder : ";

 t1.preorder();
 getch();
 cout<<"\n\nPostorder : ";
 t1.postorder();
 getch();
 cout<<"\n\nInorder : ";

 t1.inorder();
 getch();
 clrscr();

 node* x=t1.search(17);
 if(x!=t1.ret())
 {
  t1.del(x);
 cout<<"element deleted\n\n";
  cout<<"\n\nPreorder : ";

 t1.preorder();
 getch();
 cout<<"\n\nPostorder : ";
 t1.postorder();
 getch();
 cout<<"\n\nInorder : ";

 t1.inorder();
 getch();

 }
 else
 {
  cout<<"element not found \n\n";

   cout<<"\n\nPreorder : ";

  t1.preorder();
 getch();
 cout<<"\n\nPostorder : ";
 t1.postorder();
 getch();
 cout<<"\n\nInorder : ";

 t1.inorder();
 getch();

 }
}
