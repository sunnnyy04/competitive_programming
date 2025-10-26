#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())
#define loop(i,a,b) for(int i=(a); i<(b); i++)
#define nl '\n'

const ll MOD = 1e9+7;
const ll INF = 1e15;

template<typename T> inline void amin(T &a, T b) { if(b < a) a = b; }
template<typename T> inline void amax(T &a, T b) { if(b > a) a = b; }

ll modmul(ll a, ll b, ll m=MOD) { return (a % m * b % m) % m; }
ll modadd(ll a, ll b, ll m=MOD) { return (a % m + b % m) % m; }
ll modsub(ll a, ll b, ll m=MOD) { return (a % m - b % m + m) % m; }

ll expo(ll a, ll n, ll m=MOD) {
    ll res = 1;
    while(n) {
        if(n & 1) res = modmul(res, a, m);
        a = modmul(a, a, m);
        n >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    loop(i,0,n) cin>>a[i];
    vector<int>ans(n);
    ans[0]=1;
    int b=2;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]+(i+1)){
            ans[i]=b;
            b++;
        }
        else{
            ans[i]=ans[a[i-1]+(i+1)-a[i]-1];
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();
    return 0;
}