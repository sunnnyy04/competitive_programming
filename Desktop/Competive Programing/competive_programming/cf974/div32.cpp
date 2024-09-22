#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long x = n - k + 1;
        if (x < 1) x = 1; 
        long long fo = (x % 2 == 0) ? x + 1 : x; 
        long long lo = (n % 2 == 0) ? n - 1 : n;  

        long long oC = 0;
        if (fo <= lo) {
            oC = (lo - fo) / 2 + 1;
        }

        if (oC % 2 != 0) {
            cout << "NO" << endl; 
        } else {
            cout << "YES" << endl; 
        }
    }
    return 0;
}
