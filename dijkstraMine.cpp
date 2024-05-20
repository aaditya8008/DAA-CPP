#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Edge {
public:
    int dest;
    int weight;
    Edge(int dest, int weight) {
        this->dest = dest;
        this->weight = weight;
    }
};

// Number of vertices in the graph
#define V 9

void printGraph(const vector<Edge> graph[], int size) {
    cout << "Graph (Adjacency List):" << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Vertex " << i << " --> ";
        for (const auto& edge : graph[i]) {
            cout << "(" << i << "," << edge.dest << "," << edge.weight << ") ";
        }
        cout << endl;
    }
}

int minDistance(const vector<int>& dist, const vector<bool>& included) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < dist.size(); v++) {
        if (!included[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(const vector<Edge> graph[], int src, int size) {
    vector<int> dist(size, INT_MAX);
    vector<bool> included(size, false);
    dist[src] = 0;

    for (int count = 0; count < size - 1; count++) {
        int u = minDistance(dist, included);
        if (u == -1) break;  // All reachable nodes are processed
        included[u] = true;

        for (const auto& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;
            if (!included[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    // Define the adjacency matrix
    int matrix[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                         { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                         { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                         { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                         { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                         { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                         { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                         { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                         { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Initialize the adjacency list
    vector<Edge> graph[V];

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (matrix[i][j] != 0) {
                graph[i].push_back(Edge(j, matrix[i][j]));
            }
        }
    }

    printGraph(graph, V);

    int src;
    cout << "Enter source vertex for Dijkstra's algorithm: ";
    cin >> src;
    if (src < 0 || src >= V) {
        cout << "Invalid source vertex." << endl;
        return 1;
    }

    dijkstra(graph, src, V);

    return 0;
}
