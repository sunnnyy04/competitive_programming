
#include<bits/stdc++.h>
#define ll long long
const int n1=1e9+7;
using namespace std;
void solve()
{
    ll n;
    cin>>n;
    ll ans=((((n*(n+1))%n1)*(4*n-1))%n1*337)%n1;
    cout<<ans<<endl;

}
int main()
{
   
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
 
 
}