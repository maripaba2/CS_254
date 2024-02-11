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

int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size(), lbl = 1;
    vector<pair<int, int>> cells(n*n+1);
    vector<int> columns(n);
    iota(columns.begin(), columns.end(), 0);
    for (int row = n - 1; row >= 0; row--) {
        for (int column : columns) {
            cells[lbl++] = {row, column};
        }
        reverse(columns.begin(), columns.end());
    }
    vector<int> dist(n*n+1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
            auto [row, column] = cells[next];
            int destination = board[row][column] != -1 ? board[row][column] : next;
            if (dist[destination] == -1) {
                dist[destination] = dist[curr] + 1;
                q.push(destination);
            }
        }
    }
    return dist[n*n];
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;cin>>n;
vector<vector<int>> board;
fl(0,n,i){
    vector<int> v;
    fl(0,n,j){
        int q;cin>>q;
        v.push_back(q);
    }
    board.push_back(v);
}
int ans=snakesAndLadders(board);
cout<<ans<<endl;
return 0;
}