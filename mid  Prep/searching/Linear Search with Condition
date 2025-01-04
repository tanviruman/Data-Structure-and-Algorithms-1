#include <iostream> // Include the input-output stream library for console operations
using namespace std;

int main() {
    // Problem: Find the first element in an array of integers that is greater than a given target.
    // If no such element exists, return -1.
    // Example: Input: arr = [3, 5, 7, 2, 8, 10], target = 6
    // Output: 7

    // Declare the input array
    int arr[] = {3, 5, 7, 2, 8, 10}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Declare the target integer
    int target = 6; // The target value to compare

    // Variable to store the result
    int result = -1; // Initialize to -1 (default value if no element is greater than the target)

    // Linear search to find the first element greater than the target
    for (int i = 0; i < size; i++) {
        if (arr[i] > target) { // Check if the current element is greater than the target
            result = arr[i]; // Store the first element that meets the condition
            break; // Exit the loop after finding the first match
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
        cout << "Output: " << result << endl; // Print the first element greater than the target
    } else {
        cout << "Output: -1" << endl; // Print -1 if no such element exists
    }

    return 0; // End of the program
}
