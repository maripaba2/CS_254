#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n;cin>> n;

    vector<int> a;
    for (int i = 0; i < n; i++){
        int q;cin>>q;
        a.push_back(q);
    }

    // Find the two smallest elements in O(n)
    int x = a[0], y = a[1];
    for (int i = 2; i < n; i++) {
        if (a[i] < x && a[i] < y) {
            if (x < y)
                x = a[i];
            else
                y = a[i];
        } else if (a[i] < x) {
            x = a[i];
        } else if (a[i] < y) {
            y = a[i];
        }
    }

   
    cout<<min(x,y)<<" "<<max(x,y)<<endl;

    return 0;
}
