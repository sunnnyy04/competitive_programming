#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r, k;
        cin >> l >> r >> k;
        
        if (k == 1) {  
            cout << r - l + 1 << endl;
            continue;
        }

        long long ans = 0;
        long long start = l;
        long long end = r;
        
        while (start <= end) {
            long long mid = (start + end) / 2;
            if (mid * k <= r) {  
                ans = mid;  
                start = mid + 1; 
            } else {
                end = mid - 1;  
            }
        }
        if(ans==0){
            cout<<0<<endl;
            continue;
        }
        
        cout << ans-l+1<< endl;
    }
}
