#include <iostream> // Include the input-output stream library for console operations
using namespace std;

int main() {
    // Problem: Given a sorted array, return the index where a target value should be inserted
    // to maintain the order. Use binary search.
    // Example: Input: arr = [1, 3, 5, 6], target = 4
    // Output: 2

    // Declare the sorted input array
    int arr[] = {1, 3, 5, 6}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Declare the target value to be inserted
    int target = 4; // Target value

    // Initialize binary search boundaries
    int left = 0;             // Left boundary of the search range
    int right = size - 1;     // Right boundary of the search range
    int result = size;        // Default insertion index (if target is greater than all elements)

    // Binary search loop
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index to avoid overflow

        if (arr[mid] >= target) { // If the middle element is greater than or equal to the target
            result = mid;         // Update the result to the current index
            right = mid - 1;      // Narrow the search to the left half
        } else {                  // If the middle element is less than the target
            left = mid + 1;       // Narrow the search to the right half
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
    cout << "Output: " << result << endl; // Print the index where the target should be inserted

    return 0; // End of the program
}
