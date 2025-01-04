#include <iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace for convenience

int main() {
    int n; // Declare an integer variable to store the number of elements

    // Prompt the user to enter the number of elements
    cout << "Enter the number of elements: ";
    cin >> n; // Take input from the user and store it in variable `n`

    // Declare an array of size `n`
    // Note: Variable-length arrays (VLA) like `int arr[n]` are not standard in C++.
    int arr[n]; 

    // Prompt the user to input the array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read each element and store it in the array
    }

    // Perform Bubble Sort on the array
    // Outer loop controls the number of passes
    for (int i = 0; i < n - 1; i++) {
        // Inner loop performs pairwise comparisons for the current pass
        for (int j = 0; j < n - i - 1; j++) {
            // Swap adjacent elements if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];     // Store the value of `arr[j]` in a temporary variable
                arr[j] = arr[j + 1];  // Move the smaller value to the left
                arr[j + 1] = temp;    // Assign the stored value to the right position
            }
        }
    }

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Output each element of the sorted array
    }
    // cout << endl; // Uncomment if a newline is needed after the sorted array output

    return 0; // Indicate successful program termination
}
