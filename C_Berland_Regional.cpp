#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
#define loop(i, a, b) for (int i = a; i < b; i++)
#define all(a) a.begin(), a.end()

void solve() {
    ll n;
    cin >> n;
    vl u(n), s(n);


    loop(i, 0, n) cin >> u[i]; 
    loop(i, 0, n) cin >> s[i];

    
    unordered_map<ll, vl> mpp;
    loop(i, 0, n) mpp[u[i]].push_back(s[i]);

    vector<ll> total(n + 1, 0); 
    for (auto &[uni, scores] : mpp) {
        sort(all(scores), greater<ll>());  
        loop(i, 1, scores.size()) scores[i] += scores[i - 1];
        int size = scores.size();
        loop(k, 1, size + 1) {
            total[k] += scores[size - (size % k) - 1];
        }
    }
    loop(k, 1, n + 1) cout << total[k] << " ";
    cout << endl;
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
