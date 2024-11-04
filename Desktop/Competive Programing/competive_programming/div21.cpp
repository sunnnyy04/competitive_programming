#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if (n == 1) {
        cout << "0\n";
        return;
    }
    
    int mv = arr[0];
    int mi = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > mv) {
            mv = arr[i];
            mi = i;
        }
    }
    
    if (mi == 0) {
        cout << "0\n";
        return;
    }
    
    int dN = 0;
    int i = 0;
    
    while (i < n - 1) {
        int equalCount = 0;
        while (i < n - 1 && arr[i] == arr[i + 1]) {
            equalCount++;
            i++;
        }
        
        if (i < n - 1 && arr[i] < arr[i + 1]) {
            dN += equalCount + 1;
            i++;
        } else {
            break;
        }
    }
    
    int currentMax = (i < n) ? arr[i] : arr[i - 1];
    for (int j = i + 1; j < n; j++) {
        if (arr[j] > currentMax) {
            dN++;
        }
    }
    
    cout << min(dN, mi) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}