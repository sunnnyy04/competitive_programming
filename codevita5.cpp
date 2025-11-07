#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int E;
    if (!(cin >> E)) return 0;
    
    // --- Current layout ---
    vector<pair<int,int>> cur_edges(E);           // index -> (u, v) with u < v
    vector<vector<pair<int,int>>> adj_cur;         // adj[u] = { (v, edge_idx), ... }
    int max_node = 0;
    
    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cur_edges[i] = {a, b};
        max_node = max({max_node, a, b});
    }
    
    adj_cur.resize(max_node + 1);
    for (int i = 0; i < E; ++i) {
        auto [a, b] = cur_edges[i];
        adj_cur[a].emplace_back(b, i);
        adj_cur[b].emplace_back(a, i);
    }
    
    // --- Expected layout ---
    map<pair<int,int>, int> exp_pos;  // (u,v) with u < v -> edge index in expected
    for (int i = 0; i < E; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        exp_pos[{a, b}] = i;
    }
    
    // --- Find all edge-disjoint cycles ---
    vector<bool> used(E, false);
    vector<vector<int>> cycles;  // each cycle = list of edge indices in order
    
    function<bool(int, int, vector<int>&, int)> dfs_cycle = [&](int u, int start, vector<int>& path, int prev_edge) -> bool {
        for (auto [v, eidx] : adj_cur[u]) {
            if (used[eidx] || eidx == prev_edge) continue;
            used[eidx] = true;
            path.push_back(eidx);
            if (v == start) return true;
            if (dfs_cycle(v, start, path, eidx)) return true;
            path.pop_back();
            used[eidx] = false;
        }
        return false;
    };
    
    for (int i = 0; i < E; ++i) {
        if (used[i]) continue;
        auto [a, b] = cur_edges[i];
        vector<int> path = {i};
        used[i] = true;
        // Try starting from b toward a
        if (!dfs_cycle(b, a, path, i)) {
            // If not found, try reverse direction
            fill(used.begin(), used.end(), false);
            used[i] = true;
            path = {i};
            dfs_cycle(a, b, path, i);
        }
        cycles.push_back(move(path));
    }
    
    // --- Compute answer: max required rotation over all cycles ---
    int answer = 0;
    
    for (const auto& cyc : cycles) {
        int L = cyc.size();
        if (L == 0) continue;
        
        // Reconstruct ordered vertices from edge cycle
        vector<int> ordered;
        int cur = -1, prev_e = -1;
        int first_edge = cyc[0];
        auto [u0, v0] = cur_edges[first_edge];
        
        // Start from u0
        cur = u0;
        ordered.push_back(cur);
        prev_e = -1;
        
        for (int step = 0; step < L; ++step) {
            int edge_idx = cyc[step];
            auto [a, b] = cur_edges[edge_idx];
            int next_v = (a == cur ? b : a);
            if (next_v == ordered.front() && step == L - 1) break;
            ordered.push_back(next_v);
            cur = next_v;
        }
        
        // Now: ordered[i] -> ordered[(i+1)%L] uses edge cyc[i]
        int e0 = cyc[0];
        auto [a, b] = cur_edges[e0];
        pair<int,int> edge_key = {min(a, b), max(a, b)};
        int exp_idx = exp_pos[edge_key];
        int cur_idx = e0;
        
        int k = (exp_idx - cur_idx % L + L) % L;
        answer = max(answer, k);
    }
    
    cout << answer << endl;
    return 0;
}