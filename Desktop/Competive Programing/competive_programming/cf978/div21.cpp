#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }


        int maxVal = *max_element(arr.begin(), arr.end());
        int minVal = *min_element(arr.begin(), arr.end());

        // Calculate the answer
        int ans = (n - 1) * (maxVal - minVal);
        cout << ans << endl;
    }

    return 0;
}




// vector<int>a(n);
    // vector<int>b(n);
    // int mi=INT_MAX;
    // int ma=INT_MIN;
    // int ans=0;
    // for(int i=0;i<n;i++){
    //     a[i]=min(mi,arr[i]);
    //     mi=a[i];
    //     b[i]=max(ma,arr[i]);
    //     ma=b[i];
    //     ans+=b[i];
    //     ans-=a[i];
    // }