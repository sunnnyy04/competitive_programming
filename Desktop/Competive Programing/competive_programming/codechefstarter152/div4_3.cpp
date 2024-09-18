#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,p;
	    cin>>m>>p;
	    int ans=0;
	    while((p+m)<1000 && m<=298){
	        p+=20;
	        ans++;
	        m++;
	    }
	    if((p+m)<=1000){
	        cout<<ans<<endl;
	    }
	    else{
	        cout<<ans-1<<endl;
	    }
	}

}
