#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the string to be sorted: ";
    string input;
    cin >> input;

    int size = input.length();
    char arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = input[i];
    }

    char maxvalue = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxvalue)
        {
            maxvalue = arr[i];
        }
    }

    char counting[maxvalue + 1];
    for (int i = 0; i <= maxvalue; i++)
    {
        counting[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        counting[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxvalue; i++)
    {
        while (counting[i] > 0)
        {
            arr[index] = i;
            index++;
            counting[i]--;
        }
    }

    cout << "The sorted string is :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }

    return 0;
}
