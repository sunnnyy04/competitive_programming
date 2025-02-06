#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++) cin>>b[i];

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long ans=1;
        for(int i=0;i<n;i++){
           ans*=((lower_bound(b.begin(),b.end(),a[i])-b.begin()-i)%MOD);
           ans%=MOD;
        }
        cout<<ans<<endl;

    }
}