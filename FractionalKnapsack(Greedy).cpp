#include <iostream>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

struct Item
{
    int weight;
    int value;
    double ratio; // Profit-to-weight ratio
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio; // Sort in non-decreasing order of profit-to-weight ratio
}

double fractionalKnapsack(vector<Item> &items, int capacity)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (const auto &item : items)
    {
        if (capacity == 0)
        {
            break; // Knapsack is full
        }

        int amountToTake = min(item.weight, capacity);
        totalValue += amountToTake * item.ratio;
        capacity -= amountToTake;
    }

    return totalValue;
}

int main()
{
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the weights and values of the items:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    double result = fractionalKnapsack(items, capacity);

    cout << "Maximum value that can be obtained: " << result << endl;

    return 0;
}