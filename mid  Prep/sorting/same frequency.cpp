// Sort an array based on the frequency of its elements. 
//If two elements have the same frequency, sort them in ascending order.
#include <iostream> // Include the input-output stream library
using namespace std;

// Function to calculate the frequency of each element in the array
void Frequency(int arr[], int freq[], int n) {
    for (int i = 0; i < n; i++) { // Iterate through the array elements
        freq[i] = 1; // Initialize the frequency of the current element to 1
        for (int j = 0; j < n; j++) { // Compare with all other elements in the array
            if (i != j && arr[i] == arr[j]) { // Check if elements are the same and not comparing the element with itself
                freq[i]++; // Increment the frequency for the current element
            }
        }
    }
}

// Function to sort the array based on frequency and values
void sortByFrequency(int arr[], int freq[], int n) {
    for (int i = 0; i < n - 1; i++) { // Outer loop for the number of passes
        for (int j = 0; j < n - i - 1; j++) { // Inner loop for adjacent comparisons
            // Check if the frequency of the current element is less than the next element
            // Or if frequencies are equal, check if the current element is greater than the next
            if ((freq[j] < freq[j + 1]) || (freq[j] == freq[j + 1] && arr[j] > arr[j + 1])) {
                // Swap the frequencies
                int tempFreq = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = tempFreq;

                // Swap the elements in the array
                int tempElem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempElem;
            }
        }
    }
}

// Main function
int main() {
    int arr[] = {4, 3, 1, 6, 1, 3, 4, 4}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int freq[100]; // Array to store the frequency of each element

    // Calculate the frequency of elements
    Frequency(arr, freq, n);

    // Sort the array based on frequency and element value
    sortByFrequency(arr, freq, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Output each element of the sorted array
    }
    cout << endl;

    return 0; // End the program
}
