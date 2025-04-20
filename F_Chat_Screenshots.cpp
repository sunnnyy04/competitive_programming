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
bool dfs(int i,vi &vis, vector<set<int>>&v, vi &pvis){
    vis[i]=1;
    pvis[i]=1;
    for(auto j:v[i]){
        if(!vis[j]){
            if(dfs(j,vis,v,pvis)) return true;
        }
        else if(pvis[j]==1) return true;
    }
    pvis[i]=0;
    return false;

}
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<set<int>>v(n+1);
    for(int i=0;i<k;i++){
        vi a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=2;j<n;j++){
            v[a[j]].insert(a[j-1]);
        }
    }
    if(k==1){
        cout<<"YES"<<endl;
        return;
    }
    vi vis(n+1,0);
    vi pvis(n+1,0);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i,vis,v,pvis)){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    
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