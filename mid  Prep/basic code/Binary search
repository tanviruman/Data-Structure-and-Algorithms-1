#include <iostream> // Include the input-output stream library for input and output operations
using namespace std; // Use the standard namespace to simplify code syntax

// Function to perform binary search
int binarySearch(int arr[], int n, int target) { 
    int st = 0, en = n - 1; // Initialize the start (`st`) and end (`en`) indices

    // Perform binary search until the range is valid (start <= end)
    while (st <= en) { 
        int mid = st + (en - st) / 2; // Calculate the middle index to avoid overflow

        if (arr[mid] == target) // Check if the middle element is the target
            return mid; // If found, return the index of the middle element
        else if (arr[mid] < target) // If the middle element is less than the target
            st = mid + 1; // Narrow the search to the right half of the array
        else // If the middle element is greater than the target
            en = mid - 1; // Narrow the search to the left half of the array
    }

    return -1; // Return -1 if the target is not found in the array
}

int main() { // Entry point of the program
    int n, target; // Declare variables for the size of the array and the target element

    // Prompt the user to enter the size of the array
    cout << "Enter the size of the array: ";
    cin >> n; // Read the size of the array from the user

    int arr[n]; // Declare an array of size `n`
                // Note: Variable-length arrays (VLAs) like `int arr[n]` are not standard in C++.
                // Use `std::vector<int>` for better portability.

    // Prompt the user to input the sorted elements of the array
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) { // Loop to read `n` elements from the user
        cin >> arr[i]; // Store each element in the array
    }

    // Prompt the user to input the target element to search
    cout << "Enter the element to search: ";
    cin >> target; // Read the target element

    // Call the binarySearch function to find the target in the array
    int result = binarySearch(arr, n, target);

    // Check if the target was found
    if (result != -1) 
        cout << "Element found at index " << result << endl; // Output the index if found
    else
        cout << "Element not found." << endl; // Output a message if not found

    return 0; // Indicate successful program termination
}
