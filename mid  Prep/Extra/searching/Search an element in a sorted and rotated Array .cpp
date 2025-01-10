// C++ program to search an element in sorted and rotated 
// array using binary search twice

#include <iostream>
#include <vector>
using namespace std;

// An iterative binary search function
int binarySearch(vector<int> &arr, int lo, int hi, int x) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// Function to return pivot (index of the smallest element)
int findPivot(vector<int> &arr, int lo, int hi) {
    while (lo < hi) {
      
        // The current subarray is already sorted,
        // the minimum is at the low index
        if (arr[lo] <= arr[hi])        
            return lo;
        
        int mid = (lo + hi) / 2;

        // The right half is not sorted. So
        // the minimum element must be in the
        // right half.
        if (arr[mid] > arr[hi])
            lo = mid + 1;
      
        // The right half is sorted. Note that in
        // this case, we do not change high to mid - 1
        // but keep it to mid. The mid element
        // itself can be the smallest
        else
            hi = mid;
    }

    return lo;
}

// Searches an element key in a pivoted
// sorted array arr of size n
int search(vector<int> &arr, int key) {
      int n = arr.size();
    int pivot = findPivot(arr, 0, n - 1);

    // If we found a pivot, then first compare with pivot
    // and then search in two subarrays around pivot
    if (arr[pivot] == key)
        return pivot;
  
    // If the minimum element is present at index
    // 0, then the whole array is sorted
    if (pivot == 0)
        return binarySearch(arr, 0, n - 1, key);

    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
    return binarySearch(arr, pivot + 1, n - 1, key);
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    cout << search(arr, key);
    return 0;
}