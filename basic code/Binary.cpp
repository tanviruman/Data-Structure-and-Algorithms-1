#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int st = 0, en = n - 1;

    while (st <= en) {
        int mid = st + (en - st) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            st = mid + 1;
        else
            en = mid - 1;
    }

    return -1;
}
int main() {
    int n, target;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

