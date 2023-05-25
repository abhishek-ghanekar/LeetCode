
#include <bits/stdc++.h>
int f(int index,int buy,int fee,vector<int> &prices,vector<vector<int>> &memo) {
    int n = prices.size();
    if(index == n) return 0;
    if(memo[index][buy] != -1) return memo[index][buy];
    if(buy) {
        int buyToday = -prices[index] + f(index+1,0,fee,prices,memo);
        int buyLater = 0 + f(index+1,1,fee,prices,memo);
        return memo[index][buy] = max(buyToday,buyLater);
    }else {
        int sellToday = prices[index] - fee + f(index+1,1,fee,prices,memo);
        int sellLater = 0 + f(index+1,0,fee,prices,memo);
        return memo[index][buy] = max(sellToday,sellLater);
    }
} 
int maximumProfit(int n, int fee, vector<int> &prices) {
    //using memoization
    vector<vector<int>> memo(n,vector<int>(2,-1));
    return f(0,1,fee,prices,memo);
}
