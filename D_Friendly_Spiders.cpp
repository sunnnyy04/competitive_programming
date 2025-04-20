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

const int maxN = 3e5+2;
vector<int> spf(maxN + 1, 0);

void sieve() {
    for (int i = 0; i <= maxN; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= maxN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= maxN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    ll n, s, t;
    cin >> n;
    vl a(n + 1);
    vector<vector<ll>> adj(2 * maxN);
    for(int i=1;i<=n;i++) cin >> a[i];

    cin>>s>>t;

    for(ll i=1;i<=n;i++){
        while(spf[a[i]]>1){
            adj[i].pb(maxN+spf[a[i]]);
            adj[maxN+spf[a[i]]].pb(i);
            a[i]/=spf[a[i]]; 
        }
    }

    vector<ll> dis(2 * maxN, -1);
    vector<ll> par(2 * maxN, -1);
    dis[s] = 1;
    queue<ll> q;
    q.push(s);

    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        for (auto j : adj[node]) {
            if (dis[j] == -1) {
                par[j] = node;
                dis[j] = dis[node] + 1;
                q.push(j);
            }
        }
    }

    if (dis[t] == -1) {
        cout << -1 << endl;
        return;
    }

    ll node = t;
    vl ans;
    while (node != -1) {
        if(node<=n) ans.pb(node);
        node = par[node];
    }

    cout << (dis[t] + 1) / 2 << endl;  

    reverse(all(ans));
    for (auto i : ans) {
        if (i <= n) cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    solve();
    return 0;
}
