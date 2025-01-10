#include <iostream>
using namespace std;



void Bubble_Sort(int num[], int n)
{
    for (int i = 0; i < n - 1; i++)
        {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (num[j] > num[j + 1])
            {
                int temp = num[j];
                num[j] = num[j + 1];

                num[j + 1] = temp;
            }
        }
    }
}


int Missing(int num[], int n)
 {
    Bubble_Sort(num, n);
    int missing = 0;
    for (int i = 0; i < n; i++)
        {
        if (num[i] == missing)
        {
            missing++;
        }
    else if (num[i] > missing)
        {
            break;
        }
    }
    return missing;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";

    cin >> n;

    int num[n];

cout << "Enter " << n << " non-negative integers:\n";

    for (int i = 0; i < n; i++)
        {
        cin >> num[i];
    }


    int result = Missing(num, n);


    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
        {
        cout << num[i] << " ";
    }
    cout << endl;

    cout << "Smallest missing element: " << result << endl;

    return 0;
}
