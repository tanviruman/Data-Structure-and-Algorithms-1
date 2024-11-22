#include <iostream>
using namespace std;
void Sort(int arr[], int n)
 {
    for (int i = 1; i < n; i++)
        {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
 {

    int a[] = {1, 16, 13, 14, 4};
    int b[] = {15, 12, 5, 3, 7};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);


    int merged[200];
    int n = n1 + n2;

    for (int i = 0; i < n1; i++)
        {
        merged[i] = a[i];
    }


    for (int i = 0; i < n2; i++)
        {
        merged[n1 + i] = b[i];
    }


    Sort(merged, n);


    cout << "Sorted merged array: ";
    for (int i = 0; i < n; i++) {
        cout << merged[i] << ",  ";
    }
    cout << endl;

    return 0;
}
