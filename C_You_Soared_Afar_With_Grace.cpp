#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int same_count = 0, idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            same_count++;
            idx = i;
        }
    }

    if (same_count >= 2 || (n % 2 == 0 && same_count >= 1)) {
        cout << -1 << '\n';
        return;
    }

    vector<pii> operations;

    if (same_count == 1) {
        swap(a[idx], a[n/2]);
        swap(b[idx], b[n/2]);
        if(idx+1!=n/2+1) operations.push_back({idx + 1, n/2 + 1});
    }

    map<int, int> pos_a, pos_b;
    for (int i = 0; i < n; i++) {
        pos_a[a[i]] = i;
        pos_b[b[i]] = i;
    }
    for (int i = 0; i < n/2; i++) {
        if (pos_b[a[i]] == pos_a[b[i]]) {
            int u = pos_b[a[i]], v = pos_a[b[i]];
            swap(a[u], a[n - i - 1]);
            swap(b[v], b[n - i - 1]);
            if(u + 1!= n - i){
            operations.push_back({u + 1, n - i});
            swap(pos_a[a[u]], pos_a[a[n - i - 1]]);
            swap(pos_b[b[v]], pos_b[b[n - i - 1]]);}
        } else {
            cout << -1 << '\n';
            return;
        }
    }
    cout << operations.size() << '\n';
    for (auto &[u, v] : operations) {
        cout << u << " " << v << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
