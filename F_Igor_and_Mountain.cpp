#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i, a, b) for (int i = a; i < b; i++)

const ll MOD = 998244353;

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    string a[n];

    loop(i, 0, n) {
        cin >> a[i];
    }

    vector<vector<pair<ll, ll>>> t(n + 1, vector<pair<ll, ll>>(m + 1, {0, 0}));

    for (int i = 0; i < m; i++) {
        if (a[0][i] == 'X') {
            t[1][i + 1].first = 1; 
        }
    }

    for (int i = 1; i <= n; i++) {
        ll start = 1;
        ll end = min(1 + static_cast<ll>(sqrt(1LL * d * d - 1)), m);
        ll buffer = 0;

        for (int j = start; j <= m && j <= end; j++) {
            buffer = (buffer + t[i - 1][j].first + t[i - 1][j].second) % MOD;
            if (a[i - 1][j - 1] == 'X') {
                t[i][j].first = (t[i][j].first + buffer) % MOD;
            }
        }
        while (end < m) {
            buffer = (buffer - t[i - 1][start].first - t[i - 1][start].second + MOD) % MOD;
            start++;
            end++;
            buffer = (buffer + t[i - 1][end].first + t[i - 1][end].second) % MOD;
            if (a[i - 1][end - 1] == 'X') {
                t[i][end].first = (t[i][end].first + buffer) % MOD;
            }
        }

        start = max(1LL, m - static_cast<ll>(sqrt(1LL * d * d - 1)));
        end = m;
        buffer = 0;

        for (int j = end; j >= start; j--) {
            if (a[i - 1][j - 1] == 'X') {
                t[i][j].first = (t[i][j].first + buffer) % MOD;
            }
            buffer = (buffer + t[i - 1][j].first + t[i - 1][j].second) % MOD;
        }

        while (start > 1) {
            buffer = (buffer - t[i - 1][end].first - t[i - 1][end].second + MOD) % MOD;
            end--;
            start--;
            if (a[i - 1][start - 1] == 'X') {
                t[i][start].first = (t[i][start].first + buffer) % MOD;
            }
            buffer = (buffer + t[i - 1][start].first + t[i - 1][start].second) % MOD;
        }

        start = 1;
        end = min(1 + d, m);
        buffer = 0;

        for (int j = start; j <= m && j <= end; j++) {
            if (a[i - 1][j - 1] == 'X') {
                t[i][j].second = (t[i][j].second + buffer) % MOD;
            }
            buffer = (buffer + t[i][j].first) % MOD;
        }

        while (end < m) {
            buffer = (buffer - t[i][start].first + MOD) % MOD;
            start++;
            end++;
            if (a[i - 1][end - 1] == 'X') {
                t[i][end].second = (t[i][end].second + buffer) % MOD;
            }
            buffer = (buffer + t[i][end].first) % MOD;
        }

        start = max(1LL, m - d);
        end = m;
        buffer = 0;

        for (int j = end; j >= start; j--) {
            if (a[i - 1][j - 1] == 'X') {
                t[i][j].second = (t[i][j].second + buffer) % MOD;
            }
            buffer = (buffer + t[i][j].first) % MOD;
        }

        while (start > 1) {
            buffer = (buffer - t[i][end].first + MOD) % MOD;
            end--;
            start--;
            if (a[i - 1][start - 1] == 'X') {
                t[i][start].second = (t[i][start].second + buffer) % MOD;
            }
            buffer = (buffer + t[i][start].first) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = ((ans%MOD) + (t[n][i].first%MOD)) % MOD;
        ans= ((ans)%MOD +(( t[n][i].second%MOD)%MOD))%MOD;
    }

    cout << (ans%MOD )<< endl;
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