#include <iostream> // Include the input-output stream library for console operations
using namespace std;

int main() {
    // Problem: Implement binary search in a sorted array to locate a target value.
    // Return the index of the target if found; otherwise, return -1.
    // Example: Input: arr = [1, 3, 5, 7, 9], target = 5
    // Output: 2

    // Declare the sorted input array
    int arr[] = {1, 3, 5, 7, 9}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Declare the target value to search for
    int target = 5; // Target value

    // Initialize variables for binary search
    int left = 0;             // Left boundary of the search range
    int right = size - 1;     // Right boundary of the search range
    int result = -1;          // Result variable to store the index of the target (-1 if not found)

    // Binary search loop
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index to avoid overflow

        if (arr[mid] == target) { // Check if the middle element is the target
            result = mid;         // Store the index of the target
            break;                // Exit the loop as the target is found
        } else if (arr[mid] < target) { // If the target is greater than the middle element
            left = mid + 1;       // Move the left boundary to narrow the search range
        } else {                  // If the target is less than the middle element
            right = mid - 1;      // Move the right boundary to narrow the search range
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
        cout << "Output: " << result << endl; // Print the index of the target if found
    } else {
        cout << "Output: -1" << endl; // Print -1 if the target is not found
    }

    return 0; // End of the program
}
