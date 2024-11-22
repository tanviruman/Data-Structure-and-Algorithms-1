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


int LCS(int arr[], int n)
 {
    Sort(arr, n);

    int max_Len = 1;
    int current_Len = 1;

    for (int i = 1; i < n; i++)
        {

        if (arr[i] == arr[i - 1])
        {
            continue;
        }

        else if (arr[i] == arr[i - 1] + 1)
        {
            current_Len++;
        } else {

            max_Len = max(max_Len, current_Len);
            current_Len = 1;
        }
    }

    return max(max_Len, current_Len);
}

int main()
 {
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = LCS(arr, n);
    cout << "Longest Consecutive Subsequence Length: " << result << endl;

    return 0;
}
