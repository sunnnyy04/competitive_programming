#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef map<ll, ll> mll;

#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back


ll nCr(ll n, ll r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;

    ll res = 1;
    for (ll i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vl a(n);
    loop(i, 0, n) cin >> a[i];

    mll mpp;
    for (ll i : a) {
        mpp[i]++;
    }

    ll res = 0;
    for (auto &i : mpp) {
        ll j = 2;
        if (i.second >= 3) {
            res += (nCr(i.second, 3) * 6ll);
        }
        while ((j * i.first) <= 1e6 && (j * j * i.first) <= 1e6) {
            if (mpp.find(j * i.first) != mpp.end() && mpp.find(j * j * i.first) != mpp.end()) {
                res += (i.second * mpp[j * i.first] * mpp[j * j * i.first]);
            }
            j++;  
        }
    }

    cout << res << endl;
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
