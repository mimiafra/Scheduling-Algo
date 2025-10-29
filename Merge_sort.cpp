// Code for Selection Merge Algorithm in C++

#include <iostream>
#include <vector>
using namespace std;

/*
  Merge Sort (detailed explained implementation)

  Idea:
  - Divide the array into two halves, recursively sort each half, then merge the
    two sorted halves into one sorted array.
  - This is a classic divide-and-conquer algorithm.

  Properties:
  - Time complexity: O(n log n) in best/average/worst cases.
  - Space complexity: O(n) auxiliary space (for merging).
  - Stability: Stable (equal elements retain original relative order when merged).
  - Good for large arrays when stable O(n log n) sort is needed.
*/

/* Merge two sorted subarrays a[l..m] and a[m+1..r] into a single sorted range.
   We use a temporary vector to hold merged results, then copy back into a. */
void merge(vector<int> &a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp vectors for left and right halves
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; ++i) left[i] = a[l + i];
    for (int j = 0; j < n2; ++j) right[j] = a[m + 1 + j];

    // Merge left and right back into a[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        // Use '<=' to keep stability: if equal, take from left first.
        if (left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    // Copy any remaining elements
    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];
}

/* Recursive merge sort on a[l..r]. */
void mergeSort(vector<int> &a, int l, int r) {
    if (l >= r) return; // Base case: zero or one element

    int m = l + (r - l) / 2; // Avoid potential overflow
    // Sort first half
    mergeSort(a, l, m);
    // Sort second half
    mergeSort(a, m + 1, r);
    // Merge sorted halves
    merge(a, l, m, r);
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
    // Enter number of elements, then the elements themselves.
    // Example:
    // 5
    // 12 11 13 5 6
    // Output:
    // Before: 12 11 13 5 6
    // After : 5 6 11 12 13

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

    if (n > 0) mergeSort(arr, 0, n - 1);

    cout << "After : ";
    printArray(arr);

    // Notes:
    // - Merge sort requires extra O(n) space. If in-place and stable sorting with
    //   O(n log n) is required, consider alternatives like optimized merges or
    //   using std::stable_sort (introspective stable sort in the standard library).
    return 0;
}