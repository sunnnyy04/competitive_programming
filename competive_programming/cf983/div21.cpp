#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>s(2*n);
        int o=0;
        for(int i=0;i<2*n;i++){
            cin>>s[i];
            if(s[i]==1){
                o++;
            }
        }
        int z=(2*n)-o;
        int mi=o%2==0?0:1;
        int ma=min(o,z);
        cout<<mi<<" "<<ma<<endl;
        
    }
}


