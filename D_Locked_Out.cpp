#include<bits/stdc++.h>
using namespace std;
#define int long long

// Problem Statement
/*
    good array b
        no (i < j) bj - bi = 1.

    Minimum number of elements to be removed to get a good array...

    or maximum good array subsequence !!!

*/
 
// Small Observatins
/*

    What cann u say about good array ?

        if there is x,
            there cannot be x + 1 after this..

        
        if u have a pair 
            such that x, x + 1

            add an edge to this OK !!..

            And now..

                atleast 1 must be selected from this.. OK !!.

                And this is a bipartite graph...

                    right ?? 
                    WHY look at even and odd things...


                    Minimum Vertex Cover in Bipartite Graph.

                        There is something u can simplify !!

                        
                        u need maximum matching OK !!

                            There is a direction

                            if u look at 1s and 2s..

    
    
    
    if it is already good, ans = n


*/
 
 
 
/*

*/
 
 
// Claims on algo 
/*  
    
 
*/


int ComputeCommon(vector<int>& a, vector<int>& b){
    int i = 0, j = 0;
    while (i != a.size() && j != b.size()){
        if (b[j] < a[i]) j++;
        else{
            i++;
            j++;
        }
    }
    return i;
}


void solve(){
    int n; cin >> n;
    vector<int> Idx[n + 1];
    vector<int> Dp[n + 1];
    for (int i = 1; i <= n; i++) Dp[i].push_back(0);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        Idx[x].push_back(i);
        Dp[x].push_back(0);
    }

    for (int v = n - 1; v >= 1; v--){
        int sz = Idx[v].size();
        int Max = ComputeCommon(Idx[v], Idx[v + 1]);

        // cout << "F = " << Max << '\n';

        Dp[v][0] = Dp[v + 1].back();
        cout<<Dp[v][0]<<" "<<v<<endl;

        for (int i = 1; i <= sz; i++){
            if (i <= Max){
                Dp[v][i] = Dp[v + 1][Dp[v + 1].size() - (i + 1)] + i;
                cout<<Dp[v + 1][Dp[v + 1].size() - (i + 1)]<<" he"<<endl;
            }
            Dp[v][i] = max(Dp[v][i], Dp[v][i - 1]);
            cout<<Dp[v][i]<<" "<<v<<endl;

        }
        // for (int x : Dp[v]) cout << x << ' ';
        // cout << '\n';
    }

    int ans = Dp[1].back();
    
    cout << ans << '\n';

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
