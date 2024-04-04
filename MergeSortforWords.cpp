#include <iostream>
using namespace std;

void merge(char arr[], int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    char leftArray[leftSize], rightArray[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = arr[start + i];
    }
    for (int j = 0; j < rightSize; j++)
    {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k++] = leftArray[i++];
        }
        else
        {
            arr[k++] = rightArray[j++];
        }
    }

    while (i < leftSize)
    {
        arr[k++] = leftArray[i++];
    }

    while (j < rightSize)
    {
        arr[k++] = rightArray[j++];
    }
}

void mergeSort(char arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    string input;
    cout << "Enter the string to be sorted: " << endl;
    cin >> input;

    int size = input.length();
    char arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = input[i];
    }

    mergeSort(arr, 0, size - 1);

    cout << "Sorted string: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
