#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll,ll> mpp;
    for(ll i = 0;i<n;i++){
        cin>>v[i];
        mpp[v[i]]++;
    }
    bool can = true;
    for(auto& it:mpp){
        if(it.second==1){
            can = false;
            break;
        }
    }
    if(can){
        cout<<0<<endl;
        return;
    }
    ll l = 0, r = 0;
    for(ll i = 0;i<n;i++){
        if(mpp[v[i]]==1){
            l = i;
            r = i;
            break;
        }
    }
    
    ll ansl = l, ansr = l;
    while(r<n){
        if((r<n) && mpp[v[r]]==1) r++;
        else {
            if((r-l+1)>(ansr-ansl+1)){
                ansr = r;
                ansl = l;
            }
            l = r+1;
            r = l;
        }
    }
    if((r-l+1)>(ansr-ansl+1)){
        ansr = r;
        ansl = l;
    }
    cout<<(ansl+1)<<" "<<(ansr+1)<<endl;
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}