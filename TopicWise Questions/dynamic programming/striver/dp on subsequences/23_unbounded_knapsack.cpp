//using memoization
#include <bits/stdc++.h> 
int f(int index,int w,vector<int> &profit,vector<int> &weight,vector<vector<int>> &memo) {
    if(index == 0) {
        if(weight[index] > w) return 0;
        return w/weight[index] * profit[index];
    }
    if(memo[index][w] != -1) return memo[index][w];
    int pick = 0;
    if(w >= weight[index]) pick = profit[index] + f(index,w-weight[index],profit,weight,memo);
    int notPick = f(index-1,w,profit,weight,memo);
    return memo[index][w] = max(pick,notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> memo(n,vector<int>(w+1,-1));
    int ans = f(n-1,w,profit,weight,memo);
    if(ans < 0) return 0;
    return ans;
}


// using tabulation
#include <bits/stdc++.h> 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    // do the base cases
    for(int i=0;i<=w;i++) {
        if(i < weight[0]) {
            dp[0][i] = 0;
        }else {
            dp[0][i] = i /weight[0] * profit[0];
        }
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<=w;j++) {
            int pick = 0;
            if(j >= weight[i]) pick = profit[i] + dp[i][j-weight[i]];
            int notPick = dp[i-1][j];
             dp[i][j] = max(pick,notPick);
        }
    }
    return dp[n-1][w];
}
// using space optimization
#include <bits/stdc++.h> 
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1,0);
    vector<int> curr(w+1,0);
    // do the base cases
    for(int i=0;i<=w;i++) {
        if(i < weight[0]) {
            prev[i] = 0;
        }else {
            prev[i] = i /weight[0] * profit[0];
        }
    }
    

    for(int i=1;i<n;i++) {
        for(int j=0;j<=w;j++) {
            int pick = 0;
            if(j >= weight[i]) pick = profit[i] + curr[j-weight[i]];
            int notPick = prev[j];
             curr[j] = max(pick,notPick);
        }
        prev = curr;
    }
    return prev[w];
}
