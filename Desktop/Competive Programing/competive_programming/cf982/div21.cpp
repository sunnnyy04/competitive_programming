#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        vector<int> w(n); 
        for (int i = 0; i < n; i++) {
            cin >> w[i] >> h[i];
        }
        int max_height = *max_element(h.begin(), h.end()); 
        int max_width = *max_element(w.begin(), w.end());

        int ans = max_height * 2;
        int ans2 = max_width * 2;

        cout << ans+ans2 << endl;
    }
}
