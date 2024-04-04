#include <iostream>
#include <vector>
using namespace std;

int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> dp)
{
    // Base case
    //  if only 1 item to steal, then just compare it's weight with the knapsack capacity
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;

    if (weight[index] <= capacity)
    {
        include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
       int exclude = 0 + solveMem(weight, value, index - 1, capacity, dp);

        int ans = max(exclude, include);
        return ans; 
    }
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solveMem(weight, value, n - 1, maxWeight, dp);
}

int main()
{
     int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter the weights of items:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> weight[i];
    }

    cout << "Enter the values of items:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> value[i];
    }

    int maxWeight;
    cout << "Enter the maximum weight the knapsack can hold: ";
    cin >> maxWeight;

    int result = knapsack(weight, value, n, maxWeight);

    cout << "Maximum value in knapsack: " << result << endl;



    return 0;
}