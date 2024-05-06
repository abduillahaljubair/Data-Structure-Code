#include<bits/stdc++.h>
using namespace std;

int nodes, edges;
vector<pair<int, int>> q[100];
#define white 1
#define red 2
#define black 3
#define INF 1e5
int color[100];
stack<int> res;
vector<int> dis(100, INF);
vector<int> path(100, -1);

void initialize(int src) {
    for(int i = 0; i < nodes; i++) {
        dis[i] = INF;
    }
    dis[src] = 0;
}

void way(int x) {
    if(path[x] != -1) { 
        way(path[x]);
        cout << "->";
    }
    cout << x;
}

void relax(int u, int node, int edge) {
    if(dis[node] > dis[u] + edge) {
        dis[node] = dis[u] + edge;
        path[node] = u;
    }
}

void DAG(int src) {
    initialize(src);
    while(!res.empty()) {
        int u = res.top();
        res.pop();
        for(int i = 0; i < q[u].size(); i++) {
            int node = q[u][i].first;
            int edge = q[u][i].second;
            relax(u, node, edge);
        }
    }
}

void dfsvisit(int x) {
    color[x] = red;
    for(int i = 0; i < q[x].size(); i++) {
        int neig = q[x][i].first;
        if(color[neig] == white) {
            dfsvisit(neig);
        }
    }
    color[x] = black;
    res.push(x);
}

void dfs() {
    for(int i = 0; i < nodes; i++) {
        color[i] = white;
    }
    for(int i = 0; i < nodes; i++) {
        if(color[i] == white) {
            dfsvisit(i);
        }
    }
}

int main() {
    cin >> nodes >> edges;
    for(int i = 0; i < edges; i++) {
        int e1, e2, w;
        cin >> e1 >> e2 >> w;
        q[e1].push_back(make_pair(e2, w));
    }
    dfs();
    int source;
    cin >> source;
    DAG(source);
    
    cout << "Topological Order: ";
    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;
    
    cout << "ALL Paths: " << endl;
    for(int i = 0; i < nodes; i++) {
        cout << "For node " << i << ", cost = " << dis[i] << ", path: ";
        way(i);
        cout << endl;
    }
    cout << "Shortest Paths: " << endl;
     sort(dis.begin(), dis.end());
     cout<<"path= "<<" ";
     way(dis[1]);
     cout<<" "<<"cost="<<" "<<dis[1]<<endl;
     
}
