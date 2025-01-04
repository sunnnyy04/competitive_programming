#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long ans=0;
        long long mid=0;
        for(int i=0;i<n;i++){
            ans+=a[i];
            if(ans>=n){
                mid+=(ans/n);
                ans=ans%n;
            }
        }
        if(ans%n!=0){
            cout<<"no"<<endl;
        }
        else{

            bool found=false;
            int i=0;
            int j=n-1;
            if(n%2!=0){
                while(j>i+1){
                    if(j-2==i){
                        if((a[i]-a[i+1])==(a[i+1]-a[j]) && a[i+1]==mid){
                            found=true;
                            break;
                        }
                    }
                    else{
                        if(a[j]>mid){
                            a[j-2]-=(a[j]-mid);
                            a[j]=mid;
                            if(a[j-2]<0){
                                break;
                            }
                        }
                        else if(a[j]<mid){
                            a[j-2]+=(mid-a[j]);
                            a[j]=mid;
                        }
                        if(a[i]>mid){
                            a[i+2]-=(a[i-mid]);
                            a[i]=mid;
                            if(a[i+2]<0){
                                break;
                            }
                        }
                        else if(a[j]<mid){
                            a[i+2]+=(mid-a[i]);
                            a[i]=mid;

                        }
                    }
                    i++;
                    j--;
                }
            }
            else{
                while(j>i+1){
                    if(j-1==i){
                        if(a[j]==mid && a[i]==mid){
                            found=true;
                            break;
                        }
                    }
                    else{
                        if(a[j]>mid){
                            a[j-2]-=(a[j]-mid);
                            a[j]=mid;
                            if(a[j-2]<0){
                                break;
                            }
                        }
                        else if(a[j]<mid){
                            a[j-2]+=(mid-a[j]);
                            a[j]=mid;
                        }
                        if(a[i]>mid){
                            a[i+2]-=(a[i-mid]);
                            a[i]=mid;
                            if(a[i+2]<0){
                                break;
                            }
                        }
                        else if(a[j]<mid){
                            a[i+2]+=(mid-a[i]);
                            a[i]=mid;

                        }
                    }
                    i++;
                    j--;
                }


            }
            if(found){
                cout<<"yes"<<endl;
            }
            
        }
        
        
    }
}