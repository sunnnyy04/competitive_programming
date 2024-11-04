#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n, k;
        cin >> n >> k;  // Size of array and number of queries
        vector<int> p(n);
        string s;

        // Input for array p
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        // Input for string s
        cin >> s;

        // Processing each query
        for (int i = 0; i < k; i++) {
            int q;
            cin >> q;  // Query index (0-based)
            
            // Toggle the character at index q
            s[q] = (s[q] == 'L') ? 'R' : 'L';

            bool found = false;
            for (int j = 1; j < n; j++) {
                if (s[j] == 'R' && s[j - 1] == 'L') {
                    // Split the array into two parts
                    vector<int> arr(p.begin(), p.begin() + j);
                    vector<int> brr(p.begin() + j, p.end());

                    int ma = *max_element(arr.begin(), arr.end());
                    int mi = *min_element(brr.begin(), brr.end());

                    // Check if the condition is satisfied
                    if (mi > ma) {
                        cout << "NO" << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}


















// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int  t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         string s;
//         cin>>s;
//         if(s[0]=='1'||  s[n-1]=='1'){
//             cout<<"YES"<<endl;
//             continue;
//         }

//         int con=0;
//         bool ans=false;
//         for(int i=0;i<n;i++){
//             if(s[i]=='1'){
//                 con++;
//                 if(con==2){
//                     cout<<"YES"<<endl;
//                     ans=true;
//                     break;
//                 }
//             }
//             else{
//                 con=0;
//             }
//         }
//         if(ans==false){
//             cout<<"NO"<<endl;
//             continue;
//         }

        

//     }
// }










// // string ans;
// //         ans+=s[0];
// //         int zero=1;
// //         int one=0;
// //         int z=0;
// //         for(int i=1;i<n;i++){
// //             if(s[z]!=ans[i]){
// //                 ans+=s[i];
// //                 z++;
// //                 if(ans[z]=='1'){
// //                     one++;
// //                 }
// //                 else{
// //                     zero++;
// //                 }
// //             }
// //         }
// //         if(ans[ans.size()-1]=='1'){
// //             cout<<"YES"<<endl;
// //         }
// //         else{
// //             cout<<"NO"<<endl;
// //         }