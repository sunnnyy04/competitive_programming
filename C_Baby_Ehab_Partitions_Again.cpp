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
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
vvi dp;
    vl a;

bool solve2(int i, int sum, int total) {
    if (sum > total/2) return false;
    if (sum == total/2) return true;
    if (i == sz(a)) return false;
    if (dp[i][sum] != -1) return dp[i][sum];
    
    bool take = solve2(i+1, sum + a[i], total);
    bool nottake = solve2(i+1, sum, total);
    return dp[i][sum] = take || nottake;
}



void solve() {
    ll n;
    cin >> n;
    a.assign(n, 0);
    loop(i, 0, n) cin >> a[i];
    ll sum = accumulate(all(a), 0ll);

    if (sum & 1) {
        cout << 0 << endl;
        return;
    }

    dp.assign(n+1, vi((sum/2)+1, -1));

    if (solve2(0, 0, sum)) {
        pair<int, int> mn(20, 0);
        for (int i = 0; i < n; i++)
            mn = min(mn, make_pair(__builtin_ctz(a[i]), i+1));
        printf("1\n%d", mn.second);
    } else {
        cout << 0 << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
    return 0;
}