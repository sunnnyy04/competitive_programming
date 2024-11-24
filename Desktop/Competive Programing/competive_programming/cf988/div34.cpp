#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long  n,m,l;
        cin>>n>>m>>l;
        vector<pair<int,int> >hur(n);
        vector<pair<int,int> >pow(m);
        for(int i=0;i<n;i++){
            cin>>hur[i].first;
            cin>>hur[i].second;
        }
        for(int i=0;i<m;i++){
            cin>>pow[i].first;
            cin>>pow[i].second;
        }
        sort(hur.begin(), hur.end(), [&](pair<long long, long long> A, pair<long long, long long> b) {
            if (A.first == b.first) {
            return max(A.first, A.second) > max(b.first, b.second);
        }
        return A.first < b.first; 
        });

        sort(pow.begin(), pow.end(), [&](pair<long long, long long> A, pair<long long, long long> b) {
            if (A.first == b.first) 
                return max(A.first, A.second) > max(b.first, b.second);
                return A.first < b.first; 
            });

            long long ans;
            long long count;
            int j=0;
            vector<int>jump;
            bool f=true;
            for(auto &i:hur){
                int hurd=abs(i.second-i.first);
                if(hurd<=ans){

                }
                else{
                    
                        while(pow[j].first<i.first&& j<m){
                            jump.push_back(pow[j].second);
                            j++;
                    
                    sort(jump.begin(),jump.end());
                    while(hurd>ans){
                        ans+=jump[jump.size()-1];
                        jump.pop_back();
                        count++;
                    }
                    if(hurd>ans){
                        f=false;
                    }
                }
            }
            if(f) cout<<count<<endl;
            else cout<<-1<<endl;


    }
}
}