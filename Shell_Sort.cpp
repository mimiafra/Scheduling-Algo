// ShellSort.cpp
// Implementation of Shell Sort Algorithm in C++
// Contributed by Tanya Chaturvedi for Hacktoberfest 2025

#include <iostream>
#include <vector>
using namespace std;

/**
 * Shell Sort Algorithm
 * ---------------------
 * Shell Sort is an in-place comparison-based sorting algorithm.
 * It improves upon Insertion Sort by allowing exchanges of far-apart elements.
 * The interval between compared elements (gap) is gradually reduced until it becomes 1.
 */

void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Start with a large gap, then reduce it
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Shift earlier gap-sorted elements up until correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    shellSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
