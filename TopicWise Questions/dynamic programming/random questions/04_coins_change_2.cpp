//using memoization

class Solution {
private:
    int f(int idx,int amount,vector<int>& coins,vector<vector<int>> &memo) {
        if(idx == 0) {
            // we reach the first
            if(amount%coins[0] == 0) {
                return 1;
            }else {
                return 0;
            }
        }
        if(memo[idx][amount] != -1) return memo[idx][amount];
        int pick = 0;
        if(coins[idx] <= amount) {
               pick =  f(idx,amount-coins[idx],coins,memo);

        }
        int notPick = f(idx-1,amount,coins,memo);
        return memo[idx][amount] = notPick+pick;
    }
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> memo(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,memo)  ;
    }
};