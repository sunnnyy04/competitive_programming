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
const int MAX_N = 500001;
const double PI = 3.14159265358979;
const double INF = 1e15;

/*---------------------------------------------------------------------------*/ 
bool revsort(ll a, ll b) { return (a > b); }
void reverseStr(string &str) { int n = str.length(); for (int i = 0; i < n / 2; i++) { swap(str[i], str[n - i - 1]); } }
bool ispal(string x) { int n = x.size(); for (int i = 0; i < n / 2; i++) { if (x[i] != x[n - i - 1]) return 0; } return 1; }
void printall(vi v) { for (auto ele : v) cout << ele << " "; }
int modadd(int a, int b, int m) { a %= m; b %= m; return (a + b) % m; }
int modmul(int a, int b, int m) { a %= m; b %= m; return (a * b) % m; }
int modsub(int a, int b, int m) { a %= m; b %= m; return (a - b + m) % m; }
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
int expo(int a, int n, int m) { int res = 1; while (n) { if (n & 1) { res = modmul(res, a, m); --n; } else { a = modmul(a, a, m); n >>= 1; } } return res; }
int expo(int a, int n) { int res = 1; while (n) { if (n & 1) { res = res * a; --n; } else { a = a * a; n >>= 1; } } return res; }
/*---------------------------------------------------------------------------*/ 

// =============== !!! ~ ~ ~ Code Starts Here ~ ~ ~ !!! ===============
void solve() {
    ll n,l,r;
    cin>>n>>l>>r;
    vl a(n+1);
    loop(i,1,n+1) cin>>a[i];
    vl pxo(n+1);
    pxo[1] = a[1];
    for (int i = 2; i <= n; i++) {
        pxo[i] = pxo[i - 1] ^ a[i];
    }

    if(l<=n){
        cout<<a[l]<<endl;
        return;
    }
        ll z=l/2ll;
        if(z<=n){
            cout<<pxo[z]<<endl;
        }
        else if(z%2!=0){
            if(n%2==0){
                cout<<(pxo[n]^pxo[n/2])<<endl;
            }
            else{
                cout<<pxo[n]<<endl;
            }
            
        }
        else{
            int cnt=0;
            while(z%2==0 && z>n){
                z/=2;
                cnt++;
            }
            if(z<=n){
                if(n%2==0){
                    if(cnt%2!=0) cout<<(pxo[n]^pxo[n/2]^pxo[z])<<endl;
                    else cout<<(pxo[z])<<endl;
                }
                else{
                    if(cnt%2!=0) cout<<(pxo[n]^pxo[z])<<endl;
                    else cout<<(pxo[z])<<endl;   
                }
            }
            else if(n%2==0){
                cnt++;
                if(cnt%2!=0) cout<<(pxo[n]^pxo[n/2])<<endl;
                else cout<<0<<endl;
            }
            else{
                cnt++;
                if(cnt%2!=0) cout<<pxo[n]<<endl;
                else cout<<0<<endl;   
            }
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