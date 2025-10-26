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


void solve() {
    int n;
    cin>>n;
    vector<int>ans(2*n,-1);
    vector<int>q;
    q.push_back(0);
    for(int i=1;i<2*n;i++){
        q.push_back(i);
 
        cout << "? " << q.size() << ' ';
        for (int j : q) {
            cout << j + 1 << ' ';
        }
        cout << endl;
 
        int res;
        cin >> res;
 
        if (res) {
            ans[i] = res;
            q.pop_back();
        }
    }
    vector<int> found(n + 1, false);
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (ans[i] == -1) {
            q.clear();
 
            for (int j = i; j < 2 * n; j++) {
                if (ans[j] == -1)
                    q.push_back(j);
                else if (!found[ans[j]])
                    q.push_back(j);
            }
 
            cout << "? " << q.size() << ' ';
            for (int i : q) {
                cout << i + 1 << ' ';
            }
            cout << endl;
 
            int res;
            cin >> res;
 
            ans[i] = res;
            found[res] = true;
        }
    }
 
    cout << "! ";
    for (int i : ans) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();
    return 0;
}