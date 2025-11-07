#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int win = n, los = 0;
    int rounds = 0;

    while(win > 1 || los > 1){
        int new_los = win / 2;
        int win_remaining = win - new_los;
        rounds+=(new_los);
        rounds+=(los/2);
        int los_remaining = (los + 1) / 2;
        win = win_remaining;
        los = los_remaining + new_los;
    }

    rounds++;
    cout << rounds << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}
