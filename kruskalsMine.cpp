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

class Subset{
    public:
    int parent;
    int rank;
    Subset(int parent,int rank){
        this->parent=parent;
        this->rank=rank;
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

void kruskals(vector<Edge> graph[],int size){
int j=0;
int noEdges=0;
Subset subsets[size];
Edge results[size];
for (int i = 0; i < size; i++) { 
            subsets[i] = new Subset(i, 0); 
        } 
while(noEdges<size-1){
    Edge nextEdge=graph[j];
    
}

}


int main() {
    int size;
    cout << "Enter number of vertices:\n";
    cin >> size;

    vector<Edge> graph[size];
    generateU(graph, size); // Assuming generate() function populates the graph

    cout << "Original Graph:" << endl;
    printGraph(graph, size);

    sort(graph,graph+size);

    kruskals(graph,size);

   

    return 0;
}