#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int ans=0;
        if(a[n-1]>=k){
            cout<<0<<endl;
            continue;
        }
        bool found=true;
        int x;
        for(int i=n-1;i>=0;i--){
            if(ans+a[i]==k){
                cout<<0<<endl;
                found =false;
                break;
            }
            else if(ans+a[i]>k){
                found =false;
                cout<<k-ans<<endl;
                break;
            }
            else{
                ans+=a[i];
            }
        }
        if(found){
            cout<<k-ans<<endl;
        }
        
    }
}