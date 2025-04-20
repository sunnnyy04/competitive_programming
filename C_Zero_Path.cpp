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
#define bn begin()
#define en end()
#define nl '\n'
#define all(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define loopr(i, a, b) for (int i = (b); i >= (a); i--)
#define prt(v) for (auto i : v) cout << i << ' '; cout << '\n';
#define sp(n) cout << setprecision(n) << fixed;

const ll MOD = 1e9 + 7;
const int MAX_N = 500001;
const double PI = 3.14159265358979;
const ll INF = 1e15;

void solve() {
    ll n, m;
    cin >> n >> m;
    
    vvl a(n, vl(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<vector<ll>>> t(n, vector<vector<ll>>(m, vector<ll>(2)));
    
    t[0][0][0] = a[0][0];
    t[0][0][1] = a[0][0];

    for (int i = 1; i < n; i++) {
        t[i][0][0] = t[i-1][0][0] + a[i][0];
        t[i][0][1] = t[i-1][0][1] + a[i][0];
    }
    for (int j = 1; j < m; j++) {
        t[0][j][0] = t[0][j-1][0] + a[0][j];
        t[0][j][1] = t[0][j-1][1] + a[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            t[i][j][0] = min(t[i-1][j][0], t[i][j-1][0]) + a[i][j];
            t[i][j][1] = max(t[i-1][j][1], t[i][j-1][1]) + a[i][j];
        }
    }

    if (t[n-1][m-1][0] > 0 || t[n-1][m-1][1] < 0 || 
        (t[n-1][m-1][0] % 2 != 0 && t[n-1][m-1][1] % 2 != 0)) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
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
