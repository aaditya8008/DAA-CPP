#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;
    Edge(int src, int dest, int w) {
        this->src = src;
        this->dest = dest;
        this->weight = w;
    }
    Edge(int src, int dest) {
        this->src = src;
        this->dest = dest;
        this->weight = 0;
    }
    Edge() {
        this->src = 0;
        this->dest = 0;
        this->weight = 0;
    }
};

void printGraph(vector<Edge> graph[], int size) {
    cout << "Graph:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Vertex " << i << " --> ";
        for (const auto& edge : graph[i]) {
            cout << "(" << edge.src << "," << edge.dest << ")";
        }
        cout << endl;
    }
}

void generateU(vector<Edge> graph[], int size) {
    int src, d;
    cout << "Enter Source and Destination for edges (0-based indexing):" << endl;
    while (cin >> src >> d) {
        if (src < 0 || src >= size || d < 0 || d >= size) {
            cout << "Invalid input. Please enter valid source and destination indices." << endl;
            continue;
        }
        graph[src].push_back(Edge(src, d));
        graph[d].push_back(Edge(d, src));
    }
}

void generateD(vector<Edge> graph[], int size) {
    int src, d;
    cout << "Enter Source and Destination for edges (0-based indexing):" << endl;
    while (cin >> src >> d) {
        if (src < 0 || src >= size || d < 0 || d >= size) {
            cout << "Invalid input. Please enter valid source and destination indices." << endl;
            continue;
        }
        graph[src].push_back(Edge(src, d));
    }
}

void topoSort(int src, vector<Edge> graph[], int size, bool visited[], stack<int>& s) {
    visited[src] = true;
    for (const auto& edge : graph[src]) {
        if (!visited[edge.dest]) {
            topoSort(edge.dest, graph, size, visited, s);
        }
    }
    s.push(src);
}

void dfs(int src, vector<Edge> graph[], int size, bool visited[]) {
    visited[src] = true;
    cout << src << "->";
    for (const auto& edge : graph[src]) {
        if (!visited[edge.dest]) {
            dfs(edge.dest, graph, size, visited);
        }
    }
}

void bfs(vector<Edge> graph[], int size) {
    vector<bool> visited(size, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << "Visited:" << x << endl;
        for (const auto& edge : graph[x]) {
            if (!visited[edge.dest]) {
                q.push(edge.dest);
                visited[edge.dest] = true;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter number of vertices:\n";
    cin >> size;

    vector<Edge> graph[size];
    generateD(graph, size); // Assuming generate() function populates the graph

    cout << "Original Graph:" << endl;
    printGraph(graph, size);

    bool visited[size] = {false};

    stack<int> s;

    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            topoSort(i, graph, size, visited, s);
        }
    }

    cout << "Topological Order:" << endl;
    while (!s.empty()) {
        cout << "->" << s.top();
        s.pop();
    }

    return 0;
}

