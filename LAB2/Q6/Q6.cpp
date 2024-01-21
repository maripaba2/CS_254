#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int middle = low + (high - low) / 2;

    if (arr[middle] < arr[low]) {
        swap(arr[middle], arr[low]);
    }
    if (arr[high] < arr[low]) {
        swap(arr[high], arr[low]);
    }
    if (arr[high] < arr[middle]) {
        swap(arr[high], arr[middle]);
    }

    int pivot = arr[middle];
    swap(arr[middle], arr[high - 1]); 

    int i = low;
    int j = high - 1;

    while (true) {
        while (arr[++i] < pivot)
            ;
        while (pivot < arr[--j])
            ;

        if (i < j) {
            swap(arr[i], arr[j]);
        } else {
            break;
        }
    }
    swap(arr[i], arr[high - 1]);

    return i;
}
void quickSort(vector<int>& arr, int low, int high) {
    while (low < high) {
        if (high - low > 10) {
            int pivotIndex = partition(arr, low, high);
            if (pivotIndex - low < high - pivotIndex) {
                quickSort(arr, low, pivotIndex - 1);
                low = pivotIndex + 1;
            } else {
                quickSort(arr, pivotIndex + 1, high);
                high = pivotIndex - 1;
            }
        } else {
            int pivotIndex = partition(arr, low, high);
            if (pivotIndex - low < high - pivotIndex) {
                quickSort(arr, low, pivotIndex - 1);
                low = pivotIndex + 1;
            } else {
                quickSort(arr, pivotIndex + 1, high);
                high = pivotIndex - 1;
            }
        }
    }
}
void quickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> a;
    int n;cin>>n;
    for (int i=0;i<n;i++) {
        int q;cin>>q;
        a.push_back(q);
    }
    quickSort(a);
    for (int it : a) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
