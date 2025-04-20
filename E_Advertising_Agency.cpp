#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------//
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<long long> vl;
typedef vector<vector<long long> > vvl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef unordered_map<int, int> umii;
typedef priority_queue<int> maxh;
typedef priority_queue<int, vi, greater<int> > minh;
typedef vector<vector<bool> > vvb;
typedef map<int, int> mii;
typedef map<long long, long long> mll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unsigned long long ull;
typedef long double ld;

#define ll long long
#define amax(a, b)          a = max(a, b)
#define amin(a, b)          a = min(a, b)
#define mp(a, b)            make_pair(a, b)
#define pb(n)               push_back(n)
#define ff                  first
#define ss                  second
#define bn                  begin()
#define prt(v)              for (auto i : v) cout << i << " "; cout << "\n";
#define en                  end()
#define nl                  "\n"
#define sp(n)               cout << setprecision(n) << fixed;
#define loop(i, a, b)       for (int i = a; i < b; i++)
#define loopr(i, a, b)      for (int i = b; i < a; i--)
#define all(a)              a.begin(), a.end()
#define sz(x)               ((int)(x).size())

//--------------------------------------------------------------//
const long long MOD = 1000000007;
const int MAX_N = 1001;
const double PI = 3.14159265358979;
const double INF = 1e15;

/*---------------------------------------------------------------------------*/ 
vector<ll> fact(MAX_N, 1), invFact(MAX_N, 1);

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void precompute() {
    for (ll i = 2; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX_N - 1] = power(fact[MAX_N - 1], MOD - 2, MOD);
    for (ll i = MAX_N - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}
ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return ((fact[n] * invFact[r]) % MOD * invFact[n - r]) % MOD;
}

// =============== !!! ~ ~ ~ Code Starts Here ~ ~ ~ !!! ===============
void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    loop(i, 0, n) cin >> a[i];
    sort(all(a));

    ll x = 0;
    for (int i = n - k; i < n; i++) {
        if (a[i] == a[n - k]) {
            x++;
        } else {
            break;
        }
    }

    mll mpp;
    loop(i, 0, n) {
        mpp[a[i]]++;
    }
    
    cout << nCr(mpp[a[n - k]], x) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute(); 

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
