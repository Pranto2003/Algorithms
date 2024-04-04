#include <iostream>
using namespace std;
//! Finding the minimum  and maximum amount of money to buy all the candies

class Candy
{
public:
    int minimumAmountforCandy(int candies[], int numberofcandies, int freecandies)
    {
        int mini = 0;
        int buy = 0;
        int free = numberofcandies - 1;

        while (buy <= free)
        {
            mini = mini + candies[buy];
            buy++;
            free = free - freecandies;
        }
        return mini;
    }

    int maximumAmountforCandy(int candies[], int numberofcandies, int freecandies)
    {
        int maxi = 0;
        int buy = numberofcandies - 1;
        int free = 0;

        while (free <= buy)
        {
            maxi = maxi + candies[buy];
            buy--;
            free = free + freecandies;
        }
        return maxi;
    }
};
int main()
{
    int numberofcandies, freecandies;

    cout << "How many candies are there?" << endl;
    cin >> numberofcandies;

    cout << "How many candies can you get for free ?" << endl;
    cin >> freecandies;
    int arr[numberofcandies];

    cout << "Enter the types of candies" << endl;
    for (int i = 0; i < numberofcandies; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < numberofcandies; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    Candy cand;

    int minimum_money = cand.minimumAmountforCandy(arr, numberofcandies, freecandies);
    int maximum_money = cand.maximumAmountforCandy(arr, numberofcandies, freecandies);

    cout << "You need minimum " << minimum_money << " taka to buy all the candies" << endl;
    cout << "You need maximum " << maximum_money << " taka to buy all the candies" << endl;

    return 0;
}