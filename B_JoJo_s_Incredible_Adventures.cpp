#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s; s += s;
        int k = 0, z = 0;
        for (char c : s) {
            z = c == '1' ? z+1 : 0;
            k = max(k, z);
        }
        const int n = s.size() / 2;

        if (k > n) {
            cout << (ll)n*n << '\n';
        } else {
            cout <<(ll(k+1)/2)*(ll(k+2)/2)<< '\n';
        }
    }
}