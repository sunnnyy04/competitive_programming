#include <bits/stdc++.h>
using namespace std;

//---------------------- Type Aliases ----------------------//
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

//---------------------- Macros ----------------------//
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

//---------------------- Constants ----------------------//
const ll MOD = 1e9 + 7;
const int MAX_N = 500001;
const double PI = 3.14159265358979;
const ll INF = 1e15;

//---------------------- Utility Functions ----------------------//
bool revsort(ll a, ll b) { return (a > b); }
void reverseStr(string &str) { reverse(str.begin(), str.end()); }
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

ll expo(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

//---------------------- Prime Numbers ----------------------//
vi primes;
void init(int maxN) {
    vi is_prime(maxN + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= maxN; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = 2 * i; j <= maxN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}
long long power(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd, multiply base
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2;
    }
    return result;
}

// Function to compute factorials and their modular inverses
void precomputeFactorials(std::vector<long long>& fact, std::vector<long long>& invFact, int n, int mod) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    // Compute inverse of factorial using Fermat's theorem
    invFact[n] = power(fact[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

// Function to compute nCr % mod
long long nCr(int n, int r, const std::vector<long long>& fact, const std::vector<long long>& invFact, ll mod) {
    if (r > n || r < 0) return 0;
    return (fact[n] * invFact[r] % mod * invFact[n - r] % mod) % mod;
}

//---------------------- Debugging Utilities ----------------------//
#define debug(x) cerr << #x << " = " << x << endl;
#define debugv(v) cerr << #v << " = [ "; for (auto i : v) cerr << i << " "; cerr << "]" << endl;

// =============== !!! ~ ~ ~ Code Starts Here ~ ~ ~ !!! ===============
void solve() {
    ll n, m;
    cin >> n >> m;
    
    vector<long long> fact(n + 1), invFact(n + 1);
    precomputeFactorials(fact, invFact, n, MOD);

    vl a(n);
    loop(i, 0, n) cin >> a[i];

    map<int, int> mpp;
    loop(i, 0, n) mpp[a[i]]++;

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    ll x = 1;
    vl b;
    for (auto i : a) {
        x = (x * 1LL * mpp[i]) % MOD;
        b.pb(x);
    }

    ll result = 0;
    for (int i = 0; i + m - 1 < sz(a); i++) {
        ll z = a[i] + m;
        auto ind = lower_bound(all(a), z) - a.begin();
        ind--;

        if (ind - i >= m - 1) {
            ll temp = nCr(ind - i, m - 1, fact, invFact, MOD); 

            if (i > 0) {
                temp = (temp * b[ind] % MOD * expo(b[i - 1], MOD - 2, MOD)) % MOD;
            } else {
                temp = (temp * b[ind]) % MOD;
            }

            result = (result + temp) % MOD;
        }
    }

    cout << result << nl;
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