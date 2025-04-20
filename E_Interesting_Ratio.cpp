#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define all(a) a.begin(), a.end()

vector<int> primes;

// ---------------------- Sieve of Eratosthenes ---------------------- //
void sieve(int maxN) {
    vector<bool> is_prime(maxN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= maxN; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

// ---------------------- Solve Function ---------------------- //
void solve() {
    int n;
    cin >> n;
    primes.clear();
    sieve(n);
    ll ans=0;
    for (int i = 0; i < primes.size(); i++) {
        ans+=(n/primes[i]);
    }

    cout << ans << nl;
}

// ---------------------- Main Function ---------------------- //
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

      // Precompute primes once

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
