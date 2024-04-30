#include<bits/stdc++.h>
using namespace std;
int adj[100][100];
int main()
{
    cout<<"enter the nodes : ";
    int node;
    cin>>node;
    cout<<"enter the edges : ";
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        int e1,e2;
        cin>>e1>>e2;
        adj[e1][e2]=1;
        adj[e2][e1]=1;
    }
    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }


}
/*
5 6
0 1
2 0
2 1
3 4
1 4
3 1
*/

