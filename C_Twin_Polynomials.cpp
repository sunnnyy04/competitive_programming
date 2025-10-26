#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
const int N=1000010;
const int LOGN=28;
const ll  TMD=1000000007;
const ll  INF=2147483647;
int T,n;
int a[N];
ll dp[N];
 
/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug
 * stress test
 */
 
 //-------------------------------------------------
//涉及变量:f[]
//注意:自行初始化
 
int  f[N],sz[N];
 
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
 
void uni(int x,int y)
{
	int fx=find(x),fy=find(y);
	f[fx]=fy;
	if(fx!=fy) sz[fy]+=sz[fx]; //!!!
}
//-------------------------------------------------
 
void init_dp()
{
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<N;i++)
        dp[i]=(2*dp[i-1]+(i-1)*dp[i-2])%TMD;
}
 
void init()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        f[i]=i,sz[i]=1;
    for(int i=0;i<=n;i++)
        cin>>a[i];
}
 
void solve()
{
    for(int i = 0; i <= n; i++) {
        if(a[i]>n) {
            cout << 0 << endl;
            return;
        }
    }
    vector<int> ind(n+4);
    int m=n;
    for(int i=0;i<=n;i++)
        if(a[i]!=-1) uni(i,a[i]),ind[a[i]]++;
 
    for(int i=0;i<=n;i++)
    {
        if(i>0&&ind[i]>1)
        {
            cout<<"0\n";
            return ;
        }
        if(a[i]>0&&sz[find(i)]>2)
        {
            cout<<"0\n";
            return ;
        }
        if(find(i)!=0&&sz[find(i)]==2) m--;
        else if(a[i]!=-1) m--;
    }
    //
    //printf("m=%d\n",m);
    //
    if(sz[find(n)]==1) cout<<(dp[m]-dp[m-1]+TMD)%TMD<<'\n';
    else cout<<dp[m]<<'\n';
}
 
//-------------------------------------------------------
 
void gen_data()
{
    srand(time(NULL));
}
 
int bruteforce()
{
    return 0;
}
 
//-------------------------------------------------------
 
int main()
{
    fastio;
    //
    //printf("%d\n",(1<<17));
    //
 
    init_dp();
    cin>>T;
	while(T--)
	{
		init();
		solve();
 
		/*
 
		//Stress Test
 
		gen_data();
		auto ans1=solve(),ans2=bruteforce();
		if(ans1==ans2) printf("OK!\n");
		else
		{
			//Output Data
 		}
 
		*/
	}
 
	return 0;
}