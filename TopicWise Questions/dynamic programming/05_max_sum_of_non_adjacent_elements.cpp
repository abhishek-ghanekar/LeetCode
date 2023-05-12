//memoization solution
#include <bits/stdc++.h> 
int solve(int index,vector<int> &nums,vector<int> &dp) {
    if(index == 0) return nums[0];
    if(index < 0) return 0;
    if(dp[index] != -1) return dp[index];
    int maxIfPicked = nums[index] + solve(index-2,nums,dp);
    int maxIfNotPicked = 0 + solve(index-1,nums,dp);
    return dp[index] =  max(maxIfPicked,maxIfNotPicked);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+2,-1);
    return solve(n-1,nums,dp);
}


// tabulation approach

int n = nums.size();
    vector<int> dp(n+2,-1);
    dp[0] = nums[0];
    int neg = 0;
    for(int i=1;i<n;i++) {
        int pick;
        if(i == 1) {
             pick = nums[i];
        }else {
             pick = nums[i] + dp[i-2];
        }
        
        
        int notPick = dp[i-1];
        dp[i] = max(pick,notPick);
    }
    return dp[n-1];

// space optimization solution

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev1 = nums[0];
    int prev2 = 0;
    for(int i=1;i<n;i++) {
        int pick = nums[i] + prev2;
        int notPick = prev1;
        int curr = max(pick,notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}