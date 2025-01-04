#include <iostream> // Include the standard input/output library
#include <cmath>    // Include the math library for absolute value function (abs)
using namespace std; // Use the standard namespace to avoid prefixing with std::

// Function to sort an array based on absolute values using Insertion Sort
void Sort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // Outer loop iterates through each element starting from the second element
        int key = arr[i];        // Store the current element as the key
        int j = i - 1;           // Initialize j as the index of the previous element

        // Inner loop: shift elements greater in absolute value to the right
        while (j >= 0 && abs(arr[j]) > abs(key)) {
            arr[j + 1] = arr[j]; // Move the larger element to the right
            j--;                 // Decrement the index to compare the next element
        }

        arr[j + 1] = key; // Insert the key into its correct position
    }
}

// Main function to test the sorting function
int main() {
    int arr[] = {-10, 5, -3, 7, -2};        // Initialize an array with integers (both positive and negative)
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    Sort(arr, n); // Call the sorting function to sort the array based on absolute values

    // Print the sorted array
    cout << "Sorted array by absolute value: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ","; // Output each element followed by a comma
    }
    return 0; // Exit the program
}
