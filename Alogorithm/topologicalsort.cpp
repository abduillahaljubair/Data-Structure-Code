#include<bits/stdc++.h>
using namespace std;

    int nodes;


    int edges;

int adj[100][100];
int color[100];
#define white 1
#define red 2
#define black 3
stack<int>ans;
struct node 
{
    int data;
    node *next;
};
node *root=NULL;
void inserfirst(int data)
{
    node *curr_node=root;
    node *temp;
    temp=new node();
    temp->data=data;
    temp->next=curr_node;
    root=temp;

}
void dfsvisit(int x)
{
    color[x]=red;
    
    for(int i=1;i<=nodes;i++)
    {
        if(adj[x][i]==1)
        {
            if(color[i]==white)
            {
               //cout<<i<<"";
                dfsvisit(i);
            }
        }
       
    }
     color[x]=black;
     ans.push(x);//using stack for topological sort
     inserfirst(x);//using linked list  

}
void dfs()
{
    for(int i=1;i<=nodes;i++)
    {
      color[i]=white;
    }
    for(int i=1;i<=nodes;i++)
    {
        if(color[i]==white)
        {
            dfsvisit(i);
        }
    }
}
void printing()
{
    node *curr_node=root;
    while(curr_node!=NULL)
    {
        cout<<curr_node->data<<" ";
        curr_node=curr_node->next;
    }
    cout<<endl;
}
int main()
{

cin>>nodes>>edges;
    for(int i=1;i<=edges;i++)
    {
        int e1,e2;
        cin>>e1>>e2;
        adj[e1][e2]=1;
       
    }
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
      for(int i = 1; i <= nodes; i++)
    {
        cout << i << "-->";
        for(int j = 1; j <=nodes; j++)
        {
            if(adj[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
dfs();
while (!ans.empty())
{
    cout<<ans.top()<<endl;
    ans.pop();
}
printing();

}
/*
7 8
1 3
1 2
2 4
3 4
4 5
4 6
5 7
6 7
*/

