#include <iostream>
#include <algorithm>
using namespace std;

class Job {
public:
    int pr;
    int et;
    int st;
    Job(int profit, int end, int start) {
        pr = profit;
        et = end;
        st = start;
    }
};

void calc(Job arr[], int size) {
    sort(arr, arr + size, [](const Job &a, const Job &b) {
        return a.pr > b.pr; // Sort in descending order of profit
    });

    int sum = 0;
    int prev = arr[0].et;
    for (int i = 0; i < size; i++) {
        if (prev <= arr[i].st) {
            sum += arr[i].pr;
            prev = arr[i].et;
        }
    }
    cout << "Total Profit:" << sum << endl;
}

int main() {
    int n;
    cout << "Enter Number of Jobs:\n";
    cin >> n;
    Job *arr = new Job[n];
    for (int i = 0; i < n; i++) {
        int st, et, pr;
        cout << "Enter start time for job " << i + 1 << ":\n";
        cin >> st;
        cout << "Enter end time for job " << i + 1 << ":\n";
        cin >> et;
        cout << "Enter profit for job " << i + 1 << ":\n";
        cin >> pr;
        arr[i] = Job(pr, et, st);
    }
    calc(arr, n);
    delete[] arr; // Free dynamically allocated memory
    return 0;
}
