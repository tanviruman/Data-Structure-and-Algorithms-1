#include <iostream>

using namespace std;

void SearchPair(int arr[], int N, int X, int Y)

 {
    bool find_x = 0;
    bool find_y = 0;

    for (int i = 0; i < N; i++)
        {
        if (arr[i] == X)
            {
                find_x = 1;
        }

        if (arr[i] == Y)
        {
            find_y = 1;

            }
    }

    if (find_x && find_y)
        {
        cout << "PAIR MATCHED" << endl;
    }

    else if (find_x)
        {
        cout << "ONLY ME (" << X << ")" << endl;
    }


    else if (find_y)
        {
        cout << "ONLY ME (" << Y << ")" << endl;
    }


    else {
        cout << "BETTER LUCK NEXT TIME" << endl;
    }
}

int main()
 {

    int N, X, Y;
    cout << "Enter the size of the array: ";
    cin >> N;

    int arr[N];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++)
        {
        cin >> arr[i];
    }

    cout << "Enter X : ";
    cin >> X ;

    cout << "Enter  Y: ";
    cin  >> Y;

    SearchPair(arr, N, X, Y);

    return 0;
}
