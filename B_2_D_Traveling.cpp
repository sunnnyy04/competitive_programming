#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<pair<int,int> >c(n);
        for(int i=0;i<n;i++){
            cin>>c[i].first;
            cin>>c[i].second;
        }
        if(a<=k && b<=k){
            cout<<0<<endl;
            continue;
        }
        else if(a<=k && b>k){
            int ans=LLONG_MAX;
            for(int i=0;i<k;i++){
                int x=abs(c[i].first-c[b-1].first);
                int y=abs(c[i].second-c[b-1].second);
                ans=min(ans,x+y);
            }
            cout<<ans<<endl;
        }
        else if(a>k && b<=k){
            int ans=LLONG_MAX;
            for(int i=0;i<k;i++){
                int x=abs(c[i].first-c[a-1].first);
                int y=abs(c[i].second-c[a-1].second);
                ans=min(ans,x+y);
            }
            cout<<ans<<endl;
        }
        else{
            int ans = abs(c[a-1].first - c[b-1].first) + abs(c[a-1].second - c[b-1].second);
            int inp=LLONG_MAX;
            int o=LLONG_MAX;
            for(int i=0;i<k;i++){
                inp=min(inp,abs(c[i].first- c[a-1].first) +abs(c[i].second-c[a-1].second));
                o=min(o,abs(c[i].first-c[b-1].first)+ abs(c[i].second-c[b-1].second));
                ans=min(ans,(inp+o));
            }
            
            cout<<ans<<endl;

        }
    }
}