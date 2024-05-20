#include<iostream>
#include <cmath>
#include <time.h>
using namespace std;


int partition(long long int arr[],int s,int e){
    long long int key=arr[e];
    int i=s-1;
    for(int j=s;j<=e;j++){
        if(arr[j]<=key){
            i++;
            long long int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    i++;
     long long int temp=key;
            arr[e]=arr[i];
            arr[i]=temp;
return i;
}

void quickSort(long long int arr[],int s,int e){
if(s<e){
    int pivot=partition(arr,s,e);
    quickSort(arr,s,pivot-1);
    quickSort(arr,pivot+1,e);
}

}

void pr(int size, long long int arr[]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
        arr[i] = rand() % size + 1;
    }
pr(size,arr);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
   quickSort(arr,0,size-1);
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
   double tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
   pr(size,arr);
   cout<<"Time Taken:"<<tt<<endl;
    return 0;}