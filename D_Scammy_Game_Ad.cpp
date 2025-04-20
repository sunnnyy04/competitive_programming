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

//---------------------- Debugging Utilities ----------------------//
#define debug(x) cerr << #x << " = " << x << endl;
#define debugv(v) cerr << #v << " = [ "; for (auto i : v) cerr << i << " "; cerr << "]" << endl;

// =============== !!! ~ ~ ~ Code Starts Here ~ ~ ~ !!! ===============
void solve() {
    int n;
    cin >> n;
    vector<char>c1(n);
    vector<char>c2(n);
    vi d1(n);
    vi d2(n);

    // Input processing
    for (int i = 0; i < n; i++) {
        cin>>c1[i];
        cin>>d1[i];
        cin>>c2[i];
        cin>>d2[i];
    }

    ll x = 1, y = 1;

    for (int i = 0; i < n; i++) {
        ll buffer = 0;


        if (c1[i] == '+') {
            buffer += d1[i]; 
        } else { 
            buffer += (x * (d1[i] - 1));
        }
        // cout<<buffer<<" ";

        
        if (c2[i] == '+') {
            buffer += (d2[i]);
        } else { 
            buffer += (y * (d2[i] - 1));
        }


        
        bool updated = false;
        for (int j = i + 1; j < n; j++) {
            if (c1[j] == 'x' && c2[j] != 'x') {
                x += buffer;
                updated = true;
                break;
            }
            if (c1[j]!= 'x' && c2[j]== 'x') {
                y += buffer;
                updated = true;
                break;
            }
            if (c1[j] == 'x' && c2[j] == 'x') {
                if (d1[j]>d2[j]) {
                    x += buffer;
                    updated = true;
                    break;
                } else if(d1[j]<d2[j]) {
                    y += buffer;
                    updated = true;
                    break;
                }
                
            }
        }

        if (!updated) {
            x += buffer;
        }
    }

    cout << x + y << endl;
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