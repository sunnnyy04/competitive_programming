#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Size of the matrix
        vector<vector<int> > arr(n, vector<int>(n));

        // Input the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        int ans = 0; 
        for (int i = 0; i < n; i++) {
            int a = i, b = 0, neg = 0; 
            while (a < n && b < n) {
                if (arr[a][b] < 0) {
                    neg = max(neg, abs(arr[a][b]));  // Track maximum negative value
                }
                a++, b++;
            }
            ans += neg;  
        }

        for (int j = 1; j < n; j++) {
            int a = 0, b = j, neg = 0;  
            while (a < n && b < n) {
                if (arr[a][b] < 0) {
                    neg = max(neg, abs(arr[a][b]));  
                }
                a++, b++;
            }
            ans += neg;
        }

        cout << ans << endl; 
    }
}
