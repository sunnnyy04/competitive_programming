#include<bits/stdc++.h>
using namespace std;
#define int long long
bool ok(set<int>& S){
    if (S.size() > 2) return false;
    if (S.size() <= 1) return true;

    int x = *S.begin(), y = *(--S.end());

    return abs(x - y) == 1;

}

void solve(){
    int n; cin >> n;

    int xl = n + 1, xr = -1, yl = n + 1, yr = -1;
    set<int> xPy, xMy;
    char a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            if (a[i][j] == '#'){
                xl = min(xl, i);
                xr = max(xr, i);
                yl = min(yl, j);
                yr = max(yr, j);
                xPy.insert(i + j);
                xMy.insert(i - j);
            }
        }
    }

    if (ok(xPy) || ok(xMy)){
        cout << "YES\n";
        return;
    }
    else{
        cout << (xr - xl <= 1 && yr - yl <= 1 ? "YES\n" : "NO\n");
    }


}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t; cin >> t;
    while (t--) solve();
}
 
// Golden Rules
/*
    Solutions are simple.
 
    Proofs are simple.
 
    Implementations are simple.
*/
