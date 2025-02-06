#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
   ll t;
   cin >> t;
   while (t--)
   {
      ll n, k;
      cin >> n >> k;
      vector<ll> v(n);

      for (ll i = 0; i < n; i++)
         cin >> v[i];

      if (n == k)
      {
         ll ans = -1;
         for (ll i = 1; i < n; i += 2)
         {
            if (v[i] != (i / 2) + 1)
            {
               ans = (i / 2) + 1;
               break;
            }
         }
         cout << (ans == -1 ? (n / 2) + 1 : ans) << endl;
      }
      else
      {
         ll res = -1;
         for (ll i = 1; i <= (n - k + 1); i++)
         {  
            if (v[i] != 1)
            {
               res = i;
               break;
            }
         }
         if (res == -1)
         {
            ll temp = 2;
            for (ll i = n - k; i < n; i += 2)
            {
               if (v[i] != temp)
                  break;
               temp++;
            }
            cout << temp << endl;
         }
         else
         {
            cout << 1 << endl;
         }
      }
   }
   return 0;
}
