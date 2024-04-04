#include <iostream>
using namespace std;

void linearSearch(int array[], int size, int element){
    bool found = false;
for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Element not found" << endl;
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
    cout << "Enter the element you want to search :" << endl;
    cin >> element;
    linearSearch(arr, size, element);

    return 0;
}