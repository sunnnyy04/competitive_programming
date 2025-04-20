#include <bits/stdc++.h>
using namespace std;

// Typedefs
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unordered_map<int, int> umii;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef priority_queue<int> maxh;
typedef priority_queue<int, vi, greater<int>> minh;

// Macros
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'
#define all(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define loopr(i, a, b) for (int i = (b); i >= (a); i--)
#define prt(v) for (auto i : v) cout << i << ' '; cout << '\n';
#define sp(n) cout << setprecision(n) << fixed

// Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e15;
const int MAX_N = 5e5 + 1;
const double PI = 3.14159265358979;

// Helper Functions
bool revsort(ll a, ll b) { return a > b; }
void reverseStr(string &str) { reverse(all(str)); }
bool ispal(string x) { return x == string(x.rbegin(), x.rend()); }

int modadd(int a, int b, int m) { return (a % m + b % m) % m; }
int modmul(int a, int b, int m) { return ((ll)a * b) % m; }
int modsub(int a, int b, int m) { return ((a % m - b % m) + m) % m; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

ll expo(ll a, ll n, ll m) {
    ll res = 1;
    while (n) {
        if (n & 1) res = modmul(res, a, m);
        a = modmul(a, a, m);
        n >>= 1;
    }
    return res;
}

vi primes;
void init(int maxN) {
    vi is_prime(maxN + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= maxN; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = 2 * i; j <= maxN; j += i)
                is_prime[j] = 0;
        }
    }
}

ll power(ll base, ll exp, int mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Solve function
void solve() {
    ll n, q;
    cin >> n >> q;
    vl a(n);
    ll s = 0, x = 0;

    for (ll &i : a) {
        cin >> i;
        s += i;
        x ^= i;
    }

    ll mx = s - x;
    ll start = 1, end = n;
    ll ansl = 0, ansr = 0;

    while (start <= end) {
        ll mid = (start + end) / 2;
        ll ts = 0, tx = 0;
        ll k = 0, l = mid - 1;

        for (ll m = 0; m < mid; m++) {
            ts += a[m];
            tx ^= a[m];
        }

        bool found = ((ts - tx) == mx);

        while (l < n - 1 && !found) {
            ts = ts - a[k];
            tx ^= a[k];
            l++;
            k++;
            tx ^= a[l];
            ts += a[l];
            found = ((ts - tx) == mx);
        }

        if (found) {
            ansl = k;
            ansr = l;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    ll l, r;
    cin >> l >> r;

    if (mx == 0) {
        cout << 1 << " " << 1 << nl;
        return;
    }

    cout << ansl + 1 << " " << ansr + 1 << nl;
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
