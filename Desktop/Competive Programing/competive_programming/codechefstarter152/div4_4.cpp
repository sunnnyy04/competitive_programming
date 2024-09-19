#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<string> arr(m);
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        
        int ans = 0;
        
        
        for (int i = 0; i < m; i++) {
            int ones=0;
            int zero=0;
            int ques=0;
            for (int j = 0; j < n; j++) {
                if(arr[j][i]='0') zero++;
                else if(arr[j][i]='1') ones++;
                else ques++;
            }
            while(ques>0){
                if(ones>zero){
                    zero++;
                    ques--;
                }
                else{
                    ones++;
                    ques--;
                }
            }
            ans+=ones*zero;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
