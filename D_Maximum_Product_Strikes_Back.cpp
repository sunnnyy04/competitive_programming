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
#define int long long

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
ll ans;
ll xans;
ll yans;
ll n;
vl a;
void solve2(ll i,ll j){
    if(i>j) return ;
    ll x=i;
    ll neg=0;
    ll cnt2=0;
    while(i<=j){
        if(a[i]<0){
            neg++;
        }
        if(a[i]==2 || a[i]==-2){
            cnt2++;
        }
        i++;
    }
    i=x;
    if(neg%2==0){
        if(cnt2>ans){
            xans=x;
            yans=j;
            ans=cnt2;
        }
    }
    else{
        ll tcnt2=cnt2;
        while(i<j && a[i]>0){
            if(a[i]==2 || a[i]==-2){
                tcnt2--;
            }
            i++;
        }
        if(i<j){
            if(a[i]==2 || a[i]==-2){
                tcnt2--;
            }
            i++;
            if(ans<tcnt2){
                xans=i;
                yans=j;
                ans=tcnt2;
            }
        }
        i=x;
        tcnt2=cnt2;
        while(j>i && a[j]>0){
            if(a[j]==2 || a[j]==-2){
                tcnt2--;
            }
            j--;
        }
        if(j>i && a[j]<0){
            if(a[j]==2 || a[j]==-2){
                tcnt2--;
            }
            j--;
            if(ans<tcnt2){
                xans=i;
                yans=j;
                ans=tcnt2;
        }
        }
        
    }
}

void solve() {
    ans=0;
    xans=0;
    yans=-1;
    cin>>n;
    a.clear();
    a.assign(n,0);
    loop(i,0,n) cin>>a[i];
    if(n==1){
        if(a[0]>=1)cout<<0<<" "<<0<<endl;
        else{
            cout<<0<<" "<<n<<endl;
        }
        return ;
    }
    ll j=0;
    for(ll i=0;i<n;i++){
        if(a[i]==0){
            if(j<=i) solve2(j,i-1);
            j=i+1;
        }
    }
    if(j<=n-1){
        solve2(j,n-1);
    }
    if(xans==0 && yans==-1){
        cout<<0<<" "<<n<<endl;
        return;
    }
    cout<<xans<<" "<<n-yans-1<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}