#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m,c;
        cin>>m>>c;
        int b1,b2;
        cin>>b1>>b2;
        int q;
        cin>>q;
        if((b1>q && b2<q) || (b1<q && b2>q)){
            if((abs(b1-b2)-1)%2==0){
                cout<<(abs(b1-b2)-1)/2<<endl;

            }   
            else{
                cout<<((abs(b1-b2)-1)/2)+1<<endl;
            }
                    // int ans1=min(abs(q-b1),abs(q-b2))-1;
            // int ans2=max(abs(q-b1),abs(q-b2))-ans1-1;
            // cout<<ans1+(ans2/2)<<endl;
        }
        else{
            if(q>b1 && q>b2){
                cout<<n-q+abs(q-max(b1,b2))<<endl;
            }
            else{
                cout<<q+abs(q-min(b1,b2))-1<<endl;
            }
        }

    }
}