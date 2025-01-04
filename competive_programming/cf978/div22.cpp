#include <bits/stdc++.h>
using namespace std ;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"0"<<endl;
            continue;
        }
        string s = "1";
        for(int i=0;i<n-1;i++){
            s+='0';
        }
        cout<<s<<endl;
    }

}
