#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool ans=true;
        for(int i=1;i<n;i++){
            if(abs(a[i]-a[i-1])==5 ||abs(a[i]-a[i-1])==7){

            }
            else{
                ans=false;
                break;
            }

        }
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

        
    }
}