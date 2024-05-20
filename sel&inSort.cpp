#include<iostream>
#include <cmath>
#include <time.h>
using namespace std;

void selectionSort(long long int arr[],int size){
     struct timespec s;
        struct timespec e;
         double tt=0;
         clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
for(int i=0;i<size-1;i++){
     int minIdx=i;
  
    for(int j=i+1;j<size;j++){
if(arr[j]<arr[minIdx]){
    
    minIdx=j;
   
}
    }
   if(minIdx!=i){
    long long int temp=arr[i];
    arr[i]=arr[minIdx];
    arr[minIdx]=temp;
    
}

}
 clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
     tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
}

void insertionSort(long long int arr[],int size){
    struct timespec s;
        struct timespec e;
         double tt=0;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
    for(int i=1;i<size;i++){
        long long int key=arr[i];
long long int j=i-1;
while(j>=0&&key<arr[j]){
    arr[j+1]=arr[j];
    j--;
}
arr[j+1]=key;
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
     tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
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

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 999 + 1;
    }

    cout << "Choose sorting method:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Selection Sort\n";
    cin >> choice;

    switch(choice) {
        case 1:
            insertionSort(arr, size);
            break;
        case 2:
            selectionSort(arr, size);
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }
    return 0;
}

// Enter Size :
// 100000
// Choose sorting method:
// 1. Insertion Sort
// 2. Selection Sort
// 1
// Time taken: 5.60317

// Enter Size :
// 100000
// Choose sorting method:
// 1. Insertion Sort
// 2. Selection Sort
// 2
// Time taken: 10.2225