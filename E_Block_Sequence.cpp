#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int>dp(n+1);
    dp[n-1]=1;
    dp[n]=0;
    for(int i=n-2;i>=0;i--){
        int take=INT_MAX;
        if(i+a[i]<n){
            take=min(take,dp[i+1+a[i]]);
        }
       dp[i]=min(take,1+dp[i+1]);
    }
    cout << dp[0] << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
