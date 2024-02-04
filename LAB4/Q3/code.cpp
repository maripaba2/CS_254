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

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        
        return min_heap.top();
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
vector <int> v1,v2;
int n,k;cin>>n>>k;
fl(0,n){
    int q;cin>>q;
    v1.push_back(q);
}
int ans=findKthLargest(v1,k);
cout<<ans<<endl;
return 0;
}