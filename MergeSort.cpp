#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArray[leftSize], rightArray[rightSize];

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

void mergeSort(int arr[], int start, int end)
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
    int size;
    cout << "Enter the size of array :" << endl;
    cin >> size;
    int arr[size];

    cout << "Enter the elements in array :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
