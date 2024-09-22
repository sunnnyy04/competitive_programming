#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        long long ans=0;
        vector<int >a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans+=a[i];
        }
        if(n==1|| n==2){
            cout<<-1<<endl;
            continue;
        }
        sort(a.begin(),a.end());
        long long x;
        if(n%2==0){
            x=a[n/2];
        }
        else{
            x=a[n/2];
        }
        if(x*n*2<ans){
            cout<<0<<endl;

        }
        else{
            cout<<(x*n*2)-ans+1<<endl;
        }

    }
}