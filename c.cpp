#include <bits/stdc++.h>
using namespace std;

int lcs_length(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string sequence;
    sequence.reserve(n);

    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        sequence.push_back(temp[0]);
    }

    vector<int> fixed_pos;
    int x;
    while (cin >> x) fixed_pos.push_back(x);

    int cntA = 0, cntB = 0, cntC = 0;
    for (char ch : sequence) {
        if (ch == 'A') ++cntA;
        else if (ch == 'B') ++cntB;
        else ++cntC;
    }

    string order = "ABC";
    int best = INT_MAX;

    do {
        string formed;
        for (char ch : order) {
            if (ch == 'A') formed.append(cntA, 'A');
            else if (ch == 'B') formed.append(cntB, 'B');
            else formed.append(cntC, 'C');
        }

        bool consistent = true;
        for (int pos : fixed_pos) {
            if (pos < 1 || pos > n || sequence[pos - 1] != formed[pos - 1]) {
                consistent = false;
                break;
            }
        }
        if (!consistent) continue;

        int common = lcs_length(sequence, formed);
        best = min(best, n - common);

    } while (next_permutation(order.begin(), order.end()));

    if (best == INT_MAX)
        cout << "Impossible";
    else
        cout << best;

    return 0;
}
