#include <iostream>
#include <string>
using namespace std;

// Function to print the adjacency matrix
void printMatrix(int **arr, string dest[], int size) {
    cout << "Adjacency Matrix:" << endl;
    // Print column labels
    cout << "  ";
    for (int i = 0; i < size; i++) {
        cout << dest[i] << " ";
    }
    cout << endl;

    // Print row labels and matrix elements
    for (int i = 0; i < size; i++) {
        cout << dest[i] << "\t";
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to add edges for an undirected graph
void unDirected(int **arr, string dest[], int size) {
    int src, d;
    cout << "Enter Source and Destination for edges (0-based indexing):" << endl;
    while (cin >> src >> d) {
        if (src < 0 || src >= size || d < 0 || d >= size) {
            cout << "Invalid input. Please enter valid source and destination indices." << endl;
            continue;
        }
        arr[src][d] = 1;
        arr[d][src] = 1; // For undirected graph, add edge in both directions
    }
}

// Function to add edges for a directed graph
void directed(int **arr, string dest[], int size) {
    int src, d;
    cout << "Enter Source and Destination for edges (0-based indexing):" << endl;
    while (cin >> src >> d) {
        if (src < 0 || src >= size || d < 0 || d >= size) {
            cout << "Invalid input. Please enter valid source and destination indices." << endl;
            continue;
        }
        arr[src][d] = 1; // For directed graph, add edge only in one direction
    }
}

int main() {
    int size;
    cout << "Enter size of the graph:" << endl;
    cin >> size;

    string dest[size];
    int **arr = new int*[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            arr[i][j] = 0; // Initialize all elements to 0
        }
    }

    cout << "Enter destinations:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter destination " << i + 1 << ": ";
        cin >> dest[i];
    }

    char graphType;
    cout << "Enter 'U' for undirected graph, 'D' for directed graph: ";
    cin >> graphType;

    if (graphType == 'U' || graphType == 'u') {
        unDirected(arr, dest, size);
    } else if (graphType == 'D' || graphType == 'd') {
        directed(arr, dest, size);
    } else {
        cout << "Invalid graph type!";
    }

    printMatrix(arr, dest, size);

    // Free memory allocated for the adjacency matrix
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

