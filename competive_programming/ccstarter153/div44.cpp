#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        
        vector<int> q = p;
        sort(q.begin(), q.end());

        
        int m = *min_element(p.begin(), p.end());

        if (p == q) {
            cout << 0 << endl;
            continue;
        } else {
            
            int x = -1;

            for (int i = 0; i < n; i++) {
                if (p[i] != q[i]) {
                    x = max(p[i], x);
                }
            }


            cout << x + m << endl;
        }
    }
    return 0;
}
