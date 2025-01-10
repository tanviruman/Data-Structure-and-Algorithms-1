// C++ code for the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find and print missing 
// elements in the given range
void findMissing(int arr[], int n, int low, int high) {
    // Loop through the range of numbers from low to high
    for (int i = low; i <= high; i++) {
        bool found = false;
      
        // Loop through the array to check if i exists in it
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
      
        // If i is not found in the array, print it
        if (!found) {
            cout << i << " ";
        }
    }
}

// Driver's code
int main() {
      // Input array
    int arr[] = { 1, 3, 5, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 1, high = 10;
  
      // Function call
    findMissing(arr, n, low, high);
    return 0;
}