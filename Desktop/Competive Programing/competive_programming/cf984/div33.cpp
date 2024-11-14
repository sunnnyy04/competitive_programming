#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s; 
        int n;
        cin >> n;  
        

        for (int i = 0; i < n; i++) {
            int index, value;
            cin >> index >> value;
            index--; 

            if (index >= 0 && index < s.size()) {
                s[index] = value + '0';
            }


            if (s.find("1100") != string::npos) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
