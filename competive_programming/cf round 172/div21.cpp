#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,int k,string a,string b,string c,vector<vector<int> >&dp){
    if(k==c.size()){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int as=0;
    if(i<a.size()){
        if(a[i]==c[k]){
            as=f(i+1,j,k+1,a,b,c,dp);
        }
        else{
            as=1+f(i+1,j,k+1,a,b,c,dp);
        }
    }
    int bs=0;
    if(j<b.size()){
        if(b[j]==c[k]){
            bs=f(i,j+1,k+1,a,b,c,dp);
        }
        else{
            bs=1+f(i,j+1,k+1,a,b,c,dp);
        }
    }
    return dp[i][j]=min(as,bs);

}
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;
        vector<vector<int> >dp(a.size(),vector<int>(b.size(),-1));
        int ans=f(0,0,0,a,b,c,dp);
        cout<<ans<<endl;

    }
        
}
