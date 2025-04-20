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

priority_queue<pll, vector<pll>, greater<pll>> pq;
int n, m;
vl dis;
vi vis;
vector<vector<pll>> adj;

void dijkstra() {
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        if (vis[node]) continue;
        vis[node] = 1;
        for (auto [neighbor, weight] : adj[node]) {
            
                dis[neighbor] = min(dis[neighbor],d + weight);
                pq.push({dis[neighbor], neighbor});
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n + 1, vector<pll>());
    dis.assign(n + 1, INF);
    vis.assign(n + 1, 0);
    vector<vector<pll>> adj2(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj2[y].push_back({x, z});
    }

    dijkstra();
    adj = adj2;

    vis.assign(n + 1, 0);

    while (!pq.empty()) pq.pop(); 

    dijkstra();


    for (int i = 2; i <= n; i++) {
        if (dis[i] == INF) {
            cout << -1 << " ";
        } else {
            cout << dis[i]<< " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
