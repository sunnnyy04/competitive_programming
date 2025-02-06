#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define loop(i, a, b) for (int i = a; i < b; i++)

// =============== Code Starts Here ~ ~ ~ !!!
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    loop(i, 0, n) {
        cin >> a[i];
    }
    
    map<int, vector<int> > mpp;
    int ans = INT_MAX;
    
    // Collect indices of each element
    for (int i = 0; i < n; i++) {
        mpp[a[i]].push_back(i);
    }

    // Process each element's indices
    for (auto i : mpp) {
        int temp = (i.second[0] > 0) ? (i.second[0]) : 0; 
        int temp2 = 0;  

        for (int j = 1; j < i.second.size(); j++) {
            // cout<<i.second[j]<<endl;
            int gap = i.second[j] - i.second[j - 1] - 1;
            if (temp <= gap) {
                temp2 = temp;
                temp = gap;
            } else if (temp2 < gap) {
                temp2 = gap;
            }
        }


        int last_gap = n - i.second.back() - 1;
        if (temp <= last_gap) {
            temp2 = temp;
            temp = last_gap;
        } else if (temp2 < last_gap) {
            temp2 = last_gap;
        }

     
        temp = max(temp / 2, temp2);
        ans = min(ans, temp);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
