#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())
#define loop(i,a,b) for(int i=(a); i<(b); i++)
#define nl '\n'

const ll MOD = 1e9+7;
const ll INF = 1e15;

template<typename T> inline void amin(T &a, T b) { if(b < a) a = b; }
template<typename T> inline void amax(T &a, T b) { if(b > a) a = b; }

ll modmul(ll a, ll b, ll m=MOD) { return (a % m * b % m) % m; }
ll modadd(ll a, ll b, ll m=MOD) { return (a % m + b % m) % m; }
ll modsub(ll a, ll b, ll m=MOD) { return (a % m - b % m + m) % m; }

ll expo(ll a, ll n, ll m=MOD) {
    ll res = 1;
    while(n) {
        if(n & 1) res = modmul(res, a, m);
        a = modmul(a, a, m);
        n >>= 1;
    }
    return res;
}

int solve2(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> prefixIndex;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) maxLen = i + 1; 
        prefixIndex[sum].push_back(i);
    }
    sum = 0;
    for (int i = n - 1; i>0; i--) {
        sum += arr[i];
        if (sum == 0) maxLen = max(maxLen, n - i);
        if (prefixIndex.find(-sum) != prefixIndex.end()) {
            auto &vec = prefixIndex[-sum];
            auto it = upper_bound(vec.begin(), vec.end(), i - 1);

            if (it != vec.begin()) {
                --it;   
                int idx = *it;
                int len = (n+idx+1)-i;  
                maxLen = max(maxLen, len);
            }
        }
    }
    return maxLen;
}


void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            ans.push_back(1);
        }
        else{
            ans.push_back(-1);
        }

    }

    int a=solve2(ans);
    if(a==0){
        cout<<-1<<endl;
        return;
    }
    else{
        cout<<n-a<<endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();
    return 0;
}