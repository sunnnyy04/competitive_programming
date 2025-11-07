#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    vector<int> vec;
    int number,b,ret=0;
    cin>>number;
    while(number--)
    {
        cin>>b;
        vec.push_back(b);
    }
    sort(vec.begin(),vec.end());
    auto iter=unique(vec.begin(),vec.end());
    vector<int> vec2(vec.begin(),iter);
    cout<<vec2.size();
    return 0;
}}