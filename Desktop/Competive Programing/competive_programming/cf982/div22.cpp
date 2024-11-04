#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (auto &it : v)cin >> it;
    int ans=n;
    for(int i=0;i<n;i++){
        int res=0;
        for(int j=i+1;j<n;j++){
            if(v[j]>v[i])res++;
        }
        ans=min(ans,res+i);
    }
    cout<<ans<<endl;
 
 
}
 
int main() {
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}