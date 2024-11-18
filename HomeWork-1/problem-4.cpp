#include <iostream>
#include <cmath>

void Sort(int arr[], int n)
 {
    for (int i = 1; i < n; i++)
        {
        int key = arr[i];
        int j = i - 1;



        while (j >= 0 && std::abs(arr[j]) > std::abs(key))
            {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
 {
    int arr[] = {-10, 5, -3, 7, -2};
    int n = sizeof(arr) / sizeof(arr[0]);

   Sort(arr, n);

    std::cout << "Sorted array by absolute value: ";
    for (int i = 0; i < n; i++)
        {
        std::cout << arr[i] << ",";
    }
    return 0;
}
