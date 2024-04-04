#include <iostream>
using namespace std;

int partition(char arr[], int low, int high)
{
    char pivot = arr[low];
    int i = low, j = high;

    while (i < j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort(char arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

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

    quickSort(arr, 0, size - 1);

    cout << "The sorted string is :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }

    return 0;
}
