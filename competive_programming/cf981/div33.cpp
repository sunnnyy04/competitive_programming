#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n;
        cin >> n;  // Size of the array
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];  // Input the array elements
        }

        int s = 0, e = n - 1;
        while (s < e) {
            // If the elements at the start and end are not equal
            if (a[s] != a[e]) {
                // Compare adjacent elements to decide whether to swap
                int ds = (s + 1 < n && a[s] == a[s + 1]) ? 1 : 0; // Check next element from start
                int de = (e - 1 >= 0 && a[e] == a[e - 1]) ? 1 : 0; // Check previous element from end
                int das = (s + 1 < n && a[s + 1] == a[e]) ? 1 : 0; // Check if next start equals end
                int dae = (e - 1 >= 0 && a[e - 1] == a[s]) ? 1 : 0; // Check if previous end equals start

                // Swap if the conditions are met
                if (ds >das || de > dae) {
                    swap(a[s], a[e]);
                }
            }
            s++;
            e--;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                ans++;
            }
        }
        cout << ans << endl;  // Output the count of duplicates
    }

    return 0;  // End of the program
}
