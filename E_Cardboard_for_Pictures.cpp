#include <bits/stdc++.h>
 
using namespace std;
 
#define ll     long long
#define _test   int _TEST; cin>>_TEST; while(_TEST--)
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    _test
    {
        ll int n, c;
        cin>>n>>c;
 
        vector<ll int> s(n);
        for(auto &e: s)     cin>>e;
 
        __int128 low=0, high=1e9;
 
        while(low <= high)
        {
            __int128 mid = (low + high)/2;
 
            __int128 val = 0;
 
            for(auto e: s)
                val += (e+mid*2ll)*1ll*(e+mid*2ll);
 
            if(val == c)
            {
                cout<<(ll)mid<<"\n";
                break;
            }
            else if(val < c)
                low = mid+1;
            else
                high = mid-1;
        }
 
    }
}