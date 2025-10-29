#include <bits/stdc++.h>
using namespace std;

void pigeonholeSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    // Find minimum and maximum values
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    // Create pigeonholes
    vector<vector<int>> holes(range);

    // Put elements into their respective holes
    for (int i = 0; i < n; i++) {
        holes[arr[i] - min_val].push_back(arr[i]);
    }

    // Collect elements back in sorted order
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int val : holes[i]) {
            arr[index++] = val;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
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
    printArray(arr);

    pigeonholeSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}