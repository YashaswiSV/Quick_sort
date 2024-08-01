#include <iostream>
using namespace std;

int partition(int a[], int lower, int upper) {
    int pivot = a[lower];
    int i = lower, j = upper;
    
    while (i < j) {
        while (a[i] <= pivot && i < upper) 
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    swap(a[j], a[lower]);
    return j;
}

void quick_sort(int a[], int lower, int upper) {
    if (lower < upper) {
        int split = partition(a, lower, upper);
        quick_sort(a, lower, split - 1);
        quick_sort(a, split + 1, upper);
    }
}

int main() {
    int ar[7] = {21, 5, 34, 56, 78, 2, 34};
    int n = sizeof(ar) / sizeof(ar[0]);

    quick_sort(ar, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;

    return 0;
}
