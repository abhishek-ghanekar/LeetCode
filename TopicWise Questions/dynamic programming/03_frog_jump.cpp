#include <bits/stdc++.h> 
int solve(int idx,vector<int> &heights,vector<int> &dp) {
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int singleJump = solve(idx-1,heights,dp) + abs(heights[idx] - heights[idx-1]);
    int doubleJump = INT_MAX;
    if(idx > 1) doubleJump = solve(idx-2,heights,dp) + abs(heights[idx] - heights[idx-2]);
    return dp[idx] = min(singleJump,doubleJump);
}
int frogJump(int n, vector<int> &heights)
{
    //using memoization
    //converting this into dp
    vector<int> dp(n+2,-1);
    return solve(n-1,heights,dp);
    

}
// from bottom up approach
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0] = 0;
    for(int i=1;i<n;i++) {
        int singleJump = dp[i-1] + abs(heights[i] - heights[i-1]);
        int rightJump = INT_MAX;
        if(i > 1) rightJump = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(singleJump,rightJump);
    }
    return dp[n-1];
}

// optimizing space
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int prev = ;
    int prev1 = ;
    int curr = ;
    for(int i=1;i<;i++) {
        
    }
}