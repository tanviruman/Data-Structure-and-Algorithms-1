#include <iostream>
using namespace std;

void Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        {
        int min_Index = i;
        for (int j = i + 1; j < n; ++j)
         {
            if (arr[j] < arr[min_Index])
             {
                min_Index = j;
            }
        }

        int temp = arr[i];

        arr[i] = arr[min_Index];
        arr[min_Index] = temp;
    }
}


int SmallestDifference(int arr[], int n)
 {
    Sort(arr, n);
    int min_Diff = arr[1] - arr[0];
    for (int i = 2; i < n; ++i)
        {
        int diff = arr[i] - arr[i - 1];

        if (diff < min_Diff)
         {
            min_Diff = diff;
        }
    }
    return min_Diff;
}

int main() {
    int arr1[] = {15, 7, 2, 12, 13};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Smallest Difference: " << SmallestDifference(arr1, n1) << endl;
    return 0;
}
