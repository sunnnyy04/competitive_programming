#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string r;
        cin>>r;
        int so=0;
        int sz=0;
        int ro=0;
        int rz=0;
        for(int i=0;i<n;i++){
            if(i<n-1){
                if(r[i]=='0'){
                    rz++;
                }
                else{
                    ro++;
                }
            }
            if(s[i]=='0'){
                    ++sz;
                }
            else{
                so++;
            }
        }
        if(so==1 && sz==1){
            cout<<"yes"<<endl;
            continue;
        }
        if(sz==1 ){
            if(rz==so){
                cout<<"yes"<<endl;
                continue;
            }
            else if(rz+1==so && r[n-2]=='1'){
                cout<<"yes"<<endl;
                continue;
            }
            cout<<"no"<<endl;
            continue;
        }
        if(so==1 ){
            if(ro==sz){
                cout<<"yes"<<endl;
                continue;
            }
            else if(ro+1==sz && r[n-2]=='0'){
                cout<<"yes"<<endl;
                continue;
            }
            cout<<"no"<<endl;
            continue;
        }
        if(sz==0 || so==0){
            cout<<"no"<<endl;
            continue;
        }
        if(sz>so){
            if(sz==ro+1 && so==rz){
                if(r[n-2]=='0'){
                    cout<<"yes"<<endl;
                    continue;
                }
            }

        }
        else if(sz==so){
            if(sz==ro+1 && so==rz){
                if(r[n-2]=='0'){
                    cout<<"yes"<<endl;
                    continue;
                }
            }
            else if(sz==ro && so==rz+1){
                if(r[n-2]=='1'){
                    cout<<"yes"<<endl;
                    continue;
                }
            }
            

        }
        else{
            if(sz==ro && so==rz+1){
                if(r[n-2]=='1'){
                    cout<<"yes"<<endl;
                    continue;
                }
            }

        }
        cout<<"No"<<endl;
    }
}
