//You are given two arrays a and b. Merge a and b into a single array sorted in non-decreasing order.
#include <iostream> // Include the input-output library for cin and cout operations
using namespace std;

// Function to sort an array in ascending order using insertion sort
void Sort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // Loop through the array starting from the second element
        int key = arr[i];        // Store the current element as the key
        int j = i - 1;           // Initialize `j` to the previous element index

        // Move elements of `arr[0...i-1]` that are greater than `key` one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift the element one position to the right
            j--;                 // Decrement `j` to check the next element
        }

        arr[j + 1] = key;        // Place the `key` in its correct position
    }
}

int main() {
    // Initialize two separate arrays
    int a[] = {1, 16, 13, 14, 4}; // First array
    int b[] = {15, 12, 5, 3, 7};  // Second array

    // Calculate the sizes of the arrays
    int n1 = sizeof(a) / sizeof(a[0]); // Size of array `a`
    int n2 = sizeof(b) / sizeof(b[0]); // Size of array `b`

    // Initialize a merged array to store elements from both arrays
    int merged[200]; // Assuming a maximum size of 200 for simplicity
    int n = n1 + n2; // Total size of the merged array

    // Copy elements from array `a` into the merged array
    for (int i = 0; i < n1; i++) {
        merged[i] = a[i]; // Copy each element of `a` to the corresponding index in `merged`
    }

    // Copy elements from array `b` into the merged array after `a`'s elements
    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = b[i]; // Copy each element of `b` to the next available index in `merged`
    }

    // Sort the merged array using the `Sort` function
    Sort(merged, n);

    // Print the sorted merged array
    cout << "Sorted merged array: ";
    for (int i = 0; i < n; i++) {
        cout << merged[i] << ",  "; // Print each element followed by a comma and space
    }
    cout << endl; // Add a newline at the end of the output

    return 0; // Indicate successful program execution
}
