//Bubble sort implemtation using C++
void bubbleSort(int a[], int n) {
    int outer, inner;
    for (outer = 0; outer < n - 1; outer++) {
        for (inner = 0; inner < n - outer - 1; inner++) {
            if (a[inner] > a[inner + 1]) {
                int temp = a[inner];
                a[inner]= a[inner + 1];
                a[inner + 1] = temp;
            }
        }
    }
}