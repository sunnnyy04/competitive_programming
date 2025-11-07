#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int E;
    cin >> E;
    
    // Read current edges
    vector<pair<int, int>> current(E);
    for (auto& p : current) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        p = {a, b};
    }
    
    // Read expected edges
    vector<pair<int, int>> expected(E);
    for (auto& p : expected) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        p = {a, b};
    }
    
    // Find max node id
    int maxn = 0;
    for (auto& p : current) maxn = max({maxn, p.first, p.second});
    for (auto& p : expected) maxn = max({maxn, p.first, p.second});
    
    // Compute d_e: map from sorted pair to delta
    map<pair<int, int>, int> delta;
    for (auto& p : current) delta[p]--;
    for (auto& p : expected) delta[p]++;
    vector<pair<int, int>> edges;
    for (auto& pr : delta) if (pr.second != 0) edges.push_back(pr.first);
    int num_nonzero = edges.size();
    map<pair<int, int>, int> edge_id;
    for (int i = 0; i < num_nonzero; ++i) edge_id[edges[i]] = i;
    vector<int> d(num_nonzero);
    for (auto& pr : delta) {
        auto e = pr.first;
        int dd = pr.second;
        if (dd != 0) d[edge_id[e]] = dd;
    }
    
    // Build adj list for undirected graph
    vector<vector<int>> adj(maxn + 1);
    auto add_edge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    for (auto& p : current) add_edge(p.first, p.second);
    for (auto& p : expected) add_edge(p.first, p.second);
    
    // Enumerate all simple cycles using DFS
    vector<vector<int>> cycles;
    vector<bool> visited(maxn + 1);
    vector<int> path;
    function<void(int, int)> dfs = [&](int u, int start) {
        path.push_back(u);
        visited[u] = true;
        for (int v : adj[u]) {
            if (v == start && path.size() >= 3) {
                // Cycle found
                vector<int> cyc = path;
                cyc.push_back(start);
                cycles.push_back(cyc);
            } else if (!visited[v]) {
                dfs(v, start);
            }
        }
        path.pop_back();
        visited[u] = false;
    };
    for (int i = 1; i <= maxn; ++i) {
        fill(visited.begin(), visited.end(), false);
        path.clear();
        dfs(i, i);
    }
    
    int C = cycles.size();
    if (C == 0) {
        // No cycles, check if already matching
        cout << (num_nonzero == 0 ? 0 : -1) << '\n'; // But assume possible
        return 0;
    }
    
    // Build cycle matrix over GF(2): rows=cycles, cols=edges
    vector<vector<int>> mat(C, vector<int>(num_nonzero, 0));
    for (int i = 0; i < C; ++i) {
        auto& cyc = cycles[i];
        int k = cyc.size() - 1; // length
        set<pair<int, int>> cyc_edges;
        for (int j = 0; j < k; ++j) {
            int u = cyc[j], v = cyc[(j + 1) % k];
            if (u > v) swap(u, v);
            cyc_edges.insert({u, v});
        }
        for (auto& e : cyc_edges) {
            auto it = edge_id.find(e);
            if (it != edge_id.end()) {
                mat[i][it->second] = 1;
            }
        }
    }
    
    // Gaussian elimination over GF(2) to find basis
    vector<int> basis(C, 0); // indices of basis cycles
    int rank = 0;
    vector<int> col_to_row(num_nonzero, -1);
    for (int col = 0; col < num_nonzero; ++col) {
        int pivot = -1;
        for (int r = rank; r < C; ++r) {
            if (mat[r][col] == 1) {
                pivot = r;
                break;
            }
        }
        if (pivot == -1) continue;
        // Swap rows
        swap(mat[pivot], mat[rank]);
        basis[rank] = pivot;
        col_to_row[col] = rank;
        // Eliminate
        for (int r = 0; r < C; ++r) {
            if (r != rank && mat[r][col] == 1) {
                for (int j = col; j < num_nonzero; ++j) {
                    mat[r][j] ^= mat[rank][j];
                }
            }
        }
        ++rank;
    }
    
    // Now basis has 'rank' cycles
    int ans = 0;
    for (int i = 0; i < rank; ++i) {
        int cidx = basis[i];
        auto& cyc = cycles[cidx];
        int k = cyc.size() - 1;
        int max_x = 0;
        for (int j = 0; j < k; ++j) {
            int u = cyc[j], v = cyc[(j + 1) % k];
            if (u > v) swap(u, v);
            auto it = edge_id.find({u, v});
            if (it != edge_id.end()) {
                int eid = it->second;
                int de = d[eid];
                int x = (de % k + k) % k;
                max_x = max(max_x, x);
            }
        }
        ans = max(ans, max_x);
    }
    
    cout << ans << '\n';
    return 0;
}