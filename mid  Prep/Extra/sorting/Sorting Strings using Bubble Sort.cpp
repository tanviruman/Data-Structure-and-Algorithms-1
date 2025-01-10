// C++ implementation

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

void sortStrings(char arr[][MAX], int n)
{
	char temp[MAX];

	// Sorting strings using bubble sort
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (strcmp(arr[j], arr[j + 1]) > 0) {
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}
}

int main()
{
	char arr[][MAX] = { "GeeksforGeeks", "Quiz", "Practice",
						"Gblogs", "Coding" };
	int n = sizeof(arr) / sizeof(arr[0]);

	sortStrings(arr, n);

	printf("Strings in sorted order are : ");
	for (int i = 0; i < n; i++)
		printf("\n String %d is %s", i + 1, arr[i]);
	return 0;
}
