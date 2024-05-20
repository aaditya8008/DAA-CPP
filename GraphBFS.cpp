#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int wt;

    Edge(int src, int dest, int wt) : src(src), dest(dest), wt(wt) {}
};

void print(const vector<string> &dest, const vector<vector<Edge>> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << "Vertex " << i << " edges:" << endl;
        for (const auto &edge : arr[i]) {
            cout << "From: " << dest[edge.src] << " to " << dest[edge.dest] << ", Weight: " << edge.wt << endl;
        }
    }
}

void addEdge(vector<vector<Edge>> &List, int vertex, int edge, int weight = 0) {
    List[vertex].push_back(Edge(vertex, edge, weight));
}

void dfs(int start, const vector<vector<Edge>> &List, vector<bool> &visited) {
    visited[start] = true;
    cout << start << " ";

    for (const Edge &e : List[start]) {
        if (!visited[e.dest]) {
            dfs(e.dest, List, visited);
        }
    }
}



void bfs(int start, const vector<vector<Edge>> &List, vector<bool> &visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (const Edge &e : List[curr]) {
            if (!visited[e.dest]) {
                visited[e.dest] = true;
                q.push(e.dest);
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter Number of vertices: ";
    cin >> size;

    vector<vector<Edge>> List(size);
    vector<bool> visited(size, false);
    vector<string> vertices(size);

    cout << "Enter vertex names: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Vertex " << i << ": ";
        cin >> vertices[i];
    }

    cout << "Enter Number of relations:" << endl;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int vertex, edge;
        cout << "Enter Vertex: ";
        cin >> vertex;
        cout << "Enter Edge: ";
        cin >> edge;
        addEdge(List, vertex, edge);
    }

    cout << "Adjacency List:" << endl;
    print(vertices, List);

    int choice;
    cout << "\nChoose traversal method:" << endl;
    cout << "1. BFS Traversal" << endl;
    cout << "2. DFS Traversal" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "BFS Traversal from vertex 0:" << endl;
            bfs(0, List, visited);
            break;
        case 2:
            cout << "DFS Traversal from vertex 0:" << endl;
            dfs(0, List, visited);
            break;
        default:
            cout << "Invalid choice!";
    }

    return 0;
}





