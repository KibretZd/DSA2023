#include<iostream>
#include"sort.h"
using namespace std;

void printArray(int c[], int n){
    for(int i = 0; i < n; i++){
        cout << c[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {21, 23, 12, 8, 22, 21, 45, 33, 11, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nThe array elements before sorting:";
    printArray(arr, n);

    //Call bubble sort to arrange array elements here
    bubbleSort(arr, n);

    cout<<"\nThe array elements after sorting:";
    printArray(arr, n);

    return 0;
}