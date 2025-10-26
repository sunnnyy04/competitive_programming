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
    ll n;
    cin >> n;
    int i=0;
    vector<int>ans;
    if(n==0){
        cout<<"YES"<<endl;
        return;
    }
    if(__builtin_popcountll(n) % 2 == 1){ 
        cout << "NO" << endl;
        return;
    }
    while(i<=30){
        if((1ll<<i)&n){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }
        i++;

    }
    int j=0;
    int k=ans.size();
    while(k>=0){
        if(ans[k]==1){
            break;
        }
        k--;
    }
    while(j<ans.size()){
        if(ans[j]==1){
            break;
        }
        j++;
    }
    while(j<=k){
        if(ans[j]!=ans[k]){
            cout<<"NO"<<endl;
            return;
        }
        j++;
        k--;
    }
    cout<<"YES"<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while(tc--) solve();
    return 0;
}
