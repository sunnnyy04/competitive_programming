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
int n;
vector<vector<int>>dp;
vector<string>mat(2);
int solve2(int i, int j) {
    if (i >= n) return 0;
    if(i==n-1&& j!=0){
        return INT_MIN;
    }
    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MIN;
    
    if (j == 0) {
        if (i+2 < n) {
            int cnt0 = 0, cnt1 = 0;
            for (int z = i; z <= i+2; z++) {
                if (mat[0][z] == 'A') cnt0++;
                if (mat[1][z] == 'A') cnt1++;
            }
            cnt0 /= 2;
            cnt1 /= 2;
            ans = max(ans, cnt0 + cnt1 + solve2(i+3, 0));
        }
        int cnt0 = 0, cnt1 = 0;
        if (i+1 < n) {
            cnt0 += (mat[0][i] == 'A');
            cnt0 += (mat[0][i+1] == 'A');
            cnt0 += (mat[1][i] == 'A');
            
            cnt1 += (mat[0][i] == 'A');
            cnt1 += (mat[1][i] == 'A');
            cnt1 += (mat[1][i+1] == 'A');
            
            cnt0 /= 2;
            cnt1 /= 2;
            
            ans = max(ans, cnt0 + solve2(i+1, 1));
            ans = max(ans, cnt1 + solve2(i+1, 2));
        }
    } 
    else if (j == 1) {
        if (i+2 < n) {
            int cnt0 = 0, cnt1 = 0;
            for (int z = i; z <= i+2; z++) {
                if (mat[0][z+1] == 'A') cnt0++;
                if (mat[1][z] == 'A') cnt1++;
            }
            cnt0 /= 2;
            cnt1 /= 2;
            ans = max(ans, cnt0 + cnt1 + solve2(i+3, j));
        }
        if (i+1 < n) {
            int cnt0 = 0;
            cnt0 += (mat[0][i+1] == 'A');
            cnt0 += (mat[1][i] == 'A');
            cnt0 += (mat[1][i+1] == 'A');
            cnt0 /= 2;
            ans = max(ans, cnt0 + solve2(i+2, 0));
        }
    } 
    else {
        if (i+2 < n) {
            int cnt0 = 0, cnt1 = 0;
            for (int z = i; z <= i+2; z++) {
                if (mat[0][z] == 'A') cnt0++;
                if (mat[1][z+1] == 'A') cnt1++;
            }
            cnt0 /= 2;
            cnt1 /= 2;
            ans = max(ans, cnt0 + cnt1 + solve2(i+3, j));
        }
        if (i+1 < n) {
            int cnt0 = 0;
            cnt0 += (mat[0][i] == 'A');
            cnt0 += (mat[0][i+1] == 'A');
            cnt0 += (mat[1][i+1] == 'A');
            cnt0 /= 2;
            ans = max(ans, cnt0 + solve2(i+2, 0));
        }
    }
    return dp[i][j] = ans;
}
void solve() {
    cin>>n;
    mat.clear();
    cin>>mat[0];
    cin>>mat[1];
    dp.assign(n+1,vi(3,-1));
    cout<<solve2(0,0)<<endl;
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