#include <iostream>
using namespace std;

void merge(int A[], int start, int mid, int end) {
    int p = start, q = mid + 1;
    if (A[mid] <= A[q]) {
        return;  
    }
    while (p <= mid && q <= end) {
        if (A[p] <= A[q]) {
            p++;
        } else {
            int temp = A[q];

            for (int i = q; i > p; i--) {
                A[i] = A[i - 1];
            }

            A[p] = temp;
            p++;
            mid++;
            q++;
        }
    }
}

void mergeSort(int A[], int start, int end) {
    if (start < end) {
        int mid = start +(end-start)/2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    mergeSort(A, 0, n - 1);        // time complexity O(nlog(n))
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
