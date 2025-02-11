#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<pair<int,int>, int> cnt;
    long long ans = 0;
    
    for(int e : a) {
        int xx = e % x;
        int yy = e % y;
        ans += cnt[{(x - xx) % x, yy}];
        cnt[{xx, yy}]++;
    }
    
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}