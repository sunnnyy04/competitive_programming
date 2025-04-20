#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

const ll MOD = 998244353;

#define loop(i, a, b) for (int i = (a); i < (b); i++)

void solve() {
    int n;
    cin >> n;
    vi a(n);
    loop(i, 0, n) cin >> a[i];

    ll ans = 0;
    
    for (int i = 0; i < 30; i++) { 
        ll o = 0, e = 0, osum = 0, esum = 0;
        
        for (int j = 0; j < n; j++) {
            if (a[j] & (1ll << i)) {
                swap(e, o);
                swap(esum, osum);
                osum = ((osum+j)%MOD);
                o++;
                o%=MOD;
            } else {
                e++;
                e%=MOD;
                esum =((esum+ j)%MOD);
            }
            ll term = ((1ll * (j + 1) * o - osum) % MOD) % MOD;
            ans = (ans + ((1ll << i) % MOD * term) % MOD) % MOD;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
