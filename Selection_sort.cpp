// Code for Selection Sort Algorithm in C++

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/*
  Selection Sort (detailed explained implementation)

  Idea:
  - Repeatedly select the smallest (or largest) element from the unsorted
    portion of the array and swap it into the next position of the sorted portion.
  - After i-th iteration, the first i elements are the smallest i elements in sorted order.

  Properties:
  - Time complexity: O(n^2) comparisons in all cases (best/avg/worst).
  - Number of swaps: at most n-1 (one per outer loop iteration if needed).
  - Space complexity: O(1) extra space (in-place).
  - Stability: Not stable by default (equal elements may change relative order).
*/

void selectionSort(vector<int> &a) {
    int n = (int)a.size();

    // Outer loop: iterate over positions where we will place the next
    // smallest element. After iteration i, element at index i is final.
    for (int i = 0; i < n - 1; ++i) {
        // Assume the minimum element is at the current position i.
        int minIndex = i;

        // Find the index of the smallest element in the unsorted portion [i+1 .. n-1].
        // This requires (n-i-1) comparisons for this iteration.
        for (int j = i + 1; j < n; ++j) {
            // If we find a smaller element, update minIndex.
            // Using '<' means if two elements are equal, we do not change minIndex,
            // which contributes to the (lack of) stability.
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        // If the smallest element is not already at position i, swap it into place.
        // Using std::swap is constant-time.
        if (minIndex != i) {
            swap(a[i], a[minIndex]);
        }

        // After this step, a[0..i] are the smallest i+1 elements in sorted order.
    }
}

// Helper to print the array
void printArray(const vector<int> &a) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
}

int main() {
    // Example usage:
    // You can enter custom input: first n, then n integers.
    // Example:
    // 5
    // 64 25 12 22 11
    // Output:
    // Before: 64 25 12 22 11
    // After : 11 12 22 25 64

    cout << "Enter number of elements: ";
    int n;
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid size.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << "Before: ";
    printArray(arr);

    selectionSort(arr);

    cout << "After : ";
    printArray(arr);

    // Quick notes:
    // - Selection sort performs well when memory writes are expensive because it does
    //   at most n-1 swaps (useful on systems where writes are costly).
    // - For large arrays, use O(n log n) algorithms: quicksort, mergesort, heapsort.
    return 0;
}