#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k; 
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }


        map<long , long> mpp;
        long long ans=0;
        for (long long i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }
        vector<pair<long long,long long>>pa;
        for(auto &i: mpp){
            pa.push_back({i.second,i.first});
        }
        sort(pa.begin(),pa.end());
        for(auto &i: pa){
            if(i.first>=k){
                k-=i.first;
                ans--;
            }
            else{
                break;
            }
        } 
    }

    return 0;
}
