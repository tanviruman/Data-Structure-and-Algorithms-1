#include <iostream> // Include the standard input/output library
#include <string>   // Include the string library for handling string operations
using namespace std; // Use the standard namespace to avoid prefixing with std::

// Function to sort an array of strings based on their lengths
void Sort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Outer loop iterates through each element except the last
        int min_Index = i; // Assume the current element is the smallest (shortest string)

        // Inner loop to find the smallest string (by length) in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j].length() < arr[min_Index].length()) { // Compare lengths of strings
                min_Index = j; // Update the index of the smallest string
            }
        }

        // Swap the current element with the smallest element if needed
        if (min_Index != i) { // Check if a smaller string was found
            string temp = arr[i]; // Temporary variable to hold the current string
            arr[i] = arr[min_Index]; // Place the smallest string at the current position
            arr[min_Index] = temp; // Restore the current string to the smallest string's position
        }
    }
}

// Main function to test the sorting function
int main() {
    string arr[] = {"apple", "bat", "carrot", "dog"}; // Initialize an array of strings
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    Sort(arr, n); // Call the Sort function to sort the array by string lengths

    // Print the sorted array
    cout << "Sorted array by string length: ";
    for (int i = 0; i < n; i++) { // Iterate through the sorted array
        cout << "\"" << arr[i] << "\" , "; // Output each string enclosed in double quotes
    }
    return 0; // Exit the program
}
