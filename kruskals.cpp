#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
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
    // For an undirected graph, you may also want to add the reverse edge
    // List[edge].push_back(Edge(edge, vertex, weight)); // Uncomment this line if the graph is undirected
}

bool compareEdges(const Edge& a, const Edge& b) {
    return a.wt < b.wt;
}

// Find operation for Union-Find
int find(int vertex, vector<int>& parent) {
    if (parent[vertex] == -1)
        return vertex;
    return parent[vertex] = find(parent[vertex], parent);
}

// Union operation for Union-Find
void Union(int a, int b, vector<int>& parent) {
    int parentA = find(a, parent);
    int parentB = find(b, parent);
    if (parentA != parentB)
        parent[parentA] = parentB;
}

void kruskals(vector<vector<Edge>>& adjacencyList, int size) {
    // Flatten the adjacency list into a list of edges
    vector<Edge> edges;
    for (const auto& vertex : adjacencyList) {
        for (const auto& edge : vertex) {
            edges.push_back(edge);
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Union-Find data structure initialization
    vector<int> parent(size, -1);

    // Minimum Spanning Tree
    vector<Edge> MST;
    int edgeCount = 0;
    for (const auto& edge : edges) {
        if (edgeCount == size - 1)
            break;
        int srcParent = find(edge.src, parent);
        int destParent = find(edge.dest, parent);
        if (srcParent != destParent) {
            MST.push_back(edge);
            Union(edge.src, edge.dest, parent);
            edgeCount++;
        }
    }

    // Print the Minimum Spanning Tree
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const auto& edge : MST) {
        cout << "From: " << edge.src << " to " << edge.dest << ", Weight: " << edge.wt << endl;
    }
}

int main() {
    int numVertices;
    cout << "Enter Number of vertices: ";
    cin >> numVertices;

    vector<vector<Edge>> adjacencyList(numVertices);
    vector<bool> visited(numVertices, false);
    vector<string> vertices(numVertices);
    stack<int> Stack;

    cout << "Enter vertex names: " << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": ";
        cin >> vertices[i];
    }

    int numEdges;
    cout << "Enter Number of relations:" << endl;
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        int vertex, edge, weight;
        cout << "Enter Vertex: ";
        cin >> vertex;
        cout << "Enter Edge: ";
        cin >> edge;
        cout << "Enter Weight: ";
        cin >> weight;
        addEdge(adjacencyList, vertex, edge, weight);
    }

    cout << "Adjacency List:" << endl;
    print(vertices, adjacencyList);

    // Apply Kruskal's algorithm
    kruskals(adjacencyList, numVertices);

    return 0;
}
