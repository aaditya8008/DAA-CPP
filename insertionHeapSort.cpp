#include<iostream>
using namespace std;

void heapify(int heap[],int curr,int e){
int l=2*curr+1;
int r=2*curr+2;
int max=curr;
if(l<e&&heap[max]<heap[l]){
    max=l;
}
if(r<e&&heap[max]<heap[r]){
    max=r;
}
if(max!=curr){
int temp = heap[curr];
            heap[curr] = heap[max];
            heap[max] = temp;
            heapify(heap, max, e);
}

}

void heapSort(int heap[],int size){
     cout<<"Internals:\n";
for(int i=size/2;i>=0;i--){
    cout<<"Elements:"<<heap[i]<<", Index"<<i<<endl;
heapify(heap,i,size);
}
 cout<<"Leaf:\n";
for(int i=size-1;i>0;i--){
      cout<<"Elements:"<<heap[i]<<", Index"<<i<<endl;
    int temp=heap[0];
    heap[0]=heap[i];
    heap[i]=temp;
    heapify(heap,0,i);
}

}

void pr(int arr[],int size){
for (int i = 0; i < size; i++) {
        cout<<arr[i] << " ";
        }
}


int main(){
    int size;
    cout<<"Enter Size:\n";
    cin>>size;
    int heap[size];
    cout<<"Enter Elements:\n";
    for (int i = 0; i < size; i++) {
        cin>>heap[i];
        }
 
    pr(heap,size);
    for (int i = 0; i < size; i++) {
        heapify(heap,i,size);
        }
     pr(heap,size);
}