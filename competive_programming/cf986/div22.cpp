#include <bits/stdc++.h>
using namespace std;

long long solve(long long n, long long b, long long c) {
 
    if(b==0){
        if(c>=n-2) return c<=n-1?n-1:n;
        else {
            return -1;
        }
    }
    if (b * (n-1) + c == n-1) return 0;
    if (n == 1) return 1;   
    long long x = ((n-1-c) / b) + 1;
    if(n-1<c){
        return n;
    }
    return n-x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, b, c;
        cin >> n >> b >> c;
        
        cout << solve(n, b, c) << endl;
    }
    
    return 0;
}