// C++ program to implement 3-way Merge Sort
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid1, int mid2, int right) {

    // Sizes of three subarrays
    int size1 = mid1 - left + 1;
    int size2 = mid2 - mid1;
    int size3 = right - mid2;

    // Temporary arrays for three parts
    vector<int> leftArr(size1), midArr(size2), rightArr(size3);

    // Copy data to temporary arrays
    for (int i = 0; i < size1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++) {
        midArr[i] = arr[mid1 + 1 + i];
    }
    for (int i = 0; i < size3; i++) {
        rightArr[i] = arr[mid2 + 1 + i];
    }

    // Merge three sorted subarrays
    int i = 0, j = 0, k = 0, index = left;
    while (i < size1 || j < size2 || k < size3) {
        int minValue = INT_MAX, minIdx = -1;

        // Find the smallest among the three current elements
        if (i < size1 && leftArr[i] < minValue) {
            minValue = leftArr[i];
            minIdx = 0;
        }
        if (j < size2 && midArr[j] < minValue) {
            minValue = midArr[j];
            minIdx = 1;
        }
        if (k < size3 && rightArr[k] < minValue) {
            minValue = rightArr[k];
            minIdx = 2;
        }

        // Place the smallest element in the merged array
        if (minIdx == 0) {
            arr[index++] = leftArr[i++];
        } else if (minIdx == 1) {
            arr[index++] = midArr[j++];
        } else {
            arr[index++] = rightArr[k++];
        }
    }
}

void threeWayMergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid1 = left + (right - left) / 3;
    int mid2 = left + 2 * (right - left) / 3;
    // Recursive calls
    threeWayMergeSort(arr, left, mid1);
    threeWayMergeSort(arr, mid1 + 1, mid2);
    threeWayMergeSort(arr, mid2 + 1, right);
    // Merge the sorted parts
    merge(arr, left, mid1, mid2, right);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    threeWayMergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr;
    return 0;
}
