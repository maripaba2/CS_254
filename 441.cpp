#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int x=a[0],y=a[1];
    for(int i=2;i<n;i++){
        if(a[i]>x && a[i]>y){
            if(x<y)x=a[i];
            else y=a[i];
        }else if(a[i]>x){
            x=a[i];
        }else if(a[i]>y){
            y=a[i];
        }
    }
    cout<<(x+y);
    return 0;
}