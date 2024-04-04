#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> &weights, vector<int> &values, int capacity)
{
    int n = weights.size();

    // Initialize a 2D vector to store the results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp array bottom-up
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= capacity; ++w)
        {
            if (weights[i - 1] <= w)
            {
                // Recurrence relation: max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1])
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                // If the current item's weight is more than the current capacity, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result is stored at the bottom-right corner of the dp array
    return dp[n][capacity];
}

int main()
{
    // Get user input for weights, values, and capacity
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    // Calculate and display the result
    int result = knapsack(weights, values, capacity);
    cout << "Maximum value that can be obtained: " << result << endl;

    return 0;
}
