#include <iostream>
#include <climits>
using namespace std;

int matrixChainMultiplication(int dims[], int n) {
    int dp[n][n];

    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int chainLen = 2; chainLen < n; chainLen++) {
        for (int i = 1; i < n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    int dims[n + 1];
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    }

    int minOperations = matrixChainMultiplication(dims, n + 1);
    cout << "Minimum number of operations: " << minOperations << endl;
    return 0;
}
