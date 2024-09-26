#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r,g,b;
	    cin>>r>>g>>b;
	    if((r+g)<b){
	        cout<<"no"<<endl;
	    }
	    else if((r+b)<g){
	        cout<<"no"<<endl;
	    }
	    else if((g+b)<r){
	        cout<<"no"<<endl;
	    }
	    else{
	        cout<<"yes"<<endl;
	    }
	}

}
