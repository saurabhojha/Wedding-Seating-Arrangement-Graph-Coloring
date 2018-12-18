#include<stdio.h>
#include<iostream>
#include<vector>
#include<windows.h>
#include<conio.h>
using namespace std;
int V;
void printSolution(int color[]);
void thank_you();
bool isSafe (int v, bool **graph, int color[], int c,int chairs[])
{
    for (int i = 0; i < V; i++)
        if((graph[v][i] && (c == color[i])) || chairs[c-1]<=0)
            return false;
    return true;
}
bool graphColoringUtil(bool **graph, int m, int color[], int v,int chairs[])
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {

        if (isSafe(v, graph, color, c,chairs))
        {
           color[v] = c;
           chairs[c-1]--;
           if (graphColoringUtil (graph, m, color, v+1,chairs) == true)
           {
             return true;
           }
           color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool **graph, int m,int chairs[])
{
    int *color = new int[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;


    if (graphColoringUtil(graph, m, color, 0,chairs) == false)
    {
      cout<<"Sorry we could not find a solution with given number of tables and chairs";
      return false;
    }

    printSolution(color);
    return true;
}
void printSolution(int color[])
{   char c;
    system("cls");
    system("color 0E");
    cout<<"Following are the assigned tables for your guests: \n";
    for (int i = 0; i < V; i++)
      cout<<"Guest "<<i+1<<" is assigned to the table:"<<color[i]<<"\n";
    printf("\n");
    int maximum=0;
    for(int i=0;i<V;i++)
    {
        if(maximum<color[i])
            maximum=color[i];
    }
    cout<<"Number of tables used for the seating arrangement :"<<maximum;
    cout<<"\nPress any key to continue :";
    getch();
    thank_you();
}
void thank_you()
{
    int c=0;
    system("cls");
    while(c<10){
         Sleep(100);
         cout<<"\n";
         cout<<"\n\n\n\n\n\n\n\n\n\n";
         system("color 0E");
         cout<<"\t\t\t %%%%%% %%  %%    %%%    %%%%   %%  %%  %%  %%    %% %%%%%%  %%  %%\n";Sleep(2100);
         system("color 0B");
         cout<<"\t\t\t   %%   %%  %%   %% %%   %% %%  %%  %% %%    %%  %%  %%  %%  %%  %%\n";Sleep(2100);
         system("color 0C");
         cout<<"\t\t\t   %%   %%%%%%  %%   %%  %%  %% %%  %%%        %%    %%  %%  %%  %%\n";Sleep(2100);
         system("color 0F");
         cout<<"\t\t\t   %%   %%  %%  %%%%%%%  %%  %% %%  %% %%      %%    %%  %%  %%  %%\n";Sleep(2100);
         system("color 0D");
         cout<<"\t\t\t   %%   %%  %%  %%   %%  %%   %%%%  %%  %%     %%    %%%%%%  %%%%%%\n";Sleep(2100);
         system("cls");
         c++;
    }
}
void welcome()
{ cout<<"\n\n\n\n\n\n\n";
  system("color 0E");
  cout<<"\t %%   %% %%%%%% %%%%   %%%%  %%%%%% %%   %% %%%%%   %%%%  %%      %%%    %%   %% %%   %% %%%%% %%%%% \n";Sleep(2100);system("color 0A");
  cout<<"\t %%   %% %%     %% %%  %% %%   %%   %%%  %% %%      %%  % %%     %%  %%  %%%  %% %%%  %% %%    %%  %% \n";Sleep(2100);system("color 0D");
  cout<<"\t %% % %% %%%%%  %%  %% %%  %%  %%   %% % %% %% %%   %%%%  %%    %%    %% %% % %% %% % %% %%%%  %%%%  \n";Sleep(2100);system("color 0F");
  cout<<"\t %%% %%% %%     %% %%  %% %%   %%   %%  %%% %%  %   %%    %%    %%%%%%%% %%  %%% %%  %%% %%    %% %%   \n";Sleep(2100);system("color 0C");
  cout<<"\t %%  %%% %%%%%% %%%%   %%%%  %%%%%% %%   %% %%%%%   %%    %%%%% %%    %% %%   %% %%   %% %%%%% %%  %%   \n";Sleep(2100);system("color 0B");
  cout<<"\n\n\t\t\t\t\tTHE WEDDING SEATING PLANNER\n";Sleep(3000);
  cout<<"\n";
}
bool** takeEdgeInput(int v)
{   system("cls");
    system("color 0B");
	int i=0,j=0;
	bool **edge = (bool **)malloc(v * sizeof(bool *));
	printf("Enter 1 if the present guest and the corresponding guest don't prefer to sit together.\n");
	printf("Enter 0 if present guest has no problem sitting on the same table as corresponding guest.\n");
	for(i=0;i<v;i++)
	{
		edge[i] = (bool *)malloc(v * sizeof(bool));
		printf("For Guest %d \n",i+1);
		for(j=0;j<v;j++)
		{   if(i==j)
                edge[i][j]=0;
            else
			{printf("Enter 1 or 0 for guest %d :: ",j+1);
			 cin>>edge[i][j];
            }
        }
        cout<<"\n";
	}
	int reenter;
	for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(edge[i][j]!=edge[j][i])
            {   if(edge[i][j]==1)
                {
                  printf("The guest %d does not prefer to sit with guest %d \n",i+1,j+1);
                  printf("Please re enter if guest %d prefers to sit with guest %d (0) or not (1):",i+1,j+1);
                  cin>>reenter;
                }
                else
                {
                 printf("The guest %d does not prefer to sit with guest %d \n",j+1,i+1);
                 printf("Please re enter if guest %d prefers to sit with guest %d (0) or not (1):",j+1,i+1);
                 cin>>reenter;
                }
                edge[i][j]=reenter;
                edge[j][i]=reenter;
        }
    }
    }
	return edge;
}
int main()
{
    int v,m,choice;
    welcome();
    system("cls");
    system("color 0D");
    cout<<"1.Plan new wedding seating arrangements:\n";
    cout<<"2.Exit\n";
    cout<<"3.Enter your choice:";
    cin>>choice;
    system("cls");
    system("color 0A");
    if(choice==1)
    {   int m,chair,i,j;
        bool temp;
        cout<<"Enter the no of guests in your wedding:\n";
        cin>>V;
        if(V<=0)
        {
            cout<<"\nYou cannot have zero and less guests in your wedding!! Please re-enter the choice::";
            int z;
            cin>>z;
            while(z<=0)
            {
                cout<<"\nYou cannot have zero and less guests in your wedding!! Please re-enter the choice::";
                cin>>z;
            }
            V=z;
        }
        cout<<"Enter the maximum number of tables for your wedding:\n";
        cin>>m;
        if(m<=0)
        {
            cout<<"\nYou cannot have zero and less tables in your wedding!! Please re-enter the choice::";
            int z;
            cin>>z;
            while(z<=0)
            {
                cout<<"\nYou cannot have zero and less tables in your wedding!! Please re-enter the choice::";
                cin>>z;
            }
            m=z;
        }
        cout<<"Enter the no of chairs per table:\n";
        cin>>chair;
        if(chair<=0)
        {
            cout<<"\nYou cannot have zero and less tables in your wedding!! Please re-enter the choice::";
            int z;
            cin>>z;
            while(z<=0)
            {
                cout<<"\nYou cannot have zero and less tables in your wedding!! Please re-enter the choice::";
                cin>>z;
            }
            chair=z;
        }
        int chairs[1000];
        for(int i=0;i<m;i++)
        {
            chairs[i]=chair;
        }
		cout<<"\n";
        bool **graph = takeEdgeInput(V);
        graphColoring(graph,m,chairs);
    }
    return 0;
}
