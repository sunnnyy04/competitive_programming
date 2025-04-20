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
#define pb push_back
#define ff first
#define ss second
#define nl '\n'
#define all(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())

const ll MOD = 1e9 + 7;
const int MAX_N = 500001;
const ll INF = 1e15;

ll n, a, b;
vector<vector<pair<int, int>>> adj;
set<int> st;

void solve2(int z, int x, vi &vis) {
    if (vis[z] != -1) return;
    vis[z] = 1;
    for (auto j : adj[z]) { 
        if (vis[j.first] == -1) {
            x ^= j.second;
            st.insert(x);
            solve2(j.first, x, vis); 
            x ^= j.second;
        }
    }
}

bool solve3(int q, int x, vi &vis) {
    if (st.find(x) != st.end()) return true;
    vis[q] = 1;
    bool ans = false;
    for (auto i : adj[q]) {
        if (vis[i.first] == -1 && i.first!=b) {
            ans |= solve3(i.first, x ^ i.second, vis);
        }
    }
    return ans;
}

void solve() {
    cin >> n >> a >> b;
    adj.assign(n + 1, vector<pair<int, int>>());
    st.clear();
    for (int i = 0; i < n-1; i++) {  
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    vi vis(n + 1, -1);

    solve2(b, 0, vis);
    // for(auto j:st){
    //     cout<<j<<" ";
    // }
    // cout<<endl;

    vis.assign(n + 1, -1);
    if (solve3(a, 0, vis)) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
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
