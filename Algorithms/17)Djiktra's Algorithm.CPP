#include<conio.h>
#include<iostream.h>


void main()
{
  clrscr();

 int n,i,j;
 int *color,*parent,*distance;
 int **graph;

 cout<<"Enter the No of vertices : ";
 cin>>n;

 color=new int[n];
 parent=new int[n];
 distance=new int[n];

 int sou,des;


   graph=new int*[n];

   for( i=0;i<n;i++)
     graph[i]=new int[n];

   for(i=0;i<n;i++)
   {
    color[i]=0;
    parent[i]=-1;
    distance[i]=99;

   }

  cout<<"\nEnter the Graph Matrix : \n";

  for( i=0;i<n;i++)
  {
   cout<<"\nVertex "<<i<<":";
	for( j=0;j<n;j++)
	 {
	  int x =getche();

	  graph[i][j]=x-48;
	  cout<<" ";
	 }

    cout<<endl;
  }
  clrscr();
  cout<<"\nGraph Matrix \n\n";
  for(i=0;i<n;i++)
  {
   cout<<"\nVertex"<<i<<":";
   for(j=0;j<n;j++)
   {
   cout<<graph[i][j]<<" ";
   }

    cout<<endl;
  }
  getch();
  clrscr();

  clrscr();
  cout<<"\nEnter Source vertex no : ";
  cin>>sou;
  cout<<"\nEnter Destination vertex no :";
  cin>>des;

  getch();
  clrscr();
  color[sou]=1;
  parent[sou]=sou;
  distance[sou]=0;

    int minvalue,minindex,minparent;

  while(color[des]==0)
  {

	minvalue=99;
	minindex=n+1;
	minparent=n+1;

     for(i=0;i<n;i++)
		{

		   if(color[i]==1)
			{

				for(j=0;j<n;j++)
				     {

					if((!color[j])&& graph[i][j]!=0 && (graph[i][j]+distance[i]<minvalue))
					{
					minvalue=graph[i][j]+distance[i];
					minindex=j;
					minparent=i;

					}


				      }

			}


	      }
	color[minindex]=1;
	parent[minindex]=minparent;
	distance[minindex]=minvalue;//+distance[minparent];



      clrscr();
     cout<<"\n\n\nColor Array : \n\n";
   for(i=0;i<n;i++)
   {
    cout<<color[i]<<"("<<i<<") ";

   }

  cout<<"\n\n\nDistance Array : \n\n";
   for(i=0;i<n;i++)
   {
    cout<<distance[i]<<"("<<i<<") ";

   }

  cout<<"\n\n\nParent Array : \n\n";
   for(i=0;i<n;i++)
   {
    cout<<parent[i]<<"("<<i<<") ";

   }
   getch();



 }


int temp=des;
clrscr();
while(temp!=sou)
{
 cout<<temp<<"<-";
 temp=parent[temp];

}

cout<<sou;
 getch();

}