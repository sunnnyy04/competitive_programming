#include <iostream>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 1;

        while (n > 0) {
            int d = n % 10;
            n /= 10;
            int mul = 0;

            for (int i = 0; i <= d; i++) {
                for (int j = 0; j <= d; j++) {
                    if (d - i - j >= 0) {
                        mul++;
                    }
                }
            }
            cnt *= mul;
        }
        cout << cnt << endl;
    }
    return 0;
}
