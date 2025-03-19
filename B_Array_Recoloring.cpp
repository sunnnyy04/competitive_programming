#include <bits/stdc++.h>
using namespace std;
#define ll long long

// =============== !!! ~ ~ ~ Code Starts Here ~ ~ ~ !!! ===============
void solve() {
    int n,k;
    cin>>n>>k;
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll res=INT_MIN;
    if(k==1){
        for(int i=0;i<n-1;i++){
            res=max(b[n-1]+b[i],res);
        }
        for(int i=1;i<n;i++){
            res=max(b[0]+b[i],res);
        }
        cout<<res<<endl;
    }
    else{
        res=0;
        sort(b.rbegin(),b.rend());
        for(int i=0;i<=k;i++){
            res+=b[i];
        }
        cout<<res<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}