//Find the Longest Consecutive Subsequence after sorting an array.
#include <iostream> // Include the standard input-output library
using namespace std; // Use the standard namespace to avoid prefixing with std::

// Function to sort an array in ascending order using insertion sort
void Sort(int arr[], int n) {
    for (int i = 1; i < n; i++) { // Loop through the array starting from the second element
        int key = arr[i]; // Store the current element as the key
        int j = i - 1; // Initialize the previous index
        while (j >= 0 && arr[j] > key) { // Shift elements greater than the key to the right
            arr[j + 1] = arr[j]; 
            j--; // Move to the previous element
        }
        arr[j + 1] = key; // Insert the key in its correct position
    }
}

// Function to find the length of the Longest Consecutive Subsequence (LCS)
int LCS(int arr[], int n) {
    Sort(arr, n); // Sort the array in ascending order

    int max_Len = 1; // Variable to store the maximum length of consecutive subsequence
    int current_Len = 1; // Variable to track the current consecutive subsequence length

    for (int i = 1; i < n; i++) { // Traverse the sorted array
        if (arr[i] == arr[i - 1]) {
            continue; // Skip duplicate elements
        } else if (arr[i] == arr[i - 1] + 1) {
            current_Len++; // Increment the current subsequence length if elements are consecutive
        } else {
            max_Len = max(max_Len, current_Len); // Update the maximum length if needed
            current_Len = 1; // Reset the current length as the sequence breaks
        }
    }

    return max(max_Len, current_Len); // Return the maximum of max_Len and current_Len
}

int main() {
    int arr[] = {1, 9, 3, 10, 4, 20, 2}; // Initialize the input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    int result = LCS(arr, n); // Call the LCS function to find the longest consecutive subsequence
    cout << "Longest Consecutive Subsequence Length: " << result << endl; // Output the result

    return 0; // Exit the program
}
