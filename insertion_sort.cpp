#include <iostream>
#include <vector>
using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(vector<int>& arr, int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* A utility function to print array of size n */
void printArray(vector<int>& arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver method
int main()
{
    cout<<"Enter Size of array: ";
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

