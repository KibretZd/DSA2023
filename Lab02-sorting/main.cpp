#include<iostream>
#include"sort.h"
using namespace std;
 

int main()
{
    int arr[] = {21, 23, 12, 8, 22, 21, 45, 33, 11, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nThe array elements before sorting:";
    printArray(arr, n);

    //Call bubble sort to arrange array elements here
    // bubbleSort(arr, n);

    // call selection sort function
    // selectionSort(arr, n);

    // write a statement to call insertion sort function here
    your code here

    cout<<"\nThe array elements after sorting:";
    printArray(arr, n);

    return 0;
}