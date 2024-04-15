#include <bits/stdc++.h>
using namespace std;

void BFS(int s, int v, vector<int> vec[]) {
    queue<int> q;
    vector<int> vis(v + 1, false);
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << endl;

        for (int i = 0; i < vec[u].size(); i++) {
            int p = vec[u][i];

            if (!vis[p]) {
                vis[p] = true;
                q.push(p);
            }
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: " << endl;
    cin >> nodes >> edges;

    vector<int> vec[7];  // Changed the size to 7 to match the node indices (1 to 6)

    for (int i = 1; i <= edges; i++) {
        int nodea, nodeb;
        cin >> nodea >> nodeb;
        vec[nodea].push_back(nodeb);
        vec[nodeb].push_back(nodea);  // Assuming an undirected graph, add this line
    }

    for (int i = 1; i <= nodes; i++) {
        cout << i << "->";
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    BFS(1, nodes, vec);

    return 0;
}
