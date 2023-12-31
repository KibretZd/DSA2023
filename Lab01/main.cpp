// This program demonstrates the simple searching algorithms
//Author: Kibret Zewdu
//Date: December 31, 2023

#include<iostream>
#include"search.h"

using namespace std;

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int searchItem;
    cout<<"\nEnter an item to search: ";
    cin>>searchItem;

    // int location = lin_search(arr, n, searchItem);

    // int location = binary_search(arr, n, searchItem);//Iterative implementation
    int location = bin_search(arr, 0, n-1, searchItem);//recursive implementation

    if(location == -1){
        cout<<searchItem<<" is not found!"<<endl;
    }
    else {
        cout<<searchItem<<" is found at location: "<<location<<endl;
    }
    return 0;

}