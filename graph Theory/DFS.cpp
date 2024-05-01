#include<bits/stdc++.h>
using namespace std;

    int nodes;


    int edges;

int adj[100][100];
int color[100];
#define white 1
#define red 2
#define black 3
void dfsvisit(int x)
{
    color[x]=red;
    
    for(int i=0;i<nodes;i++)
    {
        if(adj[x][i]==1)
        {
            if(color[i]==white)
            {
                cout<<i<<"";
                dfsvisit(i);
            }
        }
       
    }
     color[x]=black;

}
void dfs()
{
    for(int i=0;i<nodes;i++)
    {
      color[i]=white;
    }
    for(int i=0;i<nodes;i++)
    {
        if(color[i]==white)
        {
            dfsvisit(i);
        }
    }
}
int main()
{

cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int e1,e2;
        cin>>e1>>e2;
        adj[e1][e2]=1;
        adj[e2][e1]=1;
    }
    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
      for(int i = 0; i < nodes; i++)
    {
        cout << i << "-->";
        for(int j = 0; j < nodes; j++)
        {
            if(adj[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
dfs();

}
/*
5 6
0 1
0 2
1 2
1 3
1 6
3 4


5 4
0 3
0 2
0 1
2 4

8 7
0 1
0 2
2 4
2 5
1 3
3 6
3 7
*/

