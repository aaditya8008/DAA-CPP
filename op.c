#include <stdio.h>

int main() {
    int size;
    printf("Enter Number of processes:\n");
    scanf("%d", &size);
    int arr[size][2], wt[size], tat[size];
    printf("Enter Burst Time:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i][1]);
        arr[i][0] = i;
    }
    printf("Enter Arrival Time:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i][0]);
    }

    int pr = 0;
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[min][0] > arr[j][0] || (arr[min][0] == arr[j][0] && arr[min][1] > arr[j][1])) {
                min = j;
            }
        }
        int temp = arr[i][1];
        arr[i][1] = arr[min][1];
        arr[min][1] = temp;
        temp = arr[i][0];
        arr[i][0] = arr[min][0];
        arr[min][0] = temp;
    }

    for (int i = 0; i < size; i++) {
        arr[i][1] += pr;
        pr = arr[i][1];
    }

    for (int i = 0; i < size; i++) {
        wt[arr[i][0]] = arr[i][1] - arr[i][0];
        tat[arr[i][0]] = wt[arr[i][0]] + arr[i][1];
    }

    printf("Process\tArrival Time\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", arr[i][0], arr[i][0], arr[i][1], wt[arr[i][0]], tat[arr[i][0]]);
    }

    return 0;
}
