#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {

        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }

    cout << "The sorted array is :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int binarySearch(int arr[], int size, int element)
{
    int s = 0;
    int e = size;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return -1;
}
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

    selectionSort(arr, size);
    cout << endl;
    char choice;
    do
    {
        int element;
        cout << "Enter the number you want to search :" << endl;
        cin >> element;

        int position = binarySearch(arr, size, element);

        if (position != -1)
        {
            cout << element << " found at index " << position << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
        cout << "Search for another number ? (y/n) :" << endl;
        cin >> choice;
    } while (choice == 'y');
}