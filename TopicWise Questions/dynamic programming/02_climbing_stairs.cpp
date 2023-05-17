// using normal recursion 
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 0) return 1;
        // int left = climbStairs(n-1);
        // int right = climbStairs(n-2);
        return climbStairs(n-1)+climbStairs(n-2);
    }
};
// using memoization 
class Solution {
private:
    int solve(int n,vector<int> &dp) {
        //if we reach 0 then return 1
        //if we reach 1 then return 1
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
public:
    int climbStairs(int n) {
        // if(n == 1) return 1;
        // if(n == 0) return 1;
        // // int left = climbStairs(n-1);
        // // int right = climbStairs(n-2);
        // return climbStairs(n-1)+climbStairs(n-2);
        // solving using memoization
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
// using tabulation 
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2,-1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n+1;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n+1];
    }
};
//using space optimization
class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 0;
        int prev2 = 1;
        int curr;
        for(int i=2;i<=n+1;i++) {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
}