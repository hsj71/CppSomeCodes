#include <iostream>
#include <vector>
#include <cstdlib> // For rand() function
using namespace std;
// Function to partition the array (used in deterministic Quick Sort)
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]); // Swap elements
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic Quick Sort function
void quickSortDeterministic(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array
        quickSortDeterministic(arr, low, pi - 1); // Recursively sort elements before partition
        quickSortDeterministic(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

// Function to partition the array with randomized pivot
int randomizedPartition(vector<int>& arr, int low, int high) {
      int randomPivot = low + rand() % (high - low + 1); // Select a random pivot
    swap(arr[randomPivot], arr[high]); // Swap random pivot with the last element
    return partition(arr, low, high); // Use regular partition
}

// Randomized Quick Sort function
void quickSortRandomized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high); // Partition the array with random pivot
        quickSortRandomized(arr, low, pi - 1); // Recursively sort elements before partition
        quickSortRandomized(arr, pi + 1, high); // Recursively sort elements after partition
    }
}
int main() {
    int n;
    // User input for array size
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr1(n);
    // User input for array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    // Create a copy of the original array for the randomized quick sort test
    vector<int> arr2 = arr1;

    cout << "\nOriginal array: ";
    for (int val : arr1) {
        cout << val << " ";
    }
    cout << endl;

    // Deterministic Quick Sort
    quickSortDeterministic(arr1, 0, n - 1);
    cout << "Sorted array using Deterministic Quick Sort: ";
    for (int val : arr1) {
    cout << val << " ";
    }
    cout << endl;
    // Randomized Quick Sort
    quickSortRandomized(arr2, 0, n - 1);
    cout << "Sorted array using Randomized Quick Sort: ";
    for (int val : arr2) {
    cout << val << " ";
    }
    cout << endl;
    return 0;
    }
