#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<long long>x(n);
        vector<long long>y(n);
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            cin>>y[i];
        }
        long long ans=0;
        ans+=(4*m);
        
        for(int i=1;i<n;++i){
            ans+=(2*x[i]);
            ans+=(2*y[i]);
            
        }
        cout<<ans<<endl;
    }
    return 0;
}