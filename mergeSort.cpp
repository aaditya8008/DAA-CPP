#include<iostream>
#include <cmath>
#include <time.h>
using namespace std;
void merge(long long int arr[],int s,int mid,int e){
    int temp[e-s+1];
    int i=s;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;
           
        }
        else{
            temp[k]=arr[j];
            j++;
         
        }
         k++;
    }
    while(i<=mid){
        temp[k]=arr[i];
            i++;
            k++;
    }
    while(j<=e){
         temp[k]=arr[j];
            j++;
            k++;
    }
    for(k=0, i=s;k<=e-s;k++,i++){
        arr[i]=temp[k];
    }
    
}


void mergeSort(long long int arr[],int s,int e){
    if(s<e){
        int mid = s + (e - s) / 2;

        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,mid,e);
        s++;
        e--;
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
        arr[i] = rand() % 999 + 1;
    }
pr(size,arr);
clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
   mergeSort(arr,0,size);
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
   double tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
   pr(size,arr);
   cout<<"Time Taken:"<<tt<<endl;
    return 0;}

//     Enter Size :
// 100000
// Time Taken:0.0184329
