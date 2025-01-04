#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(k), c(k);
        
        for (int i = 0; i < k; i++) {
            cin >> b[i] >> c[i];
        }
        

        map<int, int> mp;
        for (int i = 0; i < k; i++) {
            mp[b[i]] += c[i];
        }
        

        vector<int> arr;
        for (const auto& [key, value] : mp) {
            arr.push_back(value);
        }
        
        sort(arr.begin(), arr.end(), greater<int>());


        int ans = 0;
        for (int i = 0; i < n && i<k && i<arr.size(); i++) {
            ans += arr[i];
        }

        cout << ans << endl;
    }
    return 0;
}
