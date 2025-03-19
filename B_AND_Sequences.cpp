
#include<bits/stdc++.h>
using namespace std;

void solveTestCase()
{
    int MOD=1e9+7;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    int min1=*min_element(a.begin(),a.end());
    int cnt=0;
    
    for(int x:a)
    {
        if(min1==x)cnt++;
        if((min1&x)!=min1)
        {
            printf("0\n");
            return;
        }
    }
    
    int fact=1;
    for(int i=1;i<=n-2;i++)fact=(1LL*fact*i)%MOD;
    int ans=(1LL * cnt * (cnt-1))%MOD;
    ans = (1LL * ans * fact) % MOD;
    printf("%d\n",ans);
}

int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    solveTestCase();
    return 0;
}