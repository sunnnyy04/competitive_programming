#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_best3(const vector<int>& arr) {
    int mx1 = -1, mx2 = -1, mx3 = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (mx1 == -1 || arr[i] > arr[mx1]) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        } else if (mx2 == -1 || arr[i] > arr[mx2]) {
            mx3 = mx2;
            mx2 = i;
        } else if (mx3 == -1 || arr[i] > arr[mx3]) {
            mx3 = i;
        }
    }
    vector<int> v1;
    v1.push_back(mx1);
    v1.push_back(mx2);
    v1.push_back(mx3);
    return v1; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> c[i];
        
        vector<int> bestA = get_best3(a);
        vector<int> bestB = get_best3(b);
        vector<int> bestC = get_best3(c);
        
        int ans = 0;
        for (size_t i = 0; i < bestA.size(); ++i) {
            for (size_t j = 0; j < bestB.size(); ++j) {
                for (size_t k = 0; k < bestC.size(); ++k) {
                    int x = bestA[i], y = bestB[j], z = bestC[k];
                    if (x != y && x != z && y != z) {
                        ans = max(ans, a[x] + b[y] + c[z]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
