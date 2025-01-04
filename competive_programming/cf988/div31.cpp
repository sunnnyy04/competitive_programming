#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int>mp;
        vector<int>a(n);
        for(auto &i:a){
            cin>>i;
        }
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        int ans=0;
        int ma=0;
        for(auto i:mp){
            if(i.second>1){
                ans+=i.second/2;
            }
        }
        cout<<ans<<endl;


    }
}