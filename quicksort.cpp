#include<bits/stdc++.h>
using namespace std;

vector<int> a;

int partition(int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && a[i] <= pivot) {
            i++;
        }
        while (i <= j && a[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}

void quicksort(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quicksort(low, pivotIndex - 1);
        quicksort(pivotIndex + 1, high);
    }
}

void printing(int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;
    
    cout << "Enter the elements: ";
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quicksort(0, n - 1);
    
    cout << "Sorted array: ";
    printing(n);

    return 0;
}
