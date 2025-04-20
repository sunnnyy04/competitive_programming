#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vl = vector<long long>;
using umii = unordered_map<int, int>;
using maxh = priority_queue<int>;
using minh = priority_queue<int, vi, greater<int>>;
using pii = pair<int, int>;
using ll = long long;

#define all(v) (v).begin(), (v).end()
#define loop(i, start, end) for (int i = (start); i < (end); i++)
#define nl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string r = s;
    reverse(all(r));

    bool p = (s == r), a = true, g = false;

    for (char c : s) {
        if (c != s[0]) {
            a = false;
            break;
        }
    }

    if (a) {
        cout << "NO" << nl;
        return;
    }

    loop(i, 0, n) {
        if (s[i] > r[i]) {
            g = true;
            break;
        } else if (s[i] < r[i]) break;
    }

    if ((p || g) && k == 0) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
