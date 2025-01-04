#include <bits/stdc++.h>
using namespace std;

// Memoization map
map<tuple<int, int, int, int>, int> dp;

void f(int i, int &ans, string &s, int g, int b, int a, int k) {
    // Memoization check
    auto state = make_tuple(i, g, b, a);
    if (dp.count(state)) return;

    // Base case
    if (i == s.size()) {
        if (b - a == k) {
            ans = ans == -1 ? g + 1 : min(g + 1, ans);
        }
        dp[state] = ans; // Memoize the result for this state
        return;
    }

    // Recursive calls
    if (s[i] == '0') {
        f(i + 1, ans, s, g, b, a + g, k);
        if (i != 0) f(i + 1, ans, s, g + 1, b, a + g + 1, k);
    } else {
        f(i + 1, ans, s, g, b + g, a, k);
        if (i != 0) f(i + 1, ans, s, g + 1, b + g + 1, a, k);
    }

    // Memoize the result for this state
    dp[state] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int ans = -1;
        dp.clear(); // Clear the memoization map for each test case
        f(0, ans, s, 0, 0, 0, k);
        cout << ans << endl;
    }
    return 0;
}
