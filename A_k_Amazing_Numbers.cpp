#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define loop(i, a, b) for (int i = a; i < b; i++)
#define nl "\n"
const int INF = INT_MAX;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    loop(i, 0, n) cin >> a[i];

    unordered_map<int, vi> freq;
    vi ans(n + 2, INF);

    loop(i, 0, n) {
        freq[a[i]].push_back(i);
    }

    for (auto &[num, indices] : freq) {
        int prev = -1, maxGap = 0;
        for (int idx : indices) {
            maxGap = max(maxGap, idx - prev);
            prev = idx;
        }
        maxGap = max(maxGap, n - prev); 
        ans[maxGap] = min(ans[maxGap], num);
    }

    loop(i, 1, n + 1) {
        ans[i] = min(ans[i], ans[i - 1]);
        cout << (ans[i] == INF ? -1 : ans[i]) << " ";
    }
    cout << nl;
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
