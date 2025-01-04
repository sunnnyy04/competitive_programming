#include <bits/stdc++.h>
using namespace std;
int countNonOverlappingZeroSumSubarrays(const vector<int>& arr) {
    unordered_map<int, int> sumMap; 
    int cumulativeSum = 0;
    int count = 0; 
    int lastIndex = -1; 

    for (int i = 0; i < arr.size(); i++) {
        cumulativeSum += arr[i];
        
        if(arr[i]==0){
            count ++;
            lastIndex=i;
            cumulativeSum=0;
        }
        else if (cumulativeSum == 0) {
            count++; 
            lastIndex = i;
        }
        else if (sumMap.find(cumulativeSum) != sumMap.end()) {

            if (sumMap[cumulativeSum] > lastIndex) {
                count++; 
                lastIndex = i; 
                cumulativeSum=0;
            }
        }

        sumMap[cumulativeSum] = i;
    }

    return count; 
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count = countNonOverlappingZeroSumSubarrays(arr);
        cout<<count<<endl;

        
    }
}
