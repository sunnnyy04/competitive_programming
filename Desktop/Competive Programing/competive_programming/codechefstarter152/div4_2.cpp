#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    int x=min({arr[n-2]-arr[1],arr[n-3]-arr[0],arr[n-1]-arr[2]});
	    cout<<x<<endl;
	}

}
