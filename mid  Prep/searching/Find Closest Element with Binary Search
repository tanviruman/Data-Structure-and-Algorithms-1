// Problem: Given a sorted array, find the element closest to a given target.
// If two elements are equally close, return the smaller one.
// Example: Input: arr = [1, 3, 8, 10, 15], target = 12
// Output: 10

#include <iostream>
#include <cmath> // For abs function
using namespace std;

// Function to find the element closest to the target
int findClosest(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    int closest = arr[0]; // Initialize the closest element with the first element

    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        // Check if the current mid element is closer to the target
        if (abs(arr[mid] - target) < abs(closest - target) || 
            (abs(arr[mid] - target) == abs(closest - target) && arr[mid] < closest)) {
            closest = arr[mid]; // Update the closest element
        }

        // Adjust the search range based on the target
        if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return closest; // Return the closest element
}

int main() {
    // Input array and target value
    int arr[] = {1, 3, 8, 10, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    // Call the function to find the closest element
    int closest = findClosest(arr, size, target);

    // Output the result
    cout << "The element closest to " << target << " is " << closest << "." << endl;

    return 0;
}
