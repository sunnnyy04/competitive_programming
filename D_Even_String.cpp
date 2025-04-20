#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll MOD = 998244353, N = 5e5 + 1;


vector<ll> fact(N, 1), invfact(N, 1);


ll power(ll a, ll b, ll p) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}


void precompute() {
    for (ll i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[N - 1] = power(fact[N - 1], MOD - 2, MOD);  
    for (ll i = N - 2; i >= 0; i--) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}


ll chose(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return (((fact[n] * invfact[k]) % MOD) * invfact[n - k]) % MOD;
}


ll rec(ll i, ll even, ll odd, vector<ll> &c, vector<vector<ll>> &dp) {
    if (i == 26) return (even == 0 && odd == 0) ? 1 : 0;
    if (dp[i][even] != -1) return dp[i][even];

    if (c[i] == 0) return dp[i][even] = rec(i + 1, even, odd, c, dp);

    ll ans = 0;
    if (even >= c[i])  
        ans = (ans + (chose(even, c[i]) * rec(i + 1, even - c[i], odd, c, dp)) % MOD) % MOD;
    if (odd >= c[i])  
        ans = (ans + (chose(odd, c[i]) * rec(i + 1, even, odd - c[i], c, dp)) % MOD) % MOD;

    return dp[i][even] = ans;
}


void solve() {
    vector<ll> c(26);
    ll n = 0;
    for (auto &i : c) {
        cin >> i;
        n += i;
    }

    vector<vector<ll>> dp(26, vector<ll>(n + 1, -1));
    ll ans = rec(0, (n + 1) / 2, n / 2, c, dp);
    cout << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    precompute();  

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
