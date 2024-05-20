#include <iostream>

using namespace std;

class Process{

    public:

    int p,bt,at;

    Process():p(0),bt(0),at(0){}

    Process(int process,int burst,int arrival){

        p=process;

        bt=burst;

        at=arrival;

    }

    void selectionSort(Process arr[],int n){

        for(int i=0;i<n-1;i++){

            int min=i;

            for(int j=i+1;j<n;j++){

                if(arr[j].bt<arr[min].bt){

                    min=j;

                }

            }

            Process temp=arr[i];

            arr[i]=arr[min];

            arr[min]=temp;

        }

    }

    void averageTime(Process arr[],int n){

        float sum_w=0;

        int wt[n];

        float sum_t=0;

        int tat[n];

        wt[0]=0;

        for(int i=1;i<n;i++){

            wt[i]=arr[i-1].bt+wt[i-1];

            sum_w+=wt[i];

        }

        cout<<"awt"<< sum_w/n;

    for(int i=0;i<n;i++){

        tat[i]=arr[i].bt+wt[i];

        sum_t+=tat[i];

    }

    cout<<"atat"<<sum_t/n;}

};

int main(){

    int n;

    cout<<"Enter the number of process: ";

    cin>>n;

    Process *proc=new Process[n];

    for(int i=0;i<n;i++){

        int burst,arrival;

        cout<<"Process "<<i+1;

        cout<<"\nBurst Time:";

        cin>>burst;

        cout<<"Arrival Time: ";

        cin>>arrival;

        proc[i]=Process(i+1,burst,arrival);

    }

    proc->selectionSort(proc,n);

    proc->averageTime(proc,n);

return 0;}


