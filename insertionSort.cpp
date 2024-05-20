#include<iostream>
#include <cmath>
#include <ctime>
using namespace std;
void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key=arr[i];
int j=i-1;
while(j>=0&&key<arr[j]){
    arr[j+1]=arr[j];
    j--;
}
arr[j+1]=key;
    }
}


void pr(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
   struct timespec s;
   struct timespec e;
   double tt=0;

      int arr[10];
    int size = 10;
    int end = 0;

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 999 + 1;
        end++;
    }
    pr(end,arr);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
   insertionSort(arr,end);
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
   tt=(e.tv_sec-s.tv_sec)+(e.tv_nsec-s.tv_nsec)/(1000000000.0);
     cout << "Time taken: " << tt << endl;
    pr(end,arr);
    
}