#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> merge_sorted_arrays(const vector<int>& A, const vector<int>& B) {
    int m = A.size();
    int n = B.size();
    vector<int> C; 
    int i = 0, j = 0;

    // Compare elements from A and B, and insert the smaller one into C
    while (i < m && j < n) {
        if (A[i] == B[j]) {
            if(C.size()==0 || C[C.size()-1]!=A[i])C.push_back(A[i]);
            i++;
            j++;
        } else {
            if(A[i]<B[j])i++;
            else j++;
        }
    }

    return C;
}

int main() {
    vector<int> A,B;
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int q;cin>>q;
        A.push_back(q);
    } 
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int q;cin>>q;
        B.push_back(q);
    } 
    vector<int> result = merge_sorted_arrays(A, B);  // time complexity O(m+n)

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
