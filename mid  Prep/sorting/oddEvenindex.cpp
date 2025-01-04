#include <iostream> // Include the standard input-output library
using namespace std; // Use the standard namespace to avoid prefixing with std::

// Function to sort an array in ascending order using insertion sort
void Ascending(int arr[], int size) {
    for (int i = 1; i < size; i++) { // Loop through the array starting from the second element
        int key = arr[i]; // Store the current element as the key
        int j = i - 1; // Initialize the previous index
        while (j >= 0 && arr[j] > key) { // Shift elements greater than the key to the right
            arr[j + 1] = arr[j]; 
            j--; // Move to the previous element
        }
        arr[j + 1] = key; // Insert the key in its correct position
    }
}

// Function to sort an array in descending order using insertion sort
void Descending(int arr[], int size) {
    for (int i = 1; i < size; i++) { // Loop through the array starting from the second element
        int key = arr[i]; // Store the current element as the key
        int j = i - 1; // Initialize the previous index
        while (j >= 0 && arr[j] < key) { // Shift elements smaller than the key to the right
            arr[j + 1] = arr[j];
            j--; // Move to the previous element
        }
        arr[j + 1] = key; // Insert the key in its correct position
    }
}

// Main function
int main() {
    int a[] = {16, 17, 4, 18, 1, 20, 5, 12}; // Initialize the array
    int n = sizeof(a) / sizeof(a[0]); // Calculate the number of elements in the array

    int odd[100], even[100]; // Arrays to store odd-indexed and even-indexed elements
    int oddSize = 0, evenSize = 0; // Variables to keep track of the sizes of the odd and even arrays

    // Separate the array into odd-indexed and even-indexed elements
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) // Check if the index is even
            even[evenSize++] = a[i]; // Add to the even array
        else
            odd[oddSize++] = a[i]; // Add to the odd array
    }

    // Sort the odd-indexed elements in descending order
    Descending(odd, oddSize);

    // Sort the even-indexed elements in ascending order
    Ascending(even, evenSize);

    // Merge the sorted odd and even arrays back into the original array
    int oddIndex = 0, evenIndex = 0; // Initialize indices for odd and even arrays
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) // Check if the index is even
            a[i] = even[evenIndex++]; // Place an even-indexed element
        else
            a[i] = odd[oddIndex++]; // Place an odd-indexed element
    }

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ",  "; // Output each element of the array
    }
    cout << endl;

    return 0; // Exit the program
}
