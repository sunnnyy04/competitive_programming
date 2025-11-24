#include <bits/stdc++.h>
using namespace std;

using li = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        li s = 0;
        i128 mx = LLONG_MIN;  
        i128 res = LLONG_MIN;

        for (int i = 0; i < n; ++i) {
            i128 idx = (i128)(i + 1);
            i128 left = -(idx * idx) + idx + (i128)s;
            mx = max(mx, left);

            li x;
            cin >> x;
            s += x;
            i128 right = idx * idx + idx - (i128)s + mx;
            res = max(res, right);
        }

        i128 ans = (i128)s + res;
        cout << (long long)ans << "\n";
    }
}
