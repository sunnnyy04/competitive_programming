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

set<int> primes;
void init(int maxN) {
    vi is_prime(maxN + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= maxN; i++) {
        if (is_prime[i]) {
            primes.insert(i);
            for (int j = 2 * i; j <= maxN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}
bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
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

void solve() {
    ll n,k;
    cin>>n>>k;
    if(is_prime(n) && k==1){
        cout<<"YES"<<endl;
    }
    else if(n==1 && k==2){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
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