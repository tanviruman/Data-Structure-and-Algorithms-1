// A C++ program to check if any two intervals overlap
#include <algorithm>
#include <iostream>
using namespace std;

// An interval has start time and end time
struct Interval {
    int start;
    int end;
};

// Compares two intervals according to their starting time.
// This is needed for sorting the intervals using library
// function std::sort().
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start) ? true : false;
}

// Function to check if any two intervals overlap
bool isIntersect(Interval arr[], int n)
{
    // Sort intervals in increasing order of start time
    sort(arr, arr + n , compareInterval);

    // In the sorted array, if start time of an interval
    // is less than end of previous interval, then there
    // is an overlap
    for (int i = 1; i < n; i++)
        if (arr[i - 1].end > arr[i].start)
            return true;

    // If we reach here, then no overlap
    return false;
}

// Driver program
int main()
{
    Interval arr1[] = { { 1, 3 }, { 7, 9 }, { 4, 6 }, { 10, 13 } };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    isIntersect(arr1, n1) ? cout << "Yes\n" : cout << "No\n";

    Interval arr2[] = { { 6, 8 }, { 1, 3 }, { 2, 4 }, { 4, 7 } };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    isIntersect(arr2, n2) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}