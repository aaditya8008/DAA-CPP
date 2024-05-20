#include <iostream>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int wt;
    Edge(int src, int dest, int wt) {
        this->src = src;
        this->dest = dest;
        this->wt = wt;
    }
    Edge(int src, int dest) {
        this->src = src;
        this->dest = dest;
        this->wt = 0;
    }
};

void print(string dest[], Edge *arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << "From:" << dest[arr[i]->src] << "->" << dest[arr[i]->dest] << endl;
}

int main() {
    int size;
    cout << "Enter size:" << endl;
    cin >> size;

    Edge *arr[size];
    string dest[size];
    bool vis[size][size];

 for (int i = 0; i < size; i++) {
    for(int j=0;j<size;j++){
       vis[i][j]=false;}
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter destination:";
        cin >> dest[i];
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        int src, dest;
        cout << "Enter Source:";
        cin >> src;
        cout << "Enter Destination:";
        cin >> dest;
        if(!vis[src][dest]&&!vis[dest][src]){
        arr[i] = new Edge(src, dest);
        vis[src][dest]=true;
        }
        else{
            cout<<"Edge already exists";
            i--;
        }
        cout << endl;
    }

    print(dest, arr, size);

    // Free memory
    for (int i = 0; i < size; i++) {
        delete arr[i];
    }

    return 0;
}