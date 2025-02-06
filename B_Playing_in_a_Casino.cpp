#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int n,m;
       cin>>n>>m;
        
        vector<vector<int> >P(n,vector<int>(m));
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>P[i][j];
            }
        }
        
        long long ans = 0;
        for(int j=0;j<m;++j){
            
            vector<long long>temp;
            for(int i=0;i<n;++i){
                temp.push_back(P[i][j]);
            }
            sort(temp.begin(),temp.end());
            
            
            for(int i=0;i<n;++i){
                //no of vaue greater than this
                long long rem = (n - (i+1));
                rem*=temp[i];
                //no of value smaller than this
                long long add = i;
                add*=temp[i];
                
                
                ans += add;
                ans -= rem;
            }
            temp.clear();
        }
        
        cout<<ans<<"\n";
    }
}