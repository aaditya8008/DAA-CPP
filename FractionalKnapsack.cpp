#include<iostream>
#include<algorithm>
using namespace std;

class job {
public:
    int idx;
    int weight;
    int profit;
    float ratio;
job(){
    idx=0;
    weight=0;
    profit=0;
    ratio=0;
}
    job(int w, int p, int i) {
        idx = i;
        weight = w;
        profit = p;
        ratio = (float)p / w; // Calculate ratio as profit/weight
    }

    void pr(){
        cout<<"idx:"<<idx<<"\tWeight: "<<weight<<"\tProfit: "<<profit<<"\tRatio :"<<ratio<<endl;
    }
};

bool compare(job j1, job j2) {
    return j1.ratio > j2.ratio;
}

int main() {
    struct timespec s;
    struct timespec e;
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
    int capacity;
    cout << "Enter Capacity :" << endl;
    cin >> capacity;
    cout << "Enter Job Length:" << endl;
    int size;
    cin >> size;
    job Job[size];

    for (int i = 0; i < size; i++) {
        int weight, profit;
        cout << "Enter weight:\n";
        cin >> weight;
        cout << "Enter Profit:\n";
        cin >> profit;
        Job[i] = job(weight, profit, i); // Directly initialize objects
    }

    sort(Job, Job + size, compare);

    float maxProfit = 0;
    for (int i = 0; i < size; i++) {
        if (capacity >= Job[i].weight) {
            maxProfit += Job[i].profit;
            capacity -= Job[i].weight;
            Job[i].pr();

        } else {
            maxProfit += (float)capacity / Job[i].weight * Job[i].profit;
            Job[i].pr();
            break;
        }
    }

    cout << "Maximum Profit: " << maxProfit << endl;
 double tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
    cout << "Time Taken: " << tt << endl;
    return 0;
}


// Enter Profit:
// 120
// idx:0	Weight: 10	Profit: 60	Ratio :6
// idx:1	Weight: 20	Profit: 100	Ratio :5
// idx:2	Weight: 30	Profit: 120	Ratio :4
// Maximum Profit: 240
// Time Taken: 140728


// === Code Execution Successful ===