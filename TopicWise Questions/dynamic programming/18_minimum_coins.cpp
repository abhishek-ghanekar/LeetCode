// using memoization
#include <bits/stdc++.h>
int f(int index, int T, vector<int> &num,vector<vector<int>> &dp) {
  if (index == 0) {
    // we need to process the 0th index
    if (T % num[0] == 0)
      return T / num[0];
    return 1e9;
  }
  // now theres two options
  if (dp[index][T] != -1)
    return dp[index][T];
  int notPick = f(index - 1, T, num, dp);
  int pick = 1e9;
  if (T >= num[index])
    pick = 1 + f(index, T - num[index], num,dp);
    return dp[index][T] = min(pick, notPick);
}
int minimumElements(vector<int> &num, int x)
{
    
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans = f(n-1,x,num,dp);
    if(ans >= 1e9) return -1;
    return ans;
}

// using tabulation 
#include <bits/stdc++.h>

int minimumElements(vector<int> &num, int x)
{
    
    int n = num.size();
    // we try the tabulation
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    for (int i = 0; i <= x ; i++) {
        if (i % num[0] == 0) {
            dp[0][i] = i / num[0];
        }else {
            dp[0][i] = 1e9;
        }
    }
    //dp vector is setup
    // now we need to do the processing
    for(int i=1;i<n;i++) {
        for(int j=0;j<=x;j++) {
            int notTake = dp[i-1][j];
            int take = 1e9;
            if(num[i] <= j) take = 1 + dp[i][j-num[i]];
            dp[i][j] = min(notTake,take);
        }
    }
    if(dp[n-1][x] >= 1e9) return -1;
    return dp[n-1][x];
}


//using space optimization 
