#include<iostream>
using namespace std;


void insertionSort(long long int arr[],int s,int e){

    for(int i=s+1;i<=e;i++){
       long long  int key=arr[i];
int j=i-1;
while(j>=s&&key<arr[j]){
    arr[j+1]=arr[j];
    j--;
}
arr[j+1]=key;
    }
}
void merge(long long int arr[],int s,int mid,int e){
   
//int r=mid+1;
 for(int i=s;i<=mid;i++){
if(arr[i]>arr[mid+1]){
    long long temp=arr[i];
    arr[i]=arr[mid+1];
    arr[mid+1]=temp;
    insertionSort(arr,mid+1,e);
}

 }
    
}

void pr(int size, long long int arr[]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void mergeSort(long long arr[],int s,int e){
if(s!=e){
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
    }

}
int main(){
    long long int size;
    int choice;
    cout << "Enter Size :\n";
    cin >> size;
    long long int arr[size];
    struct timespec s;
    struct timespec e;


    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 999 + 1;
    }
pr(size,arr);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
   mergeSort(arr,0,size-1);
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
   double tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
   pr(size,arr);
   cout<<"Time Taken:"<<tt<<endl;
    return 0;
}