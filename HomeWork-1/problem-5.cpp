#include <iostream>
#include <string>
using namespace std;

void Sort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        {
        int min_Index = i;


        for (int j = i + 1; j < n; j++)
            {
            if (arr[j].length() < arr[min_Index].length())
             {
                min_Index = j;
            }
        }


        if (min_Index != i)
            {
            string temp = arr[i];
            arr[i] = arr[min_Index];
            arr[min_Index] = temp;
        }
    }
}

int main()
{
    string arr[] = {"apple", "bat", "carrot", "dog"};
    int n = sizeof(arr) / sizeof(arr[0]);

    Sort(arr, n);

    cout << "Sorted array by string length: ";
    for (int i = 0; i < n; i++) {
        cout << "\"" << arr[i] << "\" , ";
    }
    return 0;
}
