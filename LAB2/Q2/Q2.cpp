#include <iostream>

void inPlaceMerge(int A[], int m, int n) {
    int i = 0;
    int j = m;
    int k = 0;

    while (i < m && j < n + m) {
        if (A[i] <= A[j]) {
            A[k] = A[i];
            i++;
        } else {
            A[k] = A[j];
            j++;
        }
        k++;
    }

    while (i < m) {
        A[k] = A[i];
        i++;
        k++;
    }

    while (j < n + m) {
        A[k] = A[j];
        j++;
        k++;
    }
}

int main() {
    int m,n;cin>>m>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    
    inPlaceMerge(A, m, n);

    for (int i = 0; i < m + n; i++) {
        std::cout << A[i] << " ";
    }

    return 0;
}
