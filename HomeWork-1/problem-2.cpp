#include <iostream>
using namespace std;

void Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        {
        int indexmin = i;
        for (int j = i + 1; j < n; ++j)
         {
            if (arr[j] < arr[indexmin])
            {
                indexmin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexmin];
        arr[indexmin] = temp;
    }
}
int Median(int arr[], int n)
 {
    Sort(arr, n);
    if (n % 2 == 1)
        {
        return arr[n / 2];
    }
    else
        {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }
}

int main() {
    int arr1[] = {5, 2, 1, 4, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Median: " << Median(arr1, n1) << endl;
    return 0;
}
