// Bubble sort implemtation using C++
#include <iostream>
using namespace std;
void printArray(int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int a[], int n)
{
    int outer, inner;
    for (outer = 0; outer < n - 1; outer++)
    {
        for (inner = 0; inner < n - outer - 1; inner++)
        {
            if (a[inner] > a[inner + 1])
            {
                int temp = a[inner];
                a[inner] = a[inner + 1];
                a[inner + 1] = temp;
            }
        }
        // Uncomment the following line to print the array after each pass
        // printArray(a, n);
    }
}

void selectionSort(int arr[], int n)
{
    int outer, inner, min_idx;
    for (outer = 0; outer < n; outer++)
    {
        min_idx = outer;
        for (inner = outer + 1; inner < n; inner++)
        {
            if (arr[inner] < arr[min_idx])
                min_idx = inner;
        }
        int temp = arr[outer];
        arr[outer] = arr[min_idx];
        arr[min_idx] = temp;
        // Uncomment the following line to print the array after each pass
        // printArray(arr, n);
    }
}

//write insertion sort function here