#include <iostream>
using namespace std;
void Frequency(int arr[], int freq[], int n)
{
    for (int i = 0; i < n; i++)
        {
        freq[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                freq[i]++;
            }
        }
    }
}
void sortByFrequency(int arr[], int freq[], int n)
 {
    for (int i = 0; i < n - 1; i++)
        {
        for (int j = 0; j < n - i - 1; j++)
         {

            if ((freq[j] < freq[j + 1]) ||(freq[j] == freq[j + 1] && arr[j] > arr[j + 1]))
                {

                int tempFreq = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = tempFreq;

                int tempElem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempElem;
            }
        }
    }
}

int main()
 {
    int arr[] = {4, 3, 1, 6, 1, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int freq[100];
    Frequency(arr, freq, n);
    sortByFrequency(arr, freq, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
