#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    if(n%2==0){
      for(int i=1;i<n;i+=2){
        cout<<i<<" "<<i<<" ";
      }
      cout<<endl;
    }
    else{
      cout<<1<<endl;
    }
  }
}
