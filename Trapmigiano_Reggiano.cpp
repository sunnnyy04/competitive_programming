#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    
    int solve(int i, vector<int>& nums) {
        int n = nums.size();
        if (i >= n) return 0;  // Base case: No elements left
        if (dp[i] != -1) return dp[i];  // Return memoized value
        
        int cost = INT_MAX;

        // Remove nums[i] and nums[i+1]
        if (i + 1 < n) 
            cost = min(cost, max(nums[i], nums[i+1]) + solve(i + 2, nums));

        // Remove nums[i] and nums[i+2]
        if (i + 2 < n) 
            cost = min(cost, max(nums[i], nums[i+2]) + solve(i + 2, nums));

        // Remove nums[i+1] and nums[i+2]
        if (i + 2 < n) 
            cost = min(cost, max(nums[i+1], nums[i+2]) + solve(i + 3, nums));

        // If last remaining elements, remove all in one go
        if (i + 2 >= n) 
            cost = min(cost, *max_element(nums.begin() + i, nums.end()));

        return dp[i] = cost;
    }
    
    int minCost(vector<int>& nums) {
        dp.assign(nums.size(), -1);  // Initialize DP array
        return solve(0, nums);
    }
};

int main() {
    vector<int> nums = {9, 1, 5};
    Solution sol;
    cout << sol.minCost(nums) << endl;  // Output: 10
    return 0;
}
