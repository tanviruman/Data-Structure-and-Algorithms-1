#include <iostream> // Include the input-output stream library for handling input and output
using namespace std; // Use the standard namespace to avoid prefixing standard library names with 'std::'

int main() { // Entry point of the program
    int n; // Declare an integer variable to store the number of elements

    // Prompt the user to enter the number of elements
    cout << "Enter the number of elements: ";
    cin >> n; // Read the number of elements and store it in the variable `n`

    int arr[n]; // Declare an array of size `n` to store the elements
                // Note: Variable-length arrays (VLAs) like this are not standard in C++.
                // Consider using `std::vector<int>` for portability.

    // Prompt the user to input the array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) { // Loop to read each element
        cin >> arr[i]; // Store the input value in the array at index `i`
    }

    // Perform Insertion Sort on the array
    for (int i = 1; i < n; i++) { // Start from the second element (index 1)
        int key = arr[i]; // Store the current element in `key`
        int j = i - 1; // Initialize `j` to the index of the previous element

        // Move elements of `arr[0..i-1]` that are greater than `key` one position ahead
        while (j >= 0 && arr[j] > key) { // Continue as long as `j` is valid and `arr[j] > key`
            arr[j + 1] = arr[j]; // Shift `arr[j]` one position to the right
            j = j - 1; // Decrement `j` to check the next element on the left
        }
        arr[j + 1] = key; // Place the `key` in its correct position
    }

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) { // Loop through the sorted array
        cout << arr[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Print a newline for better formatting

    return main(); // Recursively call `main()`
                   // Note: This creates an infinite recursion, which is generally not a valid practice.
                   // Use `return 0;` instead to end the program properly.
}
