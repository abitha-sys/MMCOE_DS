#include <iostream>
using namespace std;

#define MAX 10

int adj[MAX][MAX];  // adjacency matrix
char visited[MAX];  // 'F' = unvisited, 'T' = visited
int n;              // number of nodes

// ----- Queue Implementation -----
int queueArr[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == MAX - 1);
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!\n";
        return;
    }
    if (front == -1)
        front = 0;
    queueArr[++rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return queueArr[front++];
}
// --------------------------------

// BFS Function
void bfs(int start) {
    enqueue(start);
    visited[start] = 'T';

    cout << "\nBFS Traversal (Web Page Indexing Order): ";

    while (!isEmpty()) {
        int v = dequeue();
        if (v == -1) break;
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 'F') {
                enqueue(i);
                visited[i] = 'T';
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
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    cout << "Enter hyperlinks (page1 page2):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    int start;
    cout << "\nEnter starting page (seed URL index): ";
    cin >> start;

    bfs(start);

    return 0;
}
