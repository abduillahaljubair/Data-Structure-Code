#include<bits/stdc++.h>
using namespace std;

#define white 1
#define Red 2
#define Black 3

int nodes, edges;
vector<vector<int>> adj;
int color[100]; // Assuming maximum number of nodes is 100
int parent[100];
int dis[100];
int a[100];
int level[100];
void bfs(int startingnode)
{
    for(int i = 0; i < nodes; i++)
    {
        color[i] = white;
        parent[i] = 0; // Changed initialization from -1 to 0
        dis[i] = 0;
    }

    dis[startingnode] = 0;
    parent[startingnode] = -1;
    queue<int> q;
q.push(startingnode);
int l=0;
level[startingnode]=0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        int k=0;


        for(int i = 0; i < nodes; i++)
        {
            if(adj[x][i] == 1 && color[i] == white)
            {
                parent[i] = x;
                dis[i] = dis[x] + 1;
                color[i] = Red;
                level[i]=level[x]+1;
                q.push(i);
                k++;
            }
        }
        a[l]=k;
        l++;
        color[x] = Black; // Mark the node as processed
    }
    cout<<endl;
    cout<<"parent of 5= "<<parent[5]<<endl;
    cout<<"distance of  0 to 7 = "<<dis[7]<<endl;
    cout<<"total level = "<<level[nodes-1]<<endl;
    for(int i=0;i<level[nodes-1];i++)
    {

       if(a[i]==0)
        {
            break;
        }
        else if(a[i]%2==0)
        {
            cout<<i+1<<" -> Even"<<endl;
        }
        else
             cout<<i+1<<"-> Odd"<<endl;
    }
}

int main()
{
    cin >> nodes >> edges;
    adj.resize(nodes, vector<int>(nodes, 0));

    for(int i = 0; i < edges; i++)
    {
        int e1, e2;
        cin >> e1 >> e2;
        adj[e1][e2] = 1;
        adj[e2][e1] = 1;
    }

    for(int i = 0; i < nodes; i++)
    {
        for(int j = 0; j < nodes; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
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
    cout << "BFS traversal from node 0: ";
    bfs(0); // Assuming starting node is 0

    return 0;
}
/*
8 7
0 1
0 2
2 4
2 5
1 3
3 6
3 7
*/
