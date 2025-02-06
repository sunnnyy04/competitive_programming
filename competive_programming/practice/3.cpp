#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>v(26,-1);
    for(int i=0;i<n;i++){
      if(v[s[i]-'a']==-1){
        v[s[i]-'a']=i;
      }
    }
    for(int i=0;i<26;i++){
      if(v[i]!=-1){
        ans+=(n-i);
      }
    }
    cout<<ans<<endl;
  }
}
