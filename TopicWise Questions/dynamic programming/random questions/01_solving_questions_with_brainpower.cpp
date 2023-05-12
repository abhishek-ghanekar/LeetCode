// top to bottom memoization
class Solution {
private:
    long long int f(int idx,vector<vector<int>> &questions, vector<long long int> &dp) {
        if(idx >= questions.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        //if we pickup the question
        long long int take = questions[idx][0] + f(idx + questions[idx][1] + 1 , questions,dp);
        long long int notTake = f(idx+1,questions,dp);
        return dp[idx] = max(take,notTake); 
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // we will use the take , not take approach
        int n = questions.size();
        vector<long long int> dp(n,-1);
        return f(0,questions,dp);
    }
};

// tabulation approach : top to buttom 
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        //tabulation solution
        int n = questions.size();
        vector<long long int> dp(n+1,0);
        

        for(int i=n-1;i>=0;i--) {
            long long take;
            if(i + questions[i][1] + 1 >= n) {
               take = questions[i][0] + dp[n];
            }else {
                take = questions[i][0] + dp[i+questions[i][1] + 1];
            }
            long long notTake = dp[i+1];
            dp[i] = max(take,notTake); 
        } 
        return dp[0];  
     }
};