#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<ll> pq;

int main(){
    int n, k1, k2, k;
    cin>>n>>k1>>k2;
    k = k1+k2;
    vector<ll> a(n), b(n), arr(n);
    for(int i=0 ; i<n ; ++i)
        cin>>a[i];
    for(int i=0 ; i<n ; ++i){
        cin>>b[i];
        arr[i] = abs(a[i]-b[i]);
        pq.push(arr[i]);
    }
    while(k>0){
        ll curr = pq.top();
        pq.pop();
        pq.push(abs(curr-1));
        k--;
    }
    ll ans = 0;
    while(!pq.empty()){
        ll curr = pq.top();
        ans += (curr*curr);
        pq.pop();
    }
    cout<<ans;
}