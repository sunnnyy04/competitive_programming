#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;

#define ll long long
#define pb(n) push_back(n)
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())

const ll INF = 1e15;

ll n;
vl dpr, dpc;
vl a, b;
vvi arr;

ll solve2(int i) {
    if (i >= n) return 0;
    if (dpr[i] != -1) return dpr[i];

    ll in = a[i], nin = 0;

    if (i == 0) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] + 1 == arr[i + 1][j]) in = INF;
        }
        return dpr[i] = min(in + solve2(i + 2), solve2(i + 1));
    }

    if (i == n - 1) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] + 1 == arr[i - 1][j]) in = INF;
        }
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == arr[i - 1][j]) nin = 1e16;
        }
        return dpr[i] = min(in + solve2(i + 2), nin + solve2(i + 1));
    }

    for (int j = 0; j < n; j++) {
        if (arr[i][j] + 1 == arr[i - 1][j] || arr[i][j] + 1 == arr[i + 1][j]) {
            in = INF;
            break;
        }
    }
    for (int j = 0; j < n; j++) {
        if (arr[i][j] == arr[i - 1][j]) nin = 1e16;
    }
    return dpr[i] = min(in + solve2(i + 2), nin + solve2(i + 1));
}

ll solve3(int i) {
    if (i >= n) return 0;
    if (dpc[i] != -1) return dpc[i];

    ll in = b[i], nin = 0;

    if (i == 0) {
        for (int j = 0; j < n; j++) {
            if (arr[j][i] + 1 == arr[j][i + 1]) in = INF;
        }
        return dpc[i] = min(in + solve3(i + 2), solve3(i + 1));
    }

    if (i == n - 1) {
        for (int j = 0; j < n; j++) {
            if (arr[j][i] + 1 == arr[j][i - 1]) in = INF;
        }
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == arr[j][i - 1]) nin = 1e16;
        }
        return dpc[i] = min(in + solve3(i + 2), nin + solve3(i + 1));
    }

    for (int j = 0; j < n; j++) {
        if (arr[j][i] + 1 == arr[j][i - 1] || arr[j][i] + 1 == arr[j][i + 1]) {
            in = INF;
            break;
        }
    }
    for (int j = 0; j < n; j++) {
        if (arr[j][i] == arr[j][i - 1]) nin = 1e15;
    }
    return dpc[i] = min(in + solve3(i + 2), nin + solve3(i + 1));
}

void solve() {
    cin >> n;
    dpr.assign(n + 1, -1);
    dpc.assign(n + 1, -1);
    arr.assign(n, vi(n));
    a.assign(n, 0);
    b.assign(n, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i]; 
    cout<<solve2(0)<<" "<<solve3(0)<<endl;
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
