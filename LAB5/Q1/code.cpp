#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fl(a,b,i) for(ll i=a;i<b;i++)
#define bl(a,b) for(ll i=a;i>=b;i--)
#define all(v) v.begin(),v.end()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class TI>using index = tree<TI, null_type, less<TI>, rb_tree_tag, tree_order_statistics_node_update>;
ll solve(vector <vector<ll>> &v,vector <vector<ll>> &vis,ll i,ll j,ll n,ll m){	 ll cnt=1;
	if(v[i][j]==0 || vis[i][j])return 0;
	vis[i][j]=1;
	if(i+1<n && v[i+1][j]==1)cnt+=solve(v,vis,i+1,j,n,m);
	if(j+1<m && v[i][j+1]==1)cnt+=solve(v,vis,i,j+1,n,m);
	if(i-1>=0 && v[i-1][j]==1)cnt+=solve(v,vis,i-1,j,n,m);
	if(j-1>=0 && v[i][j-1]==1)cnt+=solve(v,vis,i,j-1,n,m);
	if(j+1<m && i+1<n && v[i+1][j+1]==1)cnt+=solve(v,vis,i+1,j+1,n,m);
	return cnt;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll n,m;cin>>n>>m;
ll ans=0;
vector <vector<ll>> v,vis;
fl(0,n,i){
	vector <ll> r,k;
	fl(0,m,j){
		ll q;cin>>q;
		r.push_back(q);
		k.push_back(0);
	}
	v.push_back(r);
	vis.push_back(k);
}
fl(0,n,i){
	fl(0,m,j){
		if(!vis[i][j] && v[i][j]==1){
			ll cnt=solve(v,vis,i,j,n,m);
			ans=max(ans,cnt);
		}
		vis[i][j]=1;
	}
}
cout<<ans<<endl;

return 0;
}