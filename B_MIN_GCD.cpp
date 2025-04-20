#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll compute_gcd(ll a, ll b) {
    if (b == 0) return a;
    return compute_gcd(b, a % b);
}

void solve() {
    ll n;
    cin >> n;
    vl arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    auto it = min_element(arr.begin(), arr.end());
    ll minimum = *it;
    ll gcd_value = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] % minimum == 0 && (arr.begin() + i) != it) {
            gcd_value = compute_gcd(gcd_value, arr[i]);
        }
    }
    
    if (gcd_value == minimum) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
