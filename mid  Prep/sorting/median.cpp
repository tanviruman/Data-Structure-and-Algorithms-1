#include <iostream>  // Include the standard input/output library
using namespace std; // Use the standard namespace

// Function to sort the array using the Selection Sort algorithm
void Sort(int arr[], int n)
{
    // Outer loop iterates through each element except the last one
    for (int i = 0; i < n - 1; ++i)
    {
        int indexmin = i; // Assume the current index as the minimum

        // Inner loop finds the smallest element in the remaining unsorted part of the array
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[indexmin]) // Compare current element with the assumed smallest
            {
                indexmin = j; // Update the index of the smallest element
            }
        }

        // Swap the smallest element found with the current element at index `i`
        int temp = arr[i];
        arr[i] = arr[indexmin];
        arr[indexmin] = temp;
    }
}

// Function to find the median of an array
int Median(int arr[], int n)
{
    Sort(arr, n); // Sort the array to arrange elements in ascending order

    // If the size of the array is odd, return the middle element
    if (n % 2 == 1)
    {
        return arr[n / 2]; // Middle element when indexed from 0
    }
    else // If the size of the array is even, return the average of the two middle elements
    {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }
}

int main()
{
    int arr1[] = {5, 2, 1, 4, 7};              // Initialize an array of integers
    int n1 = sizeof(arr1) / sizeof(arr1[0]);   // Calculate the number of elements in the array

    // Call the Median function and print the result
    cout << "Median: " << Median(arr1, n1) << endl;

    return 0; // Exit the program
}
