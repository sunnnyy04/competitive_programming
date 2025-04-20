#include <bits/stdc++.h>
using namespace std;

//---------------------- Macros & Aliases ----------------------//
#define ll long long
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define int long long

// =============== !!! ~ ~ ~ Code Starts Here ~ ~ ~ !!! ===============
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    loop(i, 0, n) cin >> a[i];

    int mi = 0, ma = 0, tmi = 0, tma = 0;
    int pos = -1;

    // Finding the first non-{1, -1} element and computing initial min/max
    for (int i = 0; i < n; i++) {
        if (a[i] != 1 && a[i] != -1) {
            pos = i;
            break;
        }
        tmi += a[i];
        tma += a[i];
        ma = max(ma, tma);
        mi = min(mi, tmi);

        // Reset if needed
        if (tmi > 0) tmi = 0;
        if (tma < 0) tma = 0;
    }

    set<int> ans;
    for (int i = mi; i <= ma; i++) ans.insert(i);

    // If no special element found, stop here
    if (pos == -1) {
        cout << ans.size() << "\n";
        for (auto i : ans) cout << i << " ";
        cout << "\n";
        return;
    }

    // Compute prefix min/max for left part
    ll x = 0, pmi = a[pos], pma = a[pos];
    for (int i = pos; i >= 0; i--) {
        x += a[i];
        ans.insert(x);
        pmi = min(pmi, x);
        pma = max(pma, x);
    }

    // Reset min/max tracking for the right part
    mi = ma = tmi = tma = 0;
    for (int i = pos + 1; i < n; i++) {
        tmi += a[i];
        tma += a[i];
        ma = max(ma, tma);
        mi = min(mi, tmi);

        if (tmi > 0) tmi = 0;
        if (tma < 0) tma = 0;
    }

    for (int i = mi; i <= ma; i++) ans.insert(i);

    // Compute prefix min/max for the right part
    tmi=pmi;
    tma=pma;
    for (int i = pos + 1; i < n; i++) {
        tmi+=a[i];
        tma+=a[i];
        pmi = min(pmi,tmi);
        pma = max(pma, tma);
    }

    for (int i = pmi; i <= pma; i++) ans.insert(i);

    // Output results
    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
