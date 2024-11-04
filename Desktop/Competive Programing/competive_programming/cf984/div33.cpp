#include <bits/stdc++.h>
using namespace std;

bool contains1100(const string& s) {
    return s.find("1100") != string::npos;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s; 
        int n;
        cin >> n;  
        vector<pair<int, char>> updates(n);

        for (int i = 0; i < n; i++) {
            int index;
            char value;
            cin >> index >> value;
            updates[i] = {index - 1, value}; // Store 0-based index and char
        }

        for (const auto& [index, value] : updates) {
            s[index] = value; // Apply the update
        }

        if (contains1100(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
