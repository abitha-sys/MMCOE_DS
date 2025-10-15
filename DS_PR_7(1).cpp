#include <iostream>
using namespace std;

int adj[10][10], n;
char visited[10];
// 'F' for unvisited, 'T' for visited

void dfs(int v) {
    visited[v] = 'T';    
    cout << v << " ";      

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 'F') {
            dfs(i);
        }
    }
}

int main() {
    int edges;
    cout << "Number of nodes: ";
    cin >> n;
    cout << "Number of edges: ";
    cin >> edges;

    for (int i = 0; i < n; i++) {
        visited[i] = 'F';
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    cout << "Enter edges (node1 node2):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "DFS starting from node 0:\n";
    dfs(0);

    return 0;
}
