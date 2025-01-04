#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>s(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int ans=0;
        int result=0;
        for(int i=0;i<n;i++){
            ans+=(s[i].size());
            result++;
            if(ans>=m){
                break;
            }
        }
        if(ans<=m){
            cout<<result<<endl;
        }
        else{
            cout<<result-1<<endl;
        }
        
    }
}