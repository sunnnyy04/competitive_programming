#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>g(n);
        for(int i=0;i<n;i++){
            cin>>g[i];
        }
        int gold=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(g[i]==0){
                if(gold>0){
                    gold--;
                    ans++;
                } 
            }
            else if(g[i]>=k){
                gold+=g[i];
            }
        }
        cout<<ans<<endl;
    }
}