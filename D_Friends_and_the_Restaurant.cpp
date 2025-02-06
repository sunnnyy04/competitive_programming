#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll>x(n), y(n);
    vector<pair<ll, int> >dif(n);

    for(auto &i : x) cin >> i;
    for(auto &i: y) cin >> i;
    for(int i = 0; i < n; i++){
        dif[i].first = y[i] - x[i];
        dif[i].second = i;
    }
    sort(dif.begin(), dif.end());

    int i=0;
    int j = n - 1, cnt = 0;
    while(i<j){
        if(dif[i].first+dif[j].first>=0){
            cnt++;
            i++;
            j--;
        }
        else{
            i++;
        }
    }

    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}