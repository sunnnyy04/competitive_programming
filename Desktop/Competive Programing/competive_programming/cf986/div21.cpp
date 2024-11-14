#include <bits/stdc++.h>
using namespace std;

bool canReachTarget(int n, int a, int b, string& s) {
    const int MAX_ITERATIONS = 1000; 
    const int BOUND = 20;
    
    int x = 0, y = 0;
    int iterations = 0;
    
    while (iterations < MAX_ITERATIONS) {
        for (int i = 0; i < n; i++) {
            if (x == a && y == b) return true;
            
            switch (s[i]) {
                case 'N': y++; break;
                case 'S': y--; break;
                case 'E': x++; break;
                case 'W': x--; break;
            }
            
            if (abs(x) > BOUND || abs(y) > BOUND) return false;
        }
        
        if (x == 0 && y == 0) return false;
        
        iterations++;
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        
        string s;
        cin >> s;
        
        cout << (canReachTarget(n, a, b, s) ? "yes" : "no") << endl;
    }
    
    return 0;
}