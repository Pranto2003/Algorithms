#include <iostream>
using namespace std;

void insertionSort(int array[], int size)
{

    for (int i = 1; i < size; i++){
        int temp = array[i];
        int j = i - 1;

        while (j >= 0 && array[j]>temp){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
        cout << "Printing the array in ascending order after implementing insertion sort :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
int main()
{
    int size, element;
    cout << "Enter the size of array :" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the elements in array :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "The elements are :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertionSort(arr, size);

    return 0;
}