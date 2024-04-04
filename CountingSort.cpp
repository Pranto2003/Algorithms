#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter the size of array :" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter  the elements in array :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int maxvalue = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxvalue)
        {
            maxvalue = arr[i];
        }
    }

    int counting[maxvalue + 1];
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

    cout << "The sorted array is :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}