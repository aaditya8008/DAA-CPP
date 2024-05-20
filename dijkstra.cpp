#include <iostream>
#include <limits.h>
using namespace std;

#define NV 9
int minDistance(int dist[], bool included[]){
int min = INT_MAX, min_index;
for (int v = 0; v < NV; v++)
        if (included[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;

}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < NV; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}


void dijkstra(int graph[NV][NV], int src){
int dist[NV];

bool included[NV];


    for (int i = 0; i < NV; i++){
         dist[i]=INT_MAX, included[i]=false;}

    dist[src]=0;

    for(int i=0;i<NV-1;i++){
        int u=minDistance(dist,included);
         included[u]=true;
         for(int j=0;j<NV;j++){
          if(!included[j]&&graph[u][j]&&dist[u] != INT_MAX&&dist[u] + graph[u][j] < dist[j]){
           dist[j] = dist[u] + graph[u][j];
          }

         }

    }
    printSolution(dist);
  

}

int main()
{

    /* Let us create the example graph discussed above */
    int graph[NV][NV] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    // Function call
    dijkstra(graph, 0);

    return 0;
}