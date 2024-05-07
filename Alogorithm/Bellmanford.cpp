#include <bits/stdc++.h>
using namespace std;

int nodes, edges;
const int INF = 1e5;

int adj[100][100];
vector<int> dis(100, INF);
vector<int> path(100, -1);

void relax(int u, int node, int edge) {
    if (dis[node] > dis[u] + edge) {
        dis[node] = dis[u] + edge;
        path[node] = u;
    }
}

void initialize(int src) {
    for (int i = 0; i < nodes; i++) {
        dis[i] = INF;
    }
    dis[src] = 0;
}

void bellmanford(int src) {
    initialize(src);
    int j, k;
    for (int i = 0; i < nodes - 1; i++) {
        for (j = 0; j < nodes; j++) {
            for (k = 0; k < nodes; k++) {
                if (adj[j][k] != 0) { // Check if there's an edge
                    int weight = adj[j][k];
                    relax(j, k, weight);
                }
            }
        }
    }
    for (j = 0; j < nodes; j++) {
        for (k = 0; k < nodes; k++) {
            if (adj[j][k] != 0 && dis[k] > dis[j] + adj[j][k]) {
                cout << "Negative cycle found" << endl;
                return;
            }
        }
    }
}

void way(int x) {
    if (path[x] != -1) {
        way(path[x]);
        cout << "->";
    }
    cout << x;
}

int main() {
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++) {
        int e1, e2, w;
        cin >> e1 >> e2 >> w;
        adj[e1][e2] = w;
    }
    int source;
    cin >> source;
    bellmanford(source);

    cout << "ALL Paths: " << endl;
    for (int i = 0; i < nodes; i++) {
        cout << "For node " << i << ", cost = " << dis[i] << ", path: ";
        way(i);
        cout << endl;
    }
    cout << "Shortest Paths: " << endl;
    int shortest_path_cost= *min_element(dis.begin(), dis.end());
    cout << "path = ";
    way(min_element(dis.begin(), dis.end()) - dis.begin());
    cout << ", cost = " << shortest_path_cost << endl;

    return 0;
}
/*

5 10
0 1 6
0 3 7
1 2 5
1 3 8
1 4 -4
2 1 -2
3 2 -3
3 4 9
4 2 7
4 0 2
0

*/
