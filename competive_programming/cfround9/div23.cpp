#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x, m;
        cin >> x >> m;

        long long ans = 0;
        
        for(long long i=1;i<=min(m,x);i++){
            long long z=i^x;
            if(z%x==0 || z%i==0){
                ans++;
            }
        }
        m-=x;
        if(m>x){
            ans+=(ans*(m/x));
            long long b=x+m/x;
            for(int i=b+1;i<m;i++){
                long long z=i^x;
                if(z%x==0 || z%i==0){
                    ans++;
                }
            }
        }
       cout<<ans<<endl;
    }
    return 0;
}