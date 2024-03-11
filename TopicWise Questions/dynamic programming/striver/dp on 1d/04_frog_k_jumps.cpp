// recursion approach

#include <bits/stdc++.h> 
int solve(int idx,vector<int> &heights) {
    if(idx == 0) return 0;
    int mmSteps = INT_MAX;
    for(int i=1;i<=k;i++) {
        if(index-i >= 0 ) {
           int jump = solve(idx - i,heights,dp) + abs(heights[idx] - heights[idx-i]);
        }
        mmSteps = min(mmSteps,jump);
    }
    return mmSteps;
}
int frogJump(int n, vector<int> &heights)
{
    //using memoization
    //converting this into dp
    
    return solve(n-1,heights,dp);
}
// memoization approach
int solve(int idx,vector<int> &heights,vector<int> &dp) {
    if(idx == 0) return 0;
    int mmSteps = INT_MAX;
    if(dp[idx] != -1) return dp[idx];
    for(int i=1;i<=k;i++) {
        if(index-i >= 0 ) {
           int jump = solve(idx - i,heights,dp) + abs(heights[idx] - heights[idx-i]);
        }
        mmSteps = min(mmSteps,jump);
    }
    return dp[index] = mmSteps;
}
int frogJump(int n, vector<int> &heights)
{
    //using memoization
    //converting this into dp
    vector<int> dp(n+2,-1);
    return solve(n-1,heights,dp);
}

// tabulation approach
int frogJump(int n,vector<int> &heights) {
    
}