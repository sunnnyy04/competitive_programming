#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inv2 = 500000004, mod = 1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        
        ll ans = 0;
        for (ll i = n - 1; i > 0; i--) {
            ans = (ans + (s[i] == '1')) * inv2 % mod;
        }
        cout << (n - 1 + ans) % mod << "\n";
    }
    return 0;
}