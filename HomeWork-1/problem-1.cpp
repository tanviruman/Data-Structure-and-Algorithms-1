#include <iostream>
using namespace std;

int findSmallest(int arr[], int n, int k)
 {

    for (int i = 0; i < k; ++i)
        {
        int min_index = i;

        for (int j = i + 1; j < n; ++j)
            {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
            }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    return arr[k-1];
}

int main()

{
    int arr1[] = {6, 5, 1, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;
    cout << "The " << k1 << "th smallest element is: " << findSmallest(arr1, n1, k1) << endl;
    return 0;
}
