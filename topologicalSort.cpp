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
}

void topoSort(int start, const vector<vector<Edge>> &List, stack<int> &Stack, vector<bool> &visited) {
    visited[start] = true;
    for (const Edge &e : List[start]) {
        if (!visited[e.dest]) {
            topoSort(e.dest, List, Stack, visited);
        }
    }
    Stack.push(start);
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
        int vertex, edge;
        cout << "Enter Vertex: ";
        cin >> vertex;
        cout << "Enter Edge: ";
        cin >> edge;
        addEdge(adjacencyList, vertex, edge);
    }

    cout << "Adjacency List:" << endl;
    print(vertices, adjacencyList);

    // Perform topological sort
    for(int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            topoSort(i, adjacencyList, Stack, visited);
        }
    }
    
    cout << endl << "Topological Sort:" << endl;
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }

    

    return 0;
}


