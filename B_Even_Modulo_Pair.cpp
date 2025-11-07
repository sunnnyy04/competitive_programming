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
#define mp(a, b) make_pair(a, b)
#define pb(n) push_back(n)
#define ff first
#define ss second
#define nl '\n'
#define all(a) a.begin(), a.end()
#define loop(i, a, b) for (int i = (a); i < (b); i++)

const ll MOD = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vl a(n);
    loop(i, 0, n) cin >> a[i];

    vector<ll> odd, even;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2) odd.pb(a[i]);
        else even.pb(a[i]);
    }

    // sort for lower_bound to work correctly
    sort(all(odd));
    sort(all(even));
    ll z=*max_element(all(a));
    if(even.size()>1){
        cout<<even[0]<<" "<<even[1]<<endl;
        return;
    }
    a=odd;

    for (int i = 0; i < odd.size(); i++) {
        ll j = 2;
        while (a[i] * j <= z) {
            
            if (j % 2 == 0) {
                auto it = lower_bound(all(even), a[i] * j);
                if (it != even.end() && (*it) % 2 == 0 ) {
                    cout << a[i] << " " << *it << nl;
                        return;
                    }
                } else {
                    auto it = lower_bound(all(odd), a[i] * j);
                    if (it != odd.end() && (*it) % 2 == 0) {
                        cout << a[i] << " " << *it << nl;
                        return;
                    }
                }

        }
    }
    cout << -1 << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
