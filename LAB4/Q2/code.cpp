#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fl(a,b) for(ll i=a;i<b;i++)
#define bl(a,b) for(ll i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class TI>using index = tree<TI, null_type, less<TI>, rb_tree_tag, tree_order_statistics_node_update>;
double findMedianSortedArrays(vector<ll> &nums1, vector<ll> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;
        int low = 0, high = n1;
        
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }
        
        return 0; 
    }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vector <ll> v1,v2;
ll n;cin>>n;
fl(0,n){
    ll q;cin>>q;
    v1.push_back(q);
}
ll m;cin>>m;
fl(0,m){
    ll q;cin>>q;
    v2.push_back(q);
}
double ans=findMedianSortedArrays(v1,v2);
cout<<ans<<endl;
return 0;
}