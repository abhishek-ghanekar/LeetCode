#include <bits/stdc++.h>
//using memoization

int f(int index,int buy,int sellsLeft,vector<int> &prices,vector<vector<vector<int>>> &memo) {
    // base case
    int n = prices.size();
    if(sellsLeft == 0) {
        return 0;
    }
    if(index == n) {
        return 0;
    }
    if(memo[index][buy][sellsLeft] != -1) return memo[index][buy][sellsLeft];
    if(buy == 1) {
        // that means we can buy
        int buyToday = -prices[index] + f(index+1,0,sellsLeft,prices,memo);
        int buyLater = 0 + f(index+1,1,sellsLeft,prices,memo);
        return memo[index][buy][sellsLeft] = max(buyToday,buyLater);
    }else {
        int sellToday = prices[index] + f(index+1,1,sellsLeft-1,prices,memo);
        int sellLater = 0 + f(index+1,0,sellsLeft,prices,memo);
        return memo[index][buy][sellsLeft] = max(sellToday,sellLater);
    }
} 
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> memo(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,1,2,prices,memo);
}

//using tabulation
int maxProfit(vector<int> &prices, int n) {
  // vector<vector<vector<int>>>
  // memo(n,vector<vector<int>>(2,vector<int>(3,-1))); return
  // f(0,1,2,prices,memo);
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
  // write the base case
  for (int index = n - 1; index >= 0; index--) {
      //traverse all the index
      for(int buy=0 ; buy < 2;buy++) {
          for(int sellsLeft = 1 ; sellsLeft < 3;sellsLeft++) {
             if(buy == 1) {
        // that means we can buy
                int buyToday = -prices[index] + dp[index+1][0][sellsLeft];
                int buyLater = 0 + dp[index+1][1][sellsLeft];
                 dp[index][buy][sellsLeft] = max(buyToday,buyLater);
            }else {
                int sellToday = prices[index] + dp[index+1][1][sellsLeft-1];
                int sellLater = 0 + dp[index+1][0][sellsLeft];
                 dp[index][buy][sellsLeft] = max(sellToday,sellLater);
            } 
          }
      }
  }
  return dp[0][1][2];
}
//using space optimization
int maxProfit(vector<int> &prices, int n) {
  // vector<vector<vector<int>>>
  // memo(n,vector<vector<int>>(2,vector<int>(3,-1))); return
  // f(0,1,2,prices,memo);
  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
  // write the base case
  for (int index = n - 1; index >= 0; index--) {
      //traverse all the index
      for(int buy=0 ; buy < 2;buy++) {
          for(int sellsLeft = 1 ; sellsLeft < 3;sellsLeft++) {
             if(buy == 1) {
        // that means we can buy
                int buyToday = -prices[index] + dp[index+1][0][sellsLeft];
                int buyLater = 0 + dp[index+1][1][sellsLeft];
                 dp[index][buy][sellsLeft] = max(buyToday,buyLater);
            }else {
                int sellToday = prices[index] + dp[index+1][1][sellsLeft-1];
                int sellLater = 0 + dp[index+1][0][sellsLeft];
                 dp[index][buy][sellsLeft] = max(sellToday,sellLater);
            } 
          }
      }
  }
  return dp[0][1][2];
}
