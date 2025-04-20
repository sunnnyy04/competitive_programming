#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void setIO()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
vl fact(2e5 + 5,1);
ll binPow(ll a,ll b)
{
    if (b == 0)return 1;
    if (b == 1)return a;
    ll ret = binPow(a,b/2);
    if (b%2 == 0)return (ret * ret)%mod;
    return ((ret * ret)%mod * a)%mod;
}
ll inv(ll a)
{
    return (binPow(a,mod - 2)%mod + mod)%mod;
}
ll binom(ll a,ll b)
{
    return (((fact[a] * inv(fact[b]))%mod * inv(fact[a - b]))%mod + mod)%mod;
}
int main()
{
    setIO();

    for (int i = 2;i<=2e5;i++)fact[i] = (fact[i - 1] * 1ll * i)%mod;

    int t;
    cin>>t;
    while (t--){
        ll n,k;
        cin>>n>>k;
        
        ll val = 0;

        if (k == 0){
            cout<<1<<'\n';
            continue;
        }

        for (ll i = 0;i <= n - 1;i += 2)
            val = (val + (binom(n,i)%mod))%mod;
        
        
        vvl dp(k,vl(2));

        //dp[i][0]: LHS == RHS at ith bit
        //dp[i][1]: LHS > RHS at ith bit
        
        for (int i = 0;i<k;i++){
            if (i == 0){
                
                dp[i][1] = (n%2 == 0 ? 1 : 0);
                
                //if n is even => LHS = 1 and RHS = 0
                
                dp[i][0] = (n%2 == 1 ? 1 : 0) + val;
                
                //if n is odd => LHS = 1 and RHS = 1
                //Choose an even number of 1's and at least one 0

                dp[i][0] %= mod;
                dp[i][1] %= mod;
            }
            else{
                
                dp[i][1] = ((n%2 == 0 ? 1 : 0) * (binPow(2,n * i)%mod))%mod;
                
                dp[i][0] = (((n%2 == 1 ? 1 : 0) + val)%mod * ((dp[i - 1][0]%mod + dp[i - 1][1])%mod)%mod)%mod;

                dp[i][0] %= mod;
                dp[i][1] %= mod;
            }
        }
        ll ans = (dp[k - 1][0] + dp[k - 1][1]%mod)%mod;
        if (ans < 0)ans += mod;
        cout<<ans<<'\n';
    }
    return 0;
}