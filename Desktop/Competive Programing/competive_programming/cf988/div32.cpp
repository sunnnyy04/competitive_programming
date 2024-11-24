#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        map<int,int>mp;
        for(int i=0;i<k;i++){
            int x;
            cin>>x;
            mp[x]++;
        }
        int x=k-2;
        int m,n;
        for(int i=1;i<=x;i++){

            if(x%i==0){
                if(mp.find(i)!=mp.end() && mp.find(x/i)!=mp.end()){
                    if(i==x/i){
                        if(mp[i]>=2){
                            m=i;
                            n=i;
                            break;
                        }
                    }
                    else{
                        m=i;
                        n=x/i;
                        break;
                    }
                    
                }
            }
        }
        cout<<n<<" "<<m<<endl;

    }
}