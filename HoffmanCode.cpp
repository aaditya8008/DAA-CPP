#include<iostream>
#include <queue>
#include<vector>
using namespace std;

class Node{
public:
    char data;
    int freq;
    Node *r;
    Node *l;

    Node(char d,int f){
        data=d;
        freq=f;
        r=NULL;
        l=NULL;
    }
};
void pr(Node* root, string str) 
{ 
  
    if (!root) 
        return; 
  
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
  
    pr(root->l, str + "0"); 
    pr(root->r, str + "1"); 
} 

struct compare {
    bool operator()(Node *l,Node *r){
        return (l->freq > r->freq);
    }
};



void Huffman(char data[],int freq[],int size){
    Node *l,*r,*top;
    priority_queue<Node*,vector<Node*>,compare> heap;

    // Create a priority queue of Nodes
    for(int i=0;i<size;i++){
        heap.push(new Node(data[i],freq[i]));
    }

    while (heap.size() > 1) {
        // Extract two minimum freq items from min heap
        l = heap.top();
        heap.pop();

        r = heap.top();
        heap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        top = new Node('$', l->freq + r->freq);
        top->l = l;
        top->r = r;

        // Add the new node to the min heap
        heap.push(top);
    }

    // Print Huffman codes
    pr(heap.top(), "");
}

int main() { 
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    Huffman(arr, freq, size); 
  
    return 0; 
}

