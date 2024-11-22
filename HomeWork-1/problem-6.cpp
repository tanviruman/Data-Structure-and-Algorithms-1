#include <iostream>
using namespace std;
void Ascending(int arr[], int size)
 {
    for (int i = 1; i < size; i++)
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

void Descending(int arr[], int size)
{
    for (int i = 1; i < size; i++)
        {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int a[] = {16, 17, 4, 18, 1, 20, 5, 12};
    int n = sizeof(a) / sizeof(a[0]);

    int odd[100], even[100];
    int oddSize = 0, evenSize = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            even[evenSize++] = a[i];
        else
            odd[oddSize++] = a[i];
    }


    Descending(odd, oddSize);

    Ascending(even, evenSize);

    int oddIndex = 0, evenIndex = 0;
    for (int i = 0; i < n; i++)
        {
        if (i % 2 == 0)
            a[i] = even[evenIndex++];
        else
            a[i] = odd[oddIndex++];
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        {
        cout << a[i] << ",  ";
    }
    cout << endl;

    return 0;
}
