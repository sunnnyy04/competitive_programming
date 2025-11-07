#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unordered_map<int, int> umii;
typedef priority_queue<int> maxh;
typedef priority_queue<int, vi, greater<int>> minh;
typedef vector<vector<bool>> vvb;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long double ld;

#define ll long long
#define amax(a, b) (a = max(a, b))
#define amin(a, b) (a = min(a, b))
#define mp(a, b) make_pair(a, b)
#define pb(n) push_back(n)
#define ff first
#define ss second
#define nl '\n'
#define all(a) a.begin(), a.end()
#define loop(i, a, b) for (int i = (a); i < (b); i++)

const ll MOD = 1e9 + 7;
const ll INF = 1e15;

void solve() {
    ll n, m;
    cin >> n >> m;
    multiset<int> a;
    loop(i, 0, n) {
        int b;
        cin >> b;
        a.insert(b);
    }
    vl b(m), c(m);
    loop(i, 0, m) cin >> b[i];
    loop(i, 0, m) cin >> c[i];

    multiset<ll> z;
    ll ans = 0;
    vector<pair<ll, ll>> vpp;

    loop(i, 0, m) {
        if (c[i] == 0)
            z.insert(b[i]);
        else
            vpp.push_back({b[i], c[i]});
    }

    sort(vpp.begin(), vpp.end());

    auto idx = a.begin();
    ll s = 0;

    for (int i = 0; i < (int)vpp.size(); i++) {
            auto it = a.lower_bound(vpp[i].first);
            if (it != a.end() ) {
                
                idx = it;
                if (idx != a.end()) s = *idx;

                ans++;
                s = max(vpp[i].second, s);
                a.erase(it);
                a.insert(s);
            } else {
                break;
            }
        
    }

    if (!a.empty() && !z.empty()) {
        auto i = prev(a.end());
        auto j = prev(z.end()); 

        while (true) {
            if (*i >= *j) {
                ans++;
                if (i == a.begin() || j == z.begin()) break;
                --i;
                --j;
            } else {
                if (j == z.begin()) break;
                --j;
            }
        }
    }

    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
