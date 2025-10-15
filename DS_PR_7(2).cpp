#include <iostream>
#include <queue>
using namespace std;

int adj[10][10], n;
char visited[10]; // 'F' = unvisited, 'T' = visited

void bfs(int start) {
    queue<int> q;
    visited[start] = 'T';
    q.push(start);

    cout << "Indexing order of web pages (BFS Traversal): ";

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 'F') {
                visited[i] = 'T';
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int edges;
    cout << "Enter number of web pages (nodes): ";
    cin >> n;
    cout << "Enter number of hyperlinks (edges): ";
    cin >> edges;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 'F';
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    cout << "Enter hyperlinks (page1 page2):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected link (bi-directional)
    }

    cout << "\nAdjacency Matrix (Web Links):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nEnter starting page (seed URL index): ";
    int start;
    cin >> start;

    bfs(start);

    return 0;
}
