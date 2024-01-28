#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_of_three(int a, int b, int c) {
    return max(max(a, b), c);
}

int max_crossing_sum(const vector<int>& arr, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int max_subarray_sum(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;

    int left_sum = max_subarray_sum(arr, low, mid);
    int right_sum = max_subarray_sum(arr, mid + 1, high);
    int cross_sum = max_crossing_sum(arr, low, mid, high);
    return max_of_three(left_sum, right_sum, cross_sum);
}

int main() {
    vector<int> arr;
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int w;cin>>w;
        arr.push_back(w);
    }

    int result = max_subarray_sum(arr, 0,q - 1);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}
