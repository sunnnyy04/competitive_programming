#include<bits/stdc++.h>
using namespace std;
void applyRangeUpdates(vector<int>& arr, vector<pair<int, int> >& ranges) {
    int n = arr.size();
    vector<int> diff(n + 1, 0);  // Create difference array of size n+1

    // Process each range and apply the difference array logic
    for (auto range : ranges) {
        int l = range.first;
        int r = range.second;

        // Apply range increment using difference array
        diff[l] += 1;        // Increment start of range
        if (r + 1 < n) {
            diff[r + 1] -= 1;  // Decrement just after the end of range
        }
    }

    // Apply the prefix sum to get the final array
    arr[0] += diff[0];
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];  // Prefix sum to accumulate the increments
        arr[i] += diff[i];
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d,k;
        cin>>n>>d>>k;
        vector<pair<int,int> >a(k);
        vector<int>day(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            cin>>a[i].second;
            
        }
        applyRangeUpdates(day,a);
        int left=0,right=d;
        int m=0;
        for(int i =left;i<=right;i++){
            m+=day[i];
        }
        int temp=m;
        int mom;
        int bro;
        int ma=m;
        while(right<n){
            temp-=day[left];
            left++;
            right++;
            temp+=day[right];
            if(m>temp){
                mom=left;
            }
            m=min(m,temp);

            if(ma<temp){
                bro=left;
            }
            ma=max(ma,temp); 
        }
        cout<<bro<<" "<<mom<<endl;    
    }
}