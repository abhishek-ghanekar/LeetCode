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