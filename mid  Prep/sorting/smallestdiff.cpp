//Find the smallest difference of elements from an array.
#include <iostream>  // Include the standard input/output library
using namespace std; // Use the standard namespace to avoid prefixing std::

// Function to sort an array using the Selection Sort algorithm
void Sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) { // Outer loop iterates through the array
        int min_Index = i;            // Assume the current index `i` holds the smallest element

        for (int j = i + 1; j < n; ++j) { // Inner loop finds the smallest element in the unsorted portion
            if (arr[j] < arr[min_Index]) { // Compare current element with the assumed smallest
                min_Index = j;             // Update the index of the smallest element
            }
        }

        // Swap the smallest element found with the current element at index `i`
        int temp = arr[i];
        arr[i] = arr[min_Index];
        arr[min_Index] = temp;
    }
}

// Function to find the smallest difference between adjacent elements in an array
int SmallestDifference(int arr[], int n) {
    Sort(arr, n); // Sort the array in ascending order

    // Initialize the minimum difference to the difference between the first two elements
    int min_Diff = arr[1] - arr[0];

    // Iterate through the array to calculate differences between adjacent elements
    for (int i = 2; i < n; ++i) {
        int diff = arr[i] - arr[i - 1]; // Calculate the difference between current and previous element

        if (diff < min_Diff) { // Update the minimum difference if a smaller difference is found
            min_Diff = diff;
        }
    }

    return min_Diff; // Return the smallest difference found
}

// Main function to test the SmallestDifference function
int main() {
    int arr1[] = {15, 7, 2, 12, 13};          // Initialize the array with test values
    int n1 = sizeof(arr1) / sizeof(arr1[0]);  // Calculate the size of the array

    // Call the SmallestDifference function and print the resul
