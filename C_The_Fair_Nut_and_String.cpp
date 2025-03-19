#include <iostream>
#include <string>

using namespace std;

int countSubsequences(const string& s) {
    long long result = 1;
    const long long MOD = 1e9 + 7;
    string filtered = "";
    for (char c : s) {
        if (c == 'a' || c == 'b') {
            filtered += c;
        }
    }
    int i = 0;
    while (i < filtered.length()) {
        if (filtered[i] == 'a') {
            int count = 0;
            while (i < filtered.length() && filtered[i] == 'a') {
                count++;
                i++;
            }
            result = (result * (count + 1)) % MOD;
        } else {
            i++;
        }
    }

    return (result - 1 + MOD) % MOD; 
}

int main() {
    string input;
    cin >> input;

    int answer = countSubsequences(input);
    cout << answer << endl;

    return 0;
}
