#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------//
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pii;

#define ll long long
#define all(a) a.begin(), a.end()
#define loop(i, a, b) for (int i = a; i < b; i++)

//--------------------------------------------------------------//
const long long MOD = 998244353;
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}


ll modInverse(ll x, ll mod) {
    return power(x, mod - 2, mod);
}


ll nCrMod(ll n, ll r, ll mod) {
    if (r > n) return 0; 
    if (r > n - r) r = n - r; 

    ll num = 1, den = 1;
    for (ll i = 0; i < r; i++) {
        num = (num * (n - i)) % mod;
        den = (den * (i + 1)) % mod;
    }
    return (num * modInverse(den, mod)) % mod;
}
//--------------------------------------------------------------//
void solve() {
    int n;
    cin >> n;
    ll r=1;
    ll ans =nCrMod(n/3,n/6,MOD);
    loop(i, 0, n / 3) {
        vi a(3);
        cin >> a[0] >> a[1] >> a[2];
        int x = *min_element(all(a));
        int cnt = count(all(a), x);
        ans = (ans * cnt) % MOD;
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}