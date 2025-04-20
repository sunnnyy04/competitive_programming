#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define INF INT_MAX

void solve() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<char>> adj(n, vector<char>(m));
    vector<vector<vector<vector<int>>>> dis(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(3, INF))));

    vector<vector<vector<vector<bool>>>> vis(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(3, false))));

    vector<pii> directions = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    
    int startX, startY, targetX, targetY;
    
    priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 'S') {
                startX = i;
                startY = j;
                for (int d = 0; d < 4; d++) {
                    dis[i][j][d][0] = 0;
                    pq.push({0, i, j, d, 0});
                }
            }
            if (adj[i][j] == 'T') {
                targetX = i;
                targetY = j;
            }
        }
    }

    while (!pq.empty()) {
        auto [distance, x, y, dir, step] = pq.top();
        pq.pop();
        
        if (vis[x][y][dir][step]) continue;
        vis[x][y][dir][step] = true;

        for (int d = 0; d < 4; d++) {
            int new_x = x + directions[d].first;
            int new_y = y + directions[d].second;
            int new_step = (d == dir) ? step + 1 : 0;

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&
                (adj[new_x][new_y] == '.' || adj[new_x][new_y] == 'T')) {
                
                int new_cost = distance + (new_step >= 3 ? 3 : 1);
                
                if (new_cost < dis[new_x][new_y][d][new_step]) {
                    dis[new_x][new_y][d][new_step] = new_cost;
                    pq.push({new_cost, new_x, new_y, d, new_step});
                }
            }
        }
    }

    int ans = INF;
    for (int d = 0; d < 4; d++)
        for (int s = 0; s < 3; s++)
            ans = min(ans, dis[targetX][targetY][d][s]);

    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
