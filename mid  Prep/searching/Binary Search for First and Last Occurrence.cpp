#include <iostream> // Include the input-output stream library for console operations
using namespace std;

int main() {
    // Problem: Given a sorted array, find the first and last positions of a target value.
    // If the target is not found, return (-1, -1).
    // Example: Input: arr = [1, 2, 2, 2, 3, 4], target = 2
    // Output: (1, 3)

    // Declare the sorted input array
    int arr[] = {1, 2, 2, 2, 3, 4}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Declare the target value to search for
    int target = 2; // Target value

    // Initialize variables to store the first and last positions
    int first = -1; // First occurrence of the target
    int last = -1;  // Last occurrence of the target

    // Binary search to find the first occurrence
    int left = 0, right = size - 1; // Initialize the search boundaries
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index
        if (arr[mid] == target) { // If the middle element matches the target
            first = mid;          // Update the first position
            right = mid - 1;      // Narrow the search to the left half to find the first occurrence
        } else if (arr[mid] < target) { // If the target is greater than the middle element
            left = mid + 1;       // Move the left boundary to the right
        } else {                  // If the target is smaller than the middle element
            right = mid - 1;      // Move the right boundary to the left
        }
    }

    // Binary search to find the last occurrence
    left = 0, right = size - 1; // Reinitialize the search boundaries
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index
        if (arr[mid] == target) { // If the middle element matches the target
            last = mid;           // Update the last position
            left = mid + 1;       // Narrow the search to the right half to find the last occurrence
        } else if (arr[mid] < target) { // If the target is greater than the middle element
            left = mid + 1;       // Move the left boundary to the right
        } else {                  // If the target is smaller than the middle element
            right = mid - 1;      // Move the right boundary to the left
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

    // Output the first and last positions
    cout << "Output: (" << first << ", " << last << ")" << endl;

    return 0; // End of the program
}
