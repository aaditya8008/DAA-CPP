#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void insert(int data, int idx, int size, int arr[], int *end) {
    if (idx < size && idx >= 0) {
        int prev = data;
        int next = arr[idx];
        for (int i = idx; i < size; i++) {
            arr[i] = prev;
            prev = next;
            next = arr[i + 1];
        }
        (*end)++;
    } else {
        cout << "Index Out Of Bounds\n";
    }
}

void del(int idx, int size, int arr[], int *end) {
    if (idx < size && idx >= 0) {
        for (int i = idx; i < size; i++) {
            arr[i] = arr[i + 1];
        }
        (*end)--;
    } else {
        cout << "Index Out Of Bounds\n";
    }
}

double avg(int arr[], int end) {
    double sum = 0;
    for (int i = 0; i < end; i++) {
        sum += arr[i];
    }
    return sum / end;
}

int summ(int arr[], int end) {
    int sum = 0;
    for (int i = 0; i < end; i++) {
        sum += arr[i];
    }
    return sum;
}

int max(int arr[], int end) {
    int m = arr[0];
    for (int i = 0; i < end; i++) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }
    return m;
}

int min(int arr[], int end) {
    int m = arr[0];
    for (int i = 0; i < end; i++) {
        if (arr[i] < m) {
            m = arr[i];
        }
    }
    return m;
}

bool isSorted(int arr[], int end) {
    for (int i = 0; i < end - 1; i++) {
        if (arr[i + 1] < arr[i]) {
            return false;
        }
    }
    return true;
}

int binarySearch(int arr[], int size, int target) {
    int s = 0;
    int e = size - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (target > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return -1;
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void findOdd(int arr[], int size) {
    cout << "Odd numbers in the array: ";
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

bool isPrime(int x) {
    if (x <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void findPrime(int arr[], int size) {
    cout << "Prime numbers in the array: ";
    for (int i = 0; i < size; ++i) {
        if (isPrime(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

double standardDeviation(int arr[], int size) {
    double mean = avg(arr, size);
    double sumSquaredDifferences = 0;
    for (int i = 0; i < size; i++) {
        double diff = arr[i] - mean;
        sumSquaredDifferences += diff * diff;
    }
    double var = sumSquaredDifferences / size;
    double sd = sqrt(var);
    return sd;
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void pr(int size, int arr[]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10];
    int size = 10;
    int end = 0;

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 999 + 1;
        end++;
    }

    int choice;
    cout << "Array generated: ";
    pr(end, arr);

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Calculate average\n";
        cout << "4. Calculate sum\n";
        cout << "5. Find maximum\n";
        cout << "6. Find minimum\n";
        cout << "7. Check if sorted\n";
        cout << "8. Binary Search\n";
        cout << "9. Linear Search\n";
        cout << "10. Print\n";
        cout << "11. Insertion Sort\n";
        cout << "12. Find Odd Numbers\n";
        cout << "13. Find Prime Numbers\n";
        cout << "14. Calculate Standard Deviation\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        struct timespec s;
        struct timespec e;
        double tt;
        switch (choice) {
            case 1: {
                int data, idx;
                cout << "Enter the data to insert: ";
                cin >> data;
                cout << "Enter the index to insert at: ";
                cin >> idx;

                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                insert(data, idx, size, arr, &end);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                 tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                pr(end, arr);
                break;
            }
            case 2: {
                int idx;
                cout << "Enter the index to delete: ";
                cin >> idx;

                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                del(idx, size, arr, &end);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                 tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                pr(end, arr);
                break;
            }
            case 3:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                cout << "Average: " << avg(arr, end) << endl;
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                 tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 4:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                cout << "Sum: " << summ(arr, end) << endl;
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 5:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                cout << "Maximum: " << max(arr, end) << endl;
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 6:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                cout << "Minimum: " << min(arr, end) << endl;
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 7:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                if (isSorted(arr, end)) {
                    cout << "Array is sorted.\n";
                } else {
                    cout << "Array is not sorted.\n";
                }
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 8: {
                int target;
                cout << "Enter the element to search: ";
                cin >> target;

                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                if (isSorted(arr, end)) {
                    int result = binarySearch(arr, size, target);
                    if (result != -1) {
                        cout << "Element " << target << " found at index " << result << ".\n";
                    } else {
                        cout << "Element " << target << " not found in the array.\n";
                    }
                } else {
                    cout << "Array is not sorted. Cannot perform binary search.\n";
                }
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            }
            case 9: {
                int target;
                cout << "Enter the element to search: ";
                cin >> target;

                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                int result = linearSearch(arr, size, target);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                if (result != -1) {
                    cout << "Element " << target << " found at index " << result << ".\n";
                } else {
                    cout << "Element " << target << " not found in the array.\n";
                }
                break;
            }
            case 10:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                pr(end, arr);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 11:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                insertionSort(arr, end);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                pr(end, arr);
                break;
            case 12:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                findOdd(arr, end);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 13:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                findPrime(arr, end);
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 14:
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
                cout << "Standard Deviation: " << standardDeviation(arr, end) << endl;
                clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
                tt = (e.tv_sec - s.tv_sec) + (e.tv_nsec - s.tv_nsec) / (1000000000.0);
                cout << "Time taken: " << tt << endl;
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}