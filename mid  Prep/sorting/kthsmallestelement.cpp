//. Find the kth smallest element from an array.

#include <iostream>  // Include the standard input-output library
using namespace std; // Use the standard namespace

// Function to find the k-th smallest element in the array
int findSmallest(int arr[], int n, int k) {

    // Outer loop runs k times to ensure the first k smallest elements are found
    for (int i = 0; i < k; ++i) {
        int min_index = i; // Assume the current index as the smallest

        // Inner loop to find the smallest element in the remaining unsorted part of the array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) { // Compare current element with the assumed smallest
                min_index = j; // Update the index of the smallest element
            }
        }

        // Swap the smallest element found with the current element at index `i`
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    // Return the k-th smallest element (0-based index, so k-1 for 1-based index)
    return arr[k-1];
}

int main() {
    int arr1[] = {6, 5, 1, 3, 4};            // Initialize an array of integers
    int n1 = sizeof(arr1) / sizeof(arr1[0]); // Calculate the number of elements in the array
    int k1 = 2;                              // Specify the position (k) of the smallest element to find

    // Call the function and display the k-th smallest element
    cout << "The " << k1 << "th smallest element is: " << findSmallest(arr1, n1, k1) << endl;

    return 0; // Exit the program
}
