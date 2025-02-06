#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x, a[100000];
        cin >> n >> x;
        int s = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) cin >> a[j];
            for (int j = 0; j < n; j++) {
                if ((x | a[j]) != x) break;
                s |= a[j];
            }
        }
        if (s == x) cout << "Yes\n";
        else cout << "No\n";
    }
}