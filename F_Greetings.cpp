#include <bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
#else
#define dbg(...) ; 
#define debug(...) ; 
#endif


void solve() {
    
    int n;
    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    cout << ans << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
    #endif
    
    int t = 1;
    cin >> t;
    
    for(int tc = 1; tc <= t; tc++) {
        solve ();
    }
    
    return 0;
}