int lin_search(int arr[], int n, int sKey){
    for(int i = 0; i < n; i++){
        if(arr[i] == sKey){
            return i;
        }
    }
    return -1;
}

//write an iterative implementation of binary search fiunction
int binary_search(int a[], int n, int sKey){
    int first = 0;
    int last = n - 1;
    while(first <= last){
        int mid = (first + last) / 2;
        if(a[mid] == sKey){
            return mid;
        }
        else if(a[mid] > sKey){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }
    return -1;
}


//recursive implementation of binary search
int bin_search(int a[], int first, int last, int sKey){
    if(first > last){
        return -1;
    }
    int mid = (first + last) / 2;
    if(a[mid] == sKey){
        return mid;
    }
    else if(a[mid] > sKey){
        return bin_search(a, first, mid - 1, sKey);
    }
    else{
        return bin_search(a, mid + 1, last, sKey);
    }
}