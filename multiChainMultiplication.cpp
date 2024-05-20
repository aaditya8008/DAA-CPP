#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
pair<int, string> brackets[100][100];

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
    if (i == j) 
    {
        return 0;
    }
    if (dp[i][j] != -1) 
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) 
    { 
        int cost = matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (cost < dp[i][j]) {
            dp[i][j] = cost;
            brackets[i][j] = {k, "(" + brackets[i][k].second + brackets[k + 1][j].second + ")"};
        }
    }
    return dp[i][j];
}

int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}

string getMatrixName(int index) {
    return string(1, 'A' + index);
}

string getFullExpression(int i, int j) {
    if (i == j) {
        return getMatrixName(i);
    }
    int split = brackets[i][j].first;
    string left = getFullExpression(i, split);
    string right = getFullExpression(split + 1, j);
    return "(" + left + " * " + right + ")";
}

int main()
{
    int arr[] = { 1, 2, 3, 4 }; // Matrix dimensions
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);

    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, n) << endl;
    
    // Optimal parenthesization with matrix names
    string expression = getFullExpression(1, n - 1);
    cout << "Optimal Parenthesization: " << expression << endl;

    return 0;
}

