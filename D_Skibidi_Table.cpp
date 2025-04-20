#include <bits/stdc++.h>
using namespace std;

// Typedefs
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

// Macros
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define loop(i,a,b) for (int i = (a); i < (b); i++)
#define nl '\n'

// Constants
const ll INF = 1e15;
const ll MOD = 1e9 + 7;


ll solve2(ll x, ll y, ll value, ll siz, ll r, ll l) {
    if (siz == 1) {
        return value;
    }
    ll inc = siz / 2;
    ll dx[4] = {0, inc, inc, 0};
    ll dy[4] = {0, inc, 0, inc};
    for (int i = 0; i < 4; i++) {
        if (r >= x + dx[i] && r < x + dx[i] + inc && l >= y + dy[i] && l < y + dy[i] + inc) {
            ll total = value + (i * (siz * siz) / 4);
            return solve2(x + dx[i], y + dy[i], total, inc, r, l);
        }
    }
    return -1; 
}


pll solve1(ll d, ll x, ll y, ll value, ll siz) {
    if (siz == 1) {
        return {x, y};
    }
    ll inc = siz / 2;
    ll dx[4] = {0, inc, inc, 0};
    ll dy[4] = {0, inc, 0, inc};
    for (int i = 0; i < 4; i++) {
        ll start_val = value + (i * (siz * siz) / 4);
        ll end_val = value + ((i + 1) * (siz * siz) / 4);
        if (d >= start_val && d < end_val) {
            return solve1(d, x + dx[i], y + dy[i], start_val, inc);
        }
    }
    return {-1, -1};
}


void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string t;
        cin >> t;
        if (t == "->") {
            ll r, l;
            cin >> r >> l;
            cout << solve2(1, 1, 1, (1ll << n), r, l) << nl;
        } else {
            ll d;
            cin >> d;
            pll ans = solve1(d, 1, 1, 1, (1ll << n));
            cout << ans.ff << " " << ans.ss << nl;
        }
    }
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
