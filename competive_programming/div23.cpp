#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        vector<int>b(m);
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        vector<int>d(q);
        for(int i=0;i<q;i++){
            cin>>d[i];
        }
        for(int i=0;i<q;i++){
            if(b[m-1]<d[i]){
                cout<<(n-b[m-1])<<endl;

            }
            else if(b[0]>d[i]){
                cout<<b[0]-1<<endl;
            }
            else{
                int ans;
                for(int j=0;j<m;j++){
                    if(d[i]>b[j]){
                        ans=j;
                        break;
                    }
                }
                if((abs(d[ans]-d[ans-1])-1)%2==0){
                cout<<(abs(d[ans]-d[ans-1])-1)/2<<endl;

            }   
            else{
                cout<<((abs(d[ans]-d[ans-1])-1)/2)+1<<endl;
            }

            }
        }

        

    }
}