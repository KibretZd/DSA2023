int lin_search(int arr[], int n, int sKey){
    for(int i = 0; i < n; i++){
        if(arr[i] == sKey){
            return i;
        }
    }
    return -1;
}

//write an iterative implementation of binary search fiunction

