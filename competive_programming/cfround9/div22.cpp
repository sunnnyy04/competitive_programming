#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.size()==1){
            cout<<-1<<endl;
            continue;
            
        }
        else if(s.size()<=2){
            if(s[0]==s[1]){
                cout<<s<<endl;
                continue;
            }
            else{
                cout<<-1<<endl;
                continue;
            }
        }
        char prev1=s[0];
        char prev2=s[1]; 
        string ans="";
        bool found =false;
        if(prev2==prev1){
            ans+=prev1;
            ans+=prev2;
            found =true;
            cout<<ans<<endl;
            continue;
        }
        for(int i=2;i<s.size();i++){
            if(prev2==s[i]){
                ans+=prev2;
                ans+=s[i];
                cout<<ans<<endl;
                found =true;
                break;
            }
            else if(prev1!=s[i]){
                ans+=prev1;
                ans+=prev2;
                ans+=s[i];
                cout<<ans<<endl;
                found=true;
                break;
            }
           
            prev1=prev2;
            prev2=s[i];
        }
        if(!found){
            cout<<-1<<endl;
        }
        
    }
}