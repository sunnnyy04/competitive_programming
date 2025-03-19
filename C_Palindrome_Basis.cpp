#include <bits/stdc++.h>
using namespace std;

const int N = 40004;
const long long MOD = 1000000007;
long long dp[N];

bool isPalindrome(int n) {
    int rev = 0, temp = n;
    while (temp) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }
    return rev == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> palin;
    for (int i = 1; i < N; i++) {
        if (isPalindrome(i)) {
            palin.push_back(i);
        }
    }
    dp[0] = 1;
    for (int p : palin) {
        for (int i = p; i < N; i++) {
            dp[i] = (dp[i] + dp[i - p]) % MOD;
        }
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
