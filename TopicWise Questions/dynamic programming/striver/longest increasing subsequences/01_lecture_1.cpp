//using memoization
#include <vector>
int f(int idx,int prev,int arr[],int n,vector<vector<int>> &memo) {
    if(idx == n) return 0;
    if(memo[idx][prev+1] != -1) return memo[idx][prev+1];
    int len = 0 + f(idx+1,prev,arr,n,memo);
    if(prev == -1 || arr[idx] > arr[prev]) {
        len = max(len,1+f(idx+1,idx,arr,n,memo));
    }
    return memo[idx][prev+1] = len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> memo(n,vector<int>(n+1,-1));
    return f(0,-1,arr,n,memo);
}
//using tabulation
#include <vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int idx=n-1;idx>=0;idx--) {
        for(int prev = idx-1;prev>=-1;prev--) {
            int len = 0 + dp[idx+1][prev+1];
            if(prev == -1 || arr[idx] > arr[prev]) {
                len = max(len,1+dp[idx+1][idx+1]);
            }
            dp[idx][prev+1] = len;
        }
    }
    return dp[0][-1+1];
}

//using space optimization
#include <vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int idx=n-1;idx>=0;idx--) {
        for(int prev = idx-1;prev>=-1;prev--) {
            int len = 0 + next[prev+1];
            if(prev == -1 || arr[idx] > arr[prev]) {
                len = max(len,1+next[idx+1]);
            }
            curr[prev+1] = len;
        }
        next = curr;
    }
    return curr[-1+1];
}
