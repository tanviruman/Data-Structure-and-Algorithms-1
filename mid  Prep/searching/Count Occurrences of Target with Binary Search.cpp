// Problem: In a sorted array, count the occurrences of a target value using binary search.
// Example: Input: arr = [2, 4, 4, 4, 6, 7], target = 4
// Output: 3

#include <iostream>
using namespace std;

// Function to find the first occurrence of the target value
int findFirst(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    int first = -1; // To store the index of the first occurrence

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] == target) {
            first = mid;    // Update first occurrence
            high = mid - 1; // Search in the left half
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return first; // Return the index of the first occurrence
}

// Function to find the last occurrence of the target value
int findLast(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    int last = -1; // To store the index of the last occurrence

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        if (arr[mid] == target) {
            last = mid;     // Update last occurrence
            low = mid + 1;  // Search in the right half
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return last; // Return the index of the last occurrence
}

// Function to count the occurrences of the target value
int countOccurrences(int arr[], int size, int target) {
    int first = findFirst(arr, size, target);
    int last = findLast(arr, size, target);

    if (first == -1 || last == -1) {
        return 0; // Target value not found in the array
    }

    return last - first + 1; // Calculate the count of occurrences
}

int main() {
    // Input array and target value
    int arr[] = {2, 4, 4, 4, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    // Call the function to count occurrences
    int count = countOccurrences(arr, size, target);

    // Output the result
    cout << "The target value " << target << " occurs " << count << " times in the array." << endl;

    return 0;
}
