#include <iostream>
using namespace std;
int Duration(int start, int end)
 {
    return end - start;
}
void Sort(int tasks[][2], int n)
 {
    for (int i = 1; i < n; i++)
        {
        int keyStart = tasks[i][0];
        int keyEnd = tasks[i][1];
        int keyDuration = Duration(keyStart, keyEnd);
        int j = i - 1;


        while (j >= 0 && Duration(tasks[j][0], tasks[j][1]) > keyDuration)
            {
            tasks[j + 1][0] = tasks[j][0];
            tasks[j + 1][1] = tasks[j][1];
            j--;
        }
        tasks[j + 1][0] = keyStart;
        tasks[j + 1][1] = keyEnd;
    }
}

int main()
 {

    int tasks[3][2] = {{2, 5}, {1, 3}, {4, 6}};
    int n = 3;
    Sort(tasks, n);
    cout << "Sorted tasks: ";

    for (int i = 0; i < n; i++)
        {
        cout << "(" << tasks[i][0] << ", " << tasks[i][1] << ") ";
    }
    cout << endl;

    return 0;
}
