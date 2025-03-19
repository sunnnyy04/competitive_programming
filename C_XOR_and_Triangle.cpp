#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define ff first 
#define ss second
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pair<ll,ll>>
#define mll map<ll,ll> 
#define mcl map<char,ll>
#define nline "\n"

void solve() {
    ll x;
    cin>>x;
    if((x & (x-1))==0 || (x&(x+1))==0) cout<<-1<<nline;
    else{
        ll a=__builtin_ctz(x);
        ll b=0;
        while((x&(1<<b))!=0){
            b++;
        }
        cout<<a<<" "<<b<<" ";
        ll y=(1<<a)|(1<<b);
        cout<<y<<nline;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
