#include<iostream>
using namespace std;
class Heap{
    enum{
        size=5
    };
public:
int i;
int arr[size];
Heap(){
i=0;
}
void add(int data){
    
    if(i>=size){
        cout<<"Over Flow \n";
        return;
    }
arr[i]=data;
i++;
int x=i-1;
int pr=(x-1)/2;
while (arr[x]>arr[pr])
{
    int temp=arr[x];
    arr[x]=arr[pr];
    arr[pr]=temp;
    x=pr;
    pr=(x-1)/2;
}
}

void heapify(int s,int e){
    int l=2*s+1;
    int r=2*s+2;
    int max=s;
    if(l<e&&arr[l]>arr[s]){
max=l;
    }
     if(r<e&&arr[r]>arr[s]){
max=r;
    }
    if(max!=s){
        int temp=arr[max];
    arr[max]=arr[s];
    arr[s]=temp;
    heapify(max,s);
    }
}
int remove(){
if(!isEmpty()){
    int temp=arr[0];
    arr[0]=arr[i-1];
    arr[i-1]=temp;
    i--;
    heapify(0,i);
    
    return arr[0];
}
return -1;
}
void heapSort(){
    int n=i;
    for(int k=i/2;k>=0;k--){
        heapify(k,n);
    }
for(int k=n-1;k>0;k--){
     int temp=arr[0];
    arr[0]=arr[k];
    arr[k]=temp;
    heapify(0,k);
}
}


bool isEmpty(){
if(i<=0){
    cout<<"Heap UnderFlow\n";
    return true; }
    return false;
}
void peek(){
    if(!isEmpty()){
        cout<<arr[0]<<endl;
    }
}

void pr(){
    if(!isEmpty()){
        for(int j=0;j<i;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}



};
int main(){
Heap h;
 struct timespec s;
    struct timespec e;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
h.add(3);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
   double tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
  
   cout<<"Time Taken:"<<tt<<endl;
h.add(4);
h.add(1);
h.add(5);
h.pr();
 clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
h.remove();
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
 tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
  
   cout<<"Time Taken:"<<tt<<endl;
h.pr();
 clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
h.heapSort();
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
  
   cout<<"Time Taken:"<<tt<<endl;
h.pr();

}