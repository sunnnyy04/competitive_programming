#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    unordered_map<ll,ll> mpp;
    map<pair<ll,ll>,ll> bpp;
    for(ll i=0;i<n;i++) mpp[i+1]=v[i];
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll j=(i+1);
        ll k=(v[i]-j);
        while(k<=n && k>0){
            if(k>0 && mpp.find(k)!=mpp.end() && (j+k)==(v[i]*mpp[k])) {
                ans++;
                bpp[{min(j,k),max(j,k)}]++; 
            }
            k+=v[i];
        }
    }
    // cout<<ans<<endl;
    cout<<bpp.size()<<endl;
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
      