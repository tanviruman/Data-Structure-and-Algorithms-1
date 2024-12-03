#include <iostream>
using namespace std;

void Bubblesort(int arr,int n){



for(int i=0;i<n-1;i++){

    for (int j=0;j<n-1-i;j++)
    {
        int flag=0;
        if(arr[j]>arr[j+1]){

            int temp =arr[j];
            arr[j]=arr[j+1];
            arr[j+1]= temp;
            flag=1;

        }
if(flag==0)
    break;



    }

}




}




int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);
    return 0;

}
