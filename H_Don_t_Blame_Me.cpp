#include <bits/stdc++.h>
using namespace std;

typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;

#define ll long long
#define MOD 1000000007

ll n, k;
vvl dp;
vl a;

ll solve2(int i, int j) {
    if (i == 0) {
        if ((__builtin_popcount(j) == k) && (__builtin_popcount(j & a[i]) == k))
            return 2;
        if (__builtin_popcount(j) == k)
            return 1;
        if(__builtin_popcount(j & a[i]) == k){
            return 1;
        }
        return 0;
    }
    if (dp[i][j] != -1) return dp[i][j];

    ll take = 0;
    if (__builtin_popcount(j & a[i]) >= k) {
        take = solve2(i - 1, j & a[i]);
    }
    ll not_take = solve2(i - 1, j);
    
    return dp[i][j] = (take + not_take) % MOD;
}

void solve() {
    cin >> n >> k;
    dp.assign(n, vl(64, -1));
    a.resize(n);
    for (ll &x : a) cin >> x;
    
    ll result = solve2(n - 1, 63);
    cout << ((k == 6) ? result - 1 : result) << "\n";
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
