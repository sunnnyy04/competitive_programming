#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s="";
        if(n<=5){
            if(n==0){
                cout<<""<<endl;
            }
            if(n==1){
                cout<<"a"<<endl;
            }
            if(n==2){
                cout<<"ae"<<endl;
            }
            if(n==3){
                cout<<"aei"<<endl;
            }
            if(n==4){
                cout<<"aeio"<<endl;
            }
            if(n==5){
                cout<<"aeiou"<<endl;
            }

        }
        else{
            if(n%5==0){
                for(int i=0;i<n/5;i++){
                    s+="aeiou";
                }
            }
            else{
                for(int i=0;i<n/5;i++){
                    s+="aeiou";
                }
                int n=n%5;
                if(n==1){
                s+="a";
            }
            if(n==2){
                s+="ae";
            }
            if(n==3){
                s+="aei";
            }
            if(n==4){
                s+="aeio";
            }
            if(n==5){
                s+="aeiou";
            }

            }
            cout<<s<<endl;
        }
    }
}