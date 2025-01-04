#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<pair<int, int> > vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({a[i], b[i]});
        }
        sort(vec.begin(), vec.end());

        int am = *max_element(a.begin(), a.end());
        int bm = *max_element(b.begin(), b.end());

        if (am > bm) {
            cout << "yes" << endl;
        } else if (am == bm) {
            if (vec[n - 2].second == am) {
                cout << "no" << endl;
            } else {
                int prev = -1;
                bool found = false;
                for (int i = n - 1; i >= 0; i--) {
                    int x = vec[i].first;
                    int y = vec[i].second;
                    if (prev == y) {
                        cout << "no" << endl;
                        found = true;
                        break;
                    }
                    prev = y;
                }
                if (!found) {
                    cout << "yes" << endl;
                }
            }
        } else {
            bool found = false;
            int prev = -1;
            for (int i = n - 1; i >= 0; i--) { 
                int x = vec[i].first;
                int y = vec[i].second;
                if (prev == y) {
                    cout << "no" << endl;
                    found = true;
                    break;
                }
                prev = y;
            }
            if (!found) {
                cout << "yes" << endl;
            }
        }
    }
    return 0;
}
