#include <iostream> // Include the input-output stream library for console operations
using namespace std;

int main() {
    // Problem: Given an array of integers, find the first occurrence of a target integer.
    // If the target is not in the array, return -1.
    // Example: Input: arr = [5, 3, 8, 1, 9], target = 8
    // Output: 2

    // Declare the array
    int arr[] = {5, 3, 8, 1, 9}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Declare the target integer
    int target = 8; // The integer we are searching for

    // Variable to store the index of the first occurrence of the target
    int result = -1; // Initialize to -1 (default value if the target is not found)

    // Linear search through the array
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) { // Check if the current element matches the target
            result = i; // Store the index of the first occurrence
            break; // Exit the loop once the target is found
        }
    }

    // Output the input array
    cout << "Input array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Print each element in the array
    }
    cout << endl;

    // Output the target
    cout << "Target: " << target << endl;

    // Output the result
    if (result != -1) {
        cout << "Output: " << result << endl; // Print the index if the target is found
    } else {
        cout << "Output: -1" << endl; // Print -1 if the target is not found
    }

    return 0; // End of the program
}
