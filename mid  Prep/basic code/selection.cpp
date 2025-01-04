#include <iostream> // Include the input-output stream library for handling input and output
using namespace std; // Use the standard namespace to simplify syntax (e.g., avoid `std::cout`)

// Function to perform selection sort
void selectionSort(int arr[], int n) { // Takes an array and its size as input
    // Outer loop to iterate over each element in the array (excluding the last element)
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current element at index `i` is the smallest

        // Inner loop to find the smallest element in the unsorted portion of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) { // Compare the current element with the smallest so far
                minIndex = j; // Update `minIndex` if a smaller element is found
            }
        }

        // Swap the current element with the smallest element if needed
        if (minIndex != i) { // Check if the smallest element is not already in the correct position
            int temp = arr[i];     // Store the current element in a temporary variable
            arr[i] = arr[minIndex]; // Move the smallest element to its correct position
            arr[minIndex] = temp;   // Place the original element at the `minIndex`
        }
    }
}

// Function to print the elements of the array
void printArray(int arr[], int n) { // Takes an array and its size as input
    for (int i = 0; i < n; i++) { // Loop through all elements in the array
        cout << arr[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Print a newline for better formatting
}

// Main function - entry point of the program
int main() {
    int n; // Declare an integer variable to store the number of elements

    // Prompt the user to enter the number of elements
    cout << "Enter the number of elements: ";
    cin >> n; // Read the number of elements and store it in `n`

    int arr[n]; // Declare an array of size `n` to store the elements
                // Note: Variable-length arrays (VLAs) like `int arr[n]` are not standard in C++.
                // For better portability, use `std::vector<int>`.

    // Prompt the user to input the elements of the array
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) { // Loop to read `n` elements from the user
        cin >> arr[i]; // Store each element in the array
    }

    // Call the `selectionSort` function to sort the array
    selectionSort(arr, n);

    // Display the sorted array
    cout << "Sorted array: ";
    printArray(arr, n); // Call the `printArray` function to print the sorted elements

    return 0; // Indicate successful program termination
}
