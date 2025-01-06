// Problem: Given an array where elements increase and then decrease (a ”mountain” array),
// find the index of the peak element using binary search.
// Example: Input: arr = [1, 3, 8, 12, 4, 2]
// Output: 3 (peak element 12 is at index 3)

#include <iostream>
using namespace std;

// Function to find the index of the peak element
int findPeakIndex(int arr[], int size) {
    int low = 0, high = size - 1;

    while (low < high) { // Continue until low and high converge
        int mid = low + (high - low) / 2; // Calculate the middle index

        // Compare the middle element with the next element
        if (arr[mid] < arr[mid + 1]) {
            // If the middle element is smaller, the peak lies in the right half
            low = mid + 1;
        } else {
            // If the middle element is greater, the peak lies in the left half (or it could be the current element)
            high = mid;
        }
    }

    // When low and high converge, they point to the peak element
    return low;
}

int main() {
    // Input array
    int arr[] = {1, 3, 8, 12, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Call the function to find the peak index
    int peakIndex = findPeakIndex(arr, size);

    // Output the result
    cout << "The peak element is at index " << peakIndex << " with value " << arr[peakIndex] << "." << endl;

    return 0;
}
