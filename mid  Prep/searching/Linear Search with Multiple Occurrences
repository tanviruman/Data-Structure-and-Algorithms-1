#include <iostream> // Include the input-output stream library for console operations
using namespace std;

int main() {
    // Problem: Given an array, find all the indices where a target integer appears.
    // Return an array of indices. If the target does not appear, return an empty array.
    // Example: Input: arr = [4, 2, 3, 2, 4, 2], target = 2
    // Output: [1, 3, 5]

    // Declare the input array
    int arr[] = {4, 2, 3, 2, 4, 2}; // Input array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Declare the target integer
    int target = 2; // The integer we are searching for

    // Declare an array to store the indices of occurrences
    int indices[100]; // Fixed-size array (assume maximum 100 occurrences for simplicity)
    int count = 0; // Variable to keep track of the number of occurrences

    // Linear search to find all indices where the target appears
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) { // Check if the current element matches the target
            indices[count] = i; // Store the index in the `indices` array
            count++; // Increment the count of occurrences
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

    // Output the indices of occurrences
    cout << "Output: [";
    if (count > 0) { // Check if there are any occurrences
        for (int i = 0; i < count; i++) {
            cout << indices[i]; // Print each index
            if (i != count - 1) {
                cout << ", "; // Add a comma between indices
            }
        }
    }
    cout << "]" << endl;

    return 0; // End of the program
}
