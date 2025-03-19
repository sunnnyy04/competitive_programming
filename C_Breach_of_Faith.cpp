#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastAF                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define pb push_back
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define mod (int)1e9 + 7
#define pi 3.1415926536
#define rev greater<int>()
#define deci(x) setprecision(x)
#define revll greater<ll int>()
#define all(v) v.begin(), v.end()
#define No cout << "NO" << endl;
#define Yes cout << "YES" << endl;
#define rev2 greater<pair<int, int>>()
#define minus_one cout << "-1" << endl;
#define rev2ll greater<pair<ll int, ll int>>()
#define ff first
#define ss second
#define get_unique(v)                                 \
    {                                                 \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define endl "\n"
using namespace std;
template <typename T>
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
vll divisors;
vll factors_prime;
vector<ll> fact(1e6 + 1);
vector<ll> ifact(1e6 + 1);
vector<pll> powers;
vector<pll> hash_values;
const pll primes = {1000992299, 1000000009};
bool check_square(ll int *);
void Divisors(ll int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divisors.pb(i);
            if (n / i != i && i > 1)
            {
                divisors.pb(n / i);
            }
        }
    }
}
void Sieve(ll int n, bool sieve[])
{
    memset(sieve, true, n + 1);
    sieve[0] = false;
    sieve[1] = false;
    for (ll int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (ll int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}
bool CheckPrime(ll int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (ll int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void PrimeFactors(ll int n)
{
    while (n % 2 == 0)
    {
        factors_prime.pb(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            factors_prime.pb(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        factors_prime.pb(n);
    }
}
ll bin_expo(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_inverse(ll a, ll b)
{
    return bin_expo(a, b - 2, b);
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mod_inverse(b, m), m) + m) % m;
}
void nCrcompute()
{
    fact[0] = 1;
    for (int i = 1; i <= 1e6; ++i)
    {
        fact[i] = mod_mul(fact[i - 1], i, mod);
    }
    ifact[1000000] = bin_expo(fact[1000000], mod - 2, mod);
    for (int i = 1e6 - 1; i >= 0; --i)
    {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, mod);
    }
}
ll nCrValue(ll n, ll r)
{
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], mod), mod);
}
ll int setBit(ll int x, int i)
{
    return (x | (1 << i));
}
ll int unsetBit(ll int x, int i)
{
    return (x & ~(1 << i));
}
char upperToLower(char x)
{
    return x | ' ';
}
char lowerToUpper(char x)
{
    return x & ('_');
}
void rollinHash(string &s)
{
    int n = s.length();
    hash_values.clear();
    powers.clear();
    vector<pll> hashes(n, {s[0] - 96, s[0] - 96});
    vector<pll> power(n, {1, 1});
    for (int i = 1; i < n; i++)
    {
        hashes[i].first = (hashes[i - 1].first * 31 + (s[i] - 96)) % primes.first;
        hashes[i].second = (hashes[i - 1].second * 53 + (s[i] - 96)) % primes.second;
        power[i].first = (power[i - 1].first * 31) % primes.first;
        power[i].second = (power[i - 1].second * 53) % primes.second;
    }
    hash_values = hashes;
    powers = power;
}
pll substringHash(ll int l, ll int r)
{
    ll hash1, hash2;
    hash1 = hash_values[r].first;
    if (l > 0)
        hash1 = ((hash1 - (hash_values[l - 1].first * powers[r - l + 1].first) % primes.first) + primes.first) % primes.first;
    hash2 = hash_values[r].second;
    if (l > 0)
        hash2 = ((hash2 - (hash_values[l - 1].second * powers[r - l + 1].second) % primes.second) + primes.second) % primes.second;
    return {hash1, hash2};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        n *= 2;
        vll v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(all(v));
        ll x = v[n - 1];
        ll ans = 0;
        int i = 0, j = n - 2;
        cout << v[n - 1] << " ";
        while (i < j)
        {
            ans += (v[i] - v[j]);
            cout << v[i] << " " << v[j] << " ";
            i++;
            j--;
        }

        ans -= v[i];

        cout << x - ans << " " << v[i] << endl;
    }
}
bool check_square(ll int n)
{
    ll int x = sqrt(n);
    x *= x;
    if (x == n)
    {
        return true;
    }
    return false;
}