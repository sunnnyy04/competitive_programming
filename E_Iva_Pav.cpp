#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------//
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<bool> vb;
typedef unordered_map<int, int> umii;
typedef priority_queue<int> maxh;
typedef priority_queue<int, vi, greater<int>> minh;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define loop(i, a, b) for (int i = a; i < b; i++)
#define nl "\n"

const ll MOD = 1e9 + 7;
const int MAX_N = 500001;

// =============== !!! ~ ~ ~ Code Starts Here ~ ~ ~ !!! ===============
void solve() {
    int n;
    cin >> n;
    vl a(n);
    loop(i, 0, n) cin >> a[i];

    vector<vector<ll>> pbit(n + 1, vector<ll>(32, 0));

    // Precompute prefix sum of bits
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 32; j++) {
            pbit[i][j] = pbit[i - 1][j] + ((a[i - 1] & (1LL << j)) ? 1 : 0);
        }
    }

    ll q;
    cin >> q;
    while (q--) {
        ll k, l;
        cin >> l >> k;
        if (a[l - 1] < k) {
            cout << -1 << " ";
            continue;
        }

        ll start = l, end = n, ans = l;
        while (start <= end) {
            ll mid = start + (end - start) / 2;
            ll nums = 0;
            for (int j = 0; j < 32; j++) {
                if (pbit[mid][j] - pbit[l - 1][j] == mid - l + 1) {
                    nums += (1LL << j);
                }
            }

            if (nums >= k) {
                ans = mid;
                start=mid+1;
            } else {
                end = mid -1;
            }
        }

        cout << ans << " ";
    }
    cout << nl;
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
