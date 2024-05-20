#include<iostream>
#include <limits.h>
using namespace std;
class Edge{
    public:
    int src;
    int dest;
    int weight;
    Edge(){
        this->src=0;
     this->dest=0;
     this->weight=0;
    }
    Edge( int src,int dest,int weight){
     this->src=src;
     this->dest=dest;
     this->weight=weight;
    }
};

class Graph{
    public:
    int V,E;
    Edge *edges;
    Graph(int V,int E){
this->V=V;
this->E=E;
edges=new Edge[E];
    }
};


void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
void bellman(Graph *graph,int src){
int v=graph->V;
int e=graph->E;
int dist[v];
for(int i=0;i<v;i++){
    dist[i]=INT_MAX;
}
dist[src]=0;
for (int i = 1; i <= v - 1; i++) {
        for (int j = 0; j < e; j++) {
              int src=graph->edges[j].src;
              int dest=graph->edges[j].dest;
              int weight=graph->edges[j].weight;
            if(dist[src]!=INT_MAX&&dist[src]+weight<dist[dest]){
                dist[dest]=dist[src]+weight;
            }  


        }}
          for (int i = 0; i < e; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        if (dist[u] != INT_MAX
            && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply
                    // return
        }
    }


 printArr(dist, v);
    return;
}
int main(){
    int v=5;
    int e=8;
    Graph *graph=new Graph(5,8);

     graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edges[2].src = 1;
    graph->edges[2].dest = 2;
    graph->edges[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 2;

    // add edge 1-4 (or B-E in above figure)
    graph->edges[4].src = 1;
    graph->edges[4].dest = 4;
    graph->edges[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edges[5].src = 3;
    graph->edges[5].dest = 2;
    graph->edges[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edges[6].src = 3;
    graph->edges[6].dest = 1;
    graph->edges[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edges[7].src = 4;
    graph->edges[7].dest = 3;
    graph->edges[7].weight = -3;
    
      // Function call
    bellman(graph, 0);

    return 0;
}