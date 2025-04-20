#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

const ll INF = 1e15;

void solve() {
    ll n, m, h;
    cin >> n >> m >> h;
    
    set<ll> horseStations;
    vector<vector<pll>> adj(n + 1);
    
    for (int i = 0; i < h; i++) {
        ll x;
        cin >> x;
        horseStations.insert(x);
    }
    
    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    auto dijkstra = [&](ll src, vl &distanceh, vl &distancewh) {
        priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
        
        if (horseStations.count(src)) {
            pq.push({0, {src, 1}}); 
        } else {
            pq.push({0, {src, -1}}); 
        }
        
        while (!pq.empty()) {
            auto [dist, p] = pq.top();
            auto [u, hasHorse] = p;
            pq.pop();
            
            if (hasHorse != -1) {
                if (distanceh[u] <= dist) continue;
                distanceh[u] = dist;
            } else {
                if (distancewh[u] <= dist) continue;
                distancewh[u] = dist;
            }
            
            for (auto &[v, w] : adj[u]) {
                if (hasHorse != -1) {
                    pq.push({dist + w/2, {v, hasHorse}});
                } else {
                    if (horseStations.count(u)) {
                        pq.push({dist + w/2, {v, 1}}); 
                    } else {
                        pq.push({dist + w, {v, hasHorse}});
                    }
                }
            }
        }
    };
    
    vl d1Horse(n + 1, INF), d1WithoutHorse(n + 1, INF);
    vl dnHorse(n + 1, INF), dnWithoutHorse(n + 1, INF);
    
    dijkstra(1, d1Horse, d1WithoutHorse);
    dijkstra(n, dnHorse, dnWithoutHorse);
    
    ll ans = INF;
    
    for (ll u = 1; u <= n; u++) {
        ll t1 = min(d1Horse[u], d1WithoutHorse[u]);
        ll t2 = min(dnHorse[u], dnWithoutHorse[u]);
        ll meetTime = max(t1, t2);
        ans = min(ans, meetTime);
    }
    
    if (ans >= INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
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
